// Copyright © 2008-2023 Pioneer Developers. See AUTHORS.txt for details
// Licensed under the terms of the GPL v3. See licenses/GPL-3.txt

#include "SystemEditor.h"

#include "EditorIcons.h"
#include "GalaxyEditAPI.h"
#include "SystemEditorHelpers.h"

#include "EnumStrings.h"
#include "FileSystem.h"

#include "editor/EditorApp.h"
#include "editor/EditorDraw.h"
#include "editor/UndoSystem.h"
#include "editor/UndoStepType.h"

#include "galaxy/Galaxy.h"
#include "galaxy/GalaxyGenerator.h"
#include "galaxy/StarSystemGenerator.h"
#include "lua/Lua.h"
#include "pigui/PiGui.h"

#include "imgui/imgui.h"
#include "system/SystemBodyUndo.h"
#include "system/SystemEditorViewport.h"

#include <memory>

using namespace Editor;

namespace {
	static constexpr const char *OUTLINE_WND_ID = "Outline";
	static constexpr const char *PROPERTIES_WND_ID = "Properties";
	static constexpr const char *VIEWPORT_WND_ID = "Viewport";
}

const char *Editor::GetBodyIcon(const SystemBody *body) {
	if (body->GetType() == SystemBody::TYPE_GRAVPOINT)
		return EICON_GRAVPOINT;
	if (body->GetType() == SystemBody::TYPE_STARPORT_ORBITAL)
		return EICON_SPACE_STATION;
	if (body->GetType() == SystemBody::TYPE_STARPORT_SURFACE)
		return EICON_SURFACE_STATION;
	if (body->GetType() == SystemBody::TYPE_PLANET_ASTEROID)
		return EICON_ASTEROID;
	if (body->GetSuperType() == SystemBody::SUPERTYPE_ROCKY_PLANET)
		return (!body->GetParent() || body->GetParent()->GetSuperType() < SystemBody::SUPERTYPE_ROCKY_PLANET) ?
			EICON_ROCKY_PLANET : EICON_MOON;
	if (body->GetSuperType() == SystemBody::SUPERTYPE_GAS_GIANT)
		return EICON_GAS_GIANT;
	if (body->GetSuperType() == SystemBody::SUPERTYPE_STAR)
		return EICON_SUN;

	return "?";
}

class SystemEditor::UndoSetSelection : public UndoStep {
public:
	UndoSetSelection(SystemEditor *editor, SystemBody *newSelection) :
		m_editor(editor),
		m_selection(newSelection)
	{
		Swap();
	}

	void Swap() override {
		std::swap(m_editor->m_selectedBody, m_selection);
	}

private:
	SystemEditor *m_editor;
	SystemBody *m_selection;
};

SystemEditor::SystemEditor(EditorApp *app) :
	m_app(app),
	m_undo(new UndoSystem()),
	m_selectedBody(nullptr),
	m_pendingReparent()
{
	GalacticEconomy::Init();

	m_galaxy = GalaxyGenerator::Create();
	m_systemLoader.reset(new CustomSystemsDatabase(m_galaxy.Get(), "systems"));

	m_viewport.reset(new SystemEditorViewport(m_app, this));

	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
}

SystemEditor::~SystemEditor()
{
}

bool SystemEditor::LoadSystem(const std::string &filepath)
{
	const CustomSystem *csys = m_systemLoader->LoadSystem(filepath);
	if (!csys)
		return false;

	SystemPath path = {csys->sectorX, csys->sectorY, csys->sectorZ, csys->systemIndex};
	Uint32 _init[5] = { Uint32(csys->seed), Uint32(csys->sectorX), Uint32(csys->sectorY), Uint32(csys->sectorZ), UNIVERSE_SEED };
	Random rng(_init, 5);

	RefCountedPtr<StarSystem::GeneratorAPI> system(new StarSystem::GeneratorAPI(path, m_galaxy, nullptr, rng));
	auto customStage = std::make_unique<StarSystemCustomGenerator>();

	if (!customStage->ApplyToSystem(rng, system, csys)) {
		Log::Error("System is fully random, cannot load from file");
		return false;
	}

	// FIXME: need to run StarSystemPopulateGenerator here to finish filling out system
	// Setting up faction affinity etc. requires running full gamut of generator stages

	// auto populateStage = std::make_unique<PopulateStarSystemGenerator>();
	// GalaxyGenerator::StarSystemConfig config;
	// config.isCustomOnly = true;

	// populateStage->Apply(rng, m_galaxy, system, &config);

	if (!system->GetRootBody()) {
		Log::Error("Custom system doesn't have a root body");
		return false;
	}

	m_system = system;
	m_filepath = filepath;

	m_viewport->SetSystem(system);

	return true;
}

void SystemEditor::WriteSystem(const std::string &filepath)
{
	Log::Info("Writing to path: {}/{}", FileSystem::GetDataDir(), filepath);
	// FIXME: need better file-saving interface for the user
	FILE *f = FileSystem::FileSourceFS(FileSystem::GetDataDir()).OpenWriteStream(filepath, FileSystem::FileSourceFS::WRITE_TEXT);

	if (!f)
		return;

	StarSystem::EditorAPI::ExportToLua(f, m_system.Get(), m_galaxy.Get());

	fclose(f);
}

// Here to avoid needing to drag in the Galaxy header in SystemEditor.h
RefCountedPtr<Galaxy> SystemEditor::GetGalaxy() { return m_galaxy; }

void SystemEditor::SetSelectedBody(SystemBody *body)
{
	// note: using const_cast here to work with Projectables which store a const pointer
	m_selectedBody = body;
}

void SystemEditor::Start()
{
}

void SystemEditor::End()
{
}

// ─── Update Loop ─────────────────────────────────────────────────────────────

void SystemEditor::HandleInput()
{

}

void SystemEditor::Update(float deltaTime)
{
	ImGuiID editorID = ImGui::GetID("System Editor");
	if (ImGui::Shortcut(ImGuiMod_Ctrl | ImGuiMod_Shift | ImGuiKey_Z, editorID, ImGuiInputFlags_RouteGlobal)) {
		GetUndo()->Redo();
	} else if (ImGui::Shortcut(ImGuiMod_Ctrl | ImGuiKey_Z, editorID, ImGuiInputFlags_RouteGlobal)) {
		GetUndo()->Undo();
	}

	DrawInterface();

	if (m_pendingReparent.body) {
		size_t parentIdx = SystemBody::EditorAPI::GetIndexInParent(m_pendingReparent.body);

		GetUndo()->BeginEntry("Reorder Body");
		GetUndo()->AddUndoStep<SystemEditorUndo::ReorderStarSystemBodies>(m_system.Get());
		GetUndo()->AddUndoStep<SystemEditorUndo::AddRemoveChildBody>(m_pendingReparent.body->GetParent(), parentIdx);
		GetUndo()->AddUndoStep<SystemEditorUndo::AddRemoveChildBody>(m_pendingReparent.parent, m_pendingReparent.body, m_pendingReparent.idx);
		GetUndo()->AddUndoStep<SystemEditorUndo::ReorderStarSystemBodies>(m_system.Get(), true);
		GetUndo()->EndEntry();

		m_pendingReparent = {};
	}

	if (ImGui::IsKeyPressed(ImGuiKey_F1)) {
		WriteSystem(m_filepath);
	}
}

// ─── Interface Rendering ─────────────────────────────────────────────────────

void SystemEditor::SetupLayout(ImGuiID dockspaceID)
{
	ImGuiID nodeID = ImGui::DockBuilderAddNode(dockspaceID);

	ImGui::DockBuilderSetNodePos(nodeID, ImGui::GetWindowPos());
	ImGui::DockBuilderSetNodeSize(nodeID, ImGui::GetWindowSize());

	ImGuiID leftSide = ImGui::DockBuilderSplitNode(nodeID, ImGuiDir_Left, 0.2, nullptr, &nodeID);
	ImGuiID rightSide = ImGui::DockBuilderSplitNode(nodeID, ImGuiDir_Right, 0.2 / (1.0 - 0.2), nullptr, &nodeID);
	// ImGuiID bottom = ImGui::DockBuilderSplitNode(nodeID, ImGuiDir_Down, 0.2, nullptr, &nodeID);

	ImGui::DockBuilderDockWindow(OUTLINE_WND_ID, leftSide);
	ImGui::DockBuilderDockWindow(PROPERTIES_WND_ID, rightSide);
	ImGui::DockBuilderDockWindow(VIEWPORT_WND_ID, nodeID);

	ImGui::DockBuilderFinish(dockspaceID);
}

void SystemEditor::DrawInterface()
{
	Draw::ShowUndoDebugWindow(GetUndo());
	ImGui::ShowMetricsWindow();

	static bool isFirstRun = true;

	Draw::BeginHostWindow("HostWindow", nullptr, ImGuiWindowFlags_NoSavedSettings);

	ImGuiID dockspaceID = ImGui::GetID("DockSpace");

	if (isFirstRun)
		SetupLayout(dockspaceID);

	ImGui::DockSpace(dockspaceID);

	if (ImGui::Begin(OUTLINE_WND_ID)) {
		ImGui::PushFont(m_app->GetPiGui()->GetFont("pionillium", 14));
		DrawOutliner();
		ImGui::PopFont();
	}
	ImGui::End();

	if (ImGui::Begin(PROPERTIES_WND_ID)) {
		// Adjust default window label position
		ImGui::PushItemWidth(ImFloor(ImGui::GetWindowSize().x * 0.55f));

		if (m_selectedBody)
			DrawBodyProperties();
		else
			DrawSystemProperties();

		ImGui::PopItemWidth();
	}
	ImGui::End();

	m_viewport->Update(m_app->DeltaTime());

	ImGui::End();

	if (isFirstRun)
		isFirstRun = false;
}

void SystemEditor::DrawOutliner()
{
	ImGui::PushFont(m_app->GetPiGui()->GetFont("pionillium", 16));

	std::string name = m_system.Valid() ? m_system->GetName() : "<None>";

	std::string label = fmt::format("System: {}", m_system->GetName());
	if (ImGui::Selectable(label.c_str(), !m_selectedBody)) {
		m_selectedBody = nullptr;
	}

	ImGui::PopFont();

	if (!m_system) {
		return;
	}

	ImGui::Spacing();

	Draw::BeginHorizontalBar();

	if (ImGui::Button("A##AddBody")) {
		SystemBody *parent = m_selectedBody ? m_selectedBody : m_system->GetRootBody().Get();
		SystemBody *body = StarSystem::EditorAPI::NewBody(m_system.Get());

		GetUndo()->BeginEntry("Add Body");
		GetUndo()->AddUndoStep<SystemEditorUndo::ReorderStarSystemBodies>(m_system.Get());
		GetUndo()->AddUndoStep<SystemEditorUndo::ManageStarSystemBody>(m_system.Get(), body);
		GetUndo()->AddUndoStep<SystemEditorUndo::AddRemoveChildBody>(parent, body);
		GetUndo()->AddUndoStep<SystemEditorUndo::ReorderStarSystemBodies>(m_system.Get(), true);
		GetUndo()->AddUndoStep<SystemEditor::UndoSetSelection>(this, body);
		GetUndo()->EndEntry();
	}

	bool canDeleteBody = m_selectedBody && m_selectedBody != m_system->GetRootBody().Get();
	if (canDeleteBody && ImGui::Button("D##DeleteBody")) {

		std::vector<SystemBody *> toDelete { m_selectedBody };
		size_t sliceBegin = 0;

		while (sliceBegin < toDelete.size()) {
			size_t sliceEnd = toDelete.size();
			for (size_t idx = sliceBegin; idx < sliceEnd; idx++) {
				if (toDelete[idx]->HasChildren())
					for (auto &child : toDelete[idx]->GetChildren())
						toDelete.push_back(child);
			}
			sliceBegin = sliceEnd;
		}

		GetUndo()->BeginEntry("Delete Body");
		GetUndo()->AddUndoStep<SystemEditorUndo::ReorderStarSystemBodies>(m_system.Get());

		for (auto &child : reverse_container(toDelete)) {
			SystemBody *parent = child->GetParent();
			size_t idx = SystemBody::EditorAPI::GetIndexInParent(child);
			GetUndo()->AddUndoStep<SystemEditorUndo::AddRemoveChildBody>(parent, idx);
			GetUndo()->AddUndoStep<SystemEditorUndo::ManageStarSystemBody>(m_system.Get(), nullptr, child, true);
		}

		GetUndo()->AddUndoStep<SystemEditorUndo::ReorderStarSystemBodies>(m_system.Get(), true);
		GetUndo()->AddUndoStep<SystemEditor::UndoSetSelection>(this, nullptr);
		GetUndo()->EndEntry();
	}

	Draw::EndHorizontalBar();


	ImGui::PushFont(m_app->GetPiGui()->GetFont("pionillium", 16));
	if (ImGui::BeginChild("OutlinerList")) {
		std::vector<std::pair<SystemBody *, size_t>> m_systemStack {
			{ m_system->GetRootBody().Get(), 0 }
		};

		if (!DrawBodyNode(m_system->GetRootBody().Get(), true)) {
			ImGui::PopFont();
			ImGui::EndChild();
			return;
		}

		while (!m_systemStack.empty()) {
			auto &pair = m_systemStack.back();

			if (pair.second >= pair.first->GetNumChildren()) {
				m_systemStack.pop_back();
				ImGui::TreePop();
				continue;
			}

			SystemBody *body = pair.first->GetChildren()[pair.second++];
			if (DrawBodyNode(body, false))
				m_systemStack.push_back({ body, 0 });
		}
	}
	ImGui::EndChild();
	ImGui::PopFont();
}

void SystemEditor::HandleOutlinerDragDrop(SystemBody *refBody)
{
	// Handle drag-drop re-order/re-parent
	SystemBody *dropBody = nullptr;
	Draw::DragDropTarget dropTarget = Draw::HierarchyDragDrop("SystemBody", ImGui::GetID(refBody), &refBody, &dropBody, sizeof(SystemBody *));

	if (dropTarget != Draw::DragDropTarget::DROP_NONE && refBody != dropBody) {
		size_t targetIdx = SystemBody::EditorAPI::GetIndexInParent(refBody);

		m_pendingReparent.body = dropBody;
		m_pendingReparent.parent = dropTarget == Draw::DROP_CHILD ? refBody : refBody->GetParent();
		m_pendingReparent.idx = 0;

		if (dropTarget == Draw::DROP_BEFORE)
			m_pendingReparent.idx = targetIdx;
		else if (dropTarget == Draw::DROP_AFTER)
			m_pendingReparent.idx = targetIdx + 1;
	}
}

bool SystemEditor::DrawBodyNode(SystemBody *body, bool isRoot)
{
	ImGuiTreeNodeFlags flags =
		ImGuiTreeNodeFlags_DefaultOpen |
		ImGuiTreeNodeFlags_OpenOnDoubleClick |
		ImGuiTreeNodeFlags_OpenOnArrow |
		ImGuiTreeNodeFlags_SpanFullWidth |
		ImGuiTreeNodeFlags_FramePadding;

	if (body->GetNumChildren() == 0)
		flags |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen;

	if (body == m_selectedBody)
		flags |= ImGuiTreeNodeFlags_Selected;

	ImGuiID bodyId = ImGui::GetID(body);
	std::string name = fmt::format("{} {}###{:x}", GetBodyIcon(body), body->GetName(), bodyId);
	bool open = ImGui::TreeNodeEx(name.c_str(), flags);

	if (body == m_selectedBody)
		ImGui::SetItemDefaultFocus();

	if (!isRoot) {
		HandleOutlinerDragDrop(body);
	}

	if (ImGui::IsItemActivated()) {
		m_selectedBody = body;
	}

	// TODO: custom rendering on body entry, e.g. icon / contents etc.

	return open && body->GetNumChildren();
}

void SystemEditor::DrawBodyProperties()
{
	ImGui::PushFont(m_app->GetPiGui()->GetFont("pionillium", 16));
	ImGui::Text("Body: %s (%d)", m_selectedBody->GetName().c_str(), m_selectedBody->GetPath().bodyIndex);
	ImGui::PopFont();

	ImGui::Spacing();

	ImGui::PushID(m_selectedBody);
	ImGui::PushFont(m_app->GetPiGui()->GetFont("pionillium", 13));

	SystemBody::EditorAPI::EditProperties(m_selectedBody, GetUndo());

	ImGui::PopFont();
	ImGui::PopID();
}

void SystemEditor::DrawSystemProperties()
{
	if (!m_system) {
		ImGui::Text("No loaded system");
		return;
	}

	SystemPath path = m_system->GetPath();

	ImGui::PushFont(m_app->GetPiGui()->GetFont("pionillium", 16));
	ImGui::Text("%s (%d, %d, %d : %d)",
		m_system->GetName().c_str(),
		path.sectorX, path.sectorY, path.sectorZ, path.systemIndex);
	ImGui::PopFont();

	ImGui::Spacing();

	Random rng (Uint32(m_app->GetTime() * 4.0) ^ m_system->GetSeed());
	StarSystem::EditorAPI::EditName(m_system.Get(), rng, GetUndo());

	StarSystem::EditorAPI::EditProperties(m_system.Get(), GetUndo());
}
