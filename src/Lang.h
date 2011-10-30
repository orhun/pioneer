#ifndef _LANG_H
#define _LANG_H

#include <list>
#include <string>
#include <map>

namespace Lang {

#ifndef DECLARE_STRING
#define DECLARE_STRING(x) extern char x[]
#endif

bool LoadStrings(const std::string &lang);
const std::list<std::string> &GetAvailableLanguages();
const std::map<std::string, const char*> &GetDictionary();

DECLARE_STRING(SUGGESTED_RESPONSES);
DECLARE_STRING(CASH);
DECLARE_STRING(LEGAL_STATUS);
DECLARE_STRING(CARGO_SPACE);
DECLARE_STRING(ITEM);
DECLARE_STRING(SHIP);
DECLARE_STRING(PRICE);
DECLARE_STRING(BUY);
DECLARE_STRING(SELL);
DECLARE_STRING(STOCK);
DECLARE_STRING(CARGO);
DECLARE_STRING(VID_LINK_DOWN);
DECLARE_STRING(VID_LINK_ESTABLISHED);
DECLARE_STRING(VID_CONNECTING);
DECLARE_STRING(BOUGHT_1T_OF);
DECLARE_STRING(SOLD_1T_OF);
DECLARE_STRING(WELCOME_TO_MARKET);
DECLARE_STRING(GO_BACK);
DECLARE_STRING(FITTING);
DECLARE_STRING(REMOVING);
DECLARE_STRING(FIT_TO_WHICH_MOUNT);
DECLARE_STRING(REMOVE_FROM_WHICH_MOUNT);
DECLARE_STRING(YOU_NOT_ENOUGH_MONEY);
DECLARE_STRING(TRADER_NOT_ENOUGH_MONEY);
DECLARE_STRING(NO_SPACE_ON_SHIP);
DECLARE_STRING(SOMEWHERE_SERVICES);
DECLARE_STRING(SOMEWHERE_SHIPYARD);
DECLARE_STRING(SOMEWHERE_SHIP_REPAIRS);
DECLARE_STRING(PRICE_TO_FIT);
DECLARE_STRING(PRICE_TO_REMOVE);
DECLARE_STRING(WT);
DECLARE_STRING(FIT);
DECLARE_STRING(REMOVE);
DECLARE_STRING(BUY_THIS_SHIP);
DECLARE_STRING(SHIP_TYPE);
DECLARE_STRING(REGISTRATION_ID);
DECLARE_STRING(WEIGHT_EMPTY);
DECLARE_STRING(NUMBER_TONNES);
DECLARE_STRING(WEIGHT_FULLY_LADEN);
DECLARE_STRING(CAPACITY);
DECLARE_STRING(FORWARD_ACCEL_EMPTY);
DECLARE_STRING(NUMBER_G);
DECLARE_STRING(FORWARD_ACCEL_LADEN);
DECLARE_STRING(REVERSE_ACCEL_EMPTY);
DECLARE_STRING(REVERSE_ACCEL_LADEN);
DECLARE_STRING(HYPERDRIVE_FITTED);
DECLARE_STRING(HYPERSPACE_RANGE_LADEN);
DECLARE_STRING(THANKS_AND_REMEMBER_TO_BUY_FUEL);
DECLARE_STRING(CLASS_NUMBER);
DECLARE_STRING(NUMBER_LY);
DECLARE_STRING(NUMBER_HOURS);
DECLARE_STRING(NUMBER_DAYS);
DECLARE_STRING(SHIP_IS_ALREADY_FULLY_REPAIRED);
DECLARE_STRING(REPAIR_1_PERCENT_HULL);
DECLARE_STRING(REPAIR_ENTIRE_HULL);
DECLARE_STRING(REPAIR);
DECLARE_STRING(PART_EX);
DECLARE_STRING(VIEW);
DECLARE_STRING(SHIP_EQUIPMENT);
DECLARE_STRING(SOMEWHERE_SHIP_EQUIPMENT);
DECLARE_STRING(REPAIRS_AND_SERVICING);
DECLARE_STRING(NEW_AND_RECONDITIONED_SHIPS);
DECLARE_STRING(BULLETIN_BOARD);
DECLARE_STRING(WELCOME_TO_SOMEWHERE);
DECLARE_STRING(SPACESTATION_LONG_WELCOME_MESSAGE);
DECLARE_STRING(REQUEST_LAUNCH);
DECLARE_STRING(SHIPYARD);
DECLARE_STRING(COMMODITIES_MARKET);
DECLARE_STRING(SOMEWHERE_COMMODITIES_MARKET);
DECLARE_STRING(SOMEWHERE_SHIP_MARKET);
DECLARE_STRING(CONTACT_LOCAL_POLICE);
DECLARE_STRING(COMMS_LINK);
DECLARE_STRING(ZOOM_IN);
DECLARE_STRING(ZOOM_OUT);
DECLARE_STRING(NORMA_ARM);
DECLARE_STRING(PERSEUS_ARM);
DECLARE_STRING(OUTER_ARM);
DECLARE_STRING(SAGITTARIUS_ARM);
DECLARE_STRING(SCUTUM_CENTAURUS_ARM);
DECLARE_STRING(INT_LY);
DECLARE_STRING(SEARCH);
DECLARE_STRING(PRESS_BUTTON_WANTED_FOR);
DECLARE_STRING(MOVE_AXIS_WANTED_FOR);
DECLARE_STRING(SAVE);
DECLARE_STRING(LOAD);
DECLARE_STRING(CANCEL);
DECLARE_STRING(SELECT_FILENAME_TO_SAVE);
DECLARE_STRING(GAME_SAVED_TO);
DECLARE_STRING(SELECT_FILENAME_TO_LOAD);
DECLARE_STRING(COULD_NOT_OPEN_FILENAME);
DECLARE_STRING(GAME_LOAD_CORRUPT);
DECLARE_STRING(GAME_LOAD_CANNOT_OPEN);
DECLARE_STRING(VERY_LOW);
DECLARE_STRING(LOW);
DECLARE_STRING(MEDIUM);
DECLARE_STRING(HIGH);
DECLARE_STRING(VERY_HIGH);
DECLARE_STRING(VERY_VERY_HIGH);
DECLARE_STRING(ON);
DECLARE_STRING(OFF);
DECLARE_STRING(SIGHTS_SOUNDS_SAVES);
DECLARE_STRING(PIONEER);
DECLARE_STRING(SAVE_THE_GAME);
DECLARE_STRING(LOAD_A_GAME);
DECLARE_STRING(EXIT_THIS_GAME);
DECLARE_STRING(WINDOW_OR_FULLSCREEN);
DECLARE_STRING(FULL_SCREEN);
DECLARE_STRING(OTHER_GRAPHICS_SETTINGS);
DECLARE_STRING(USE_SHADERS);
DECLARE_STRING(USE_HDR);
DECLARE_STRING(SOUND_SETTINGS);
DECLARE_STRING(VOL_MASTER);
DECLARE_STRING(VOL_EFFECTS);
DECLARE_STRING(VOL_MUSIC);
DECLARE_STRING(VIDEO_RESOLUTION);
DECLARE_STRING(X_BY_X);
DECLARE_STRING(PLANET_DETAIL_DISTANCE);
DECLARE_STRING(CITY_DETAIL_LEVEL);
DECLARE_STRING(PLANET_TEXTURES);
DECLARE_STRING(FRACTAL_DETAIL);
DECLARE_STRING(CONTROLS);
DECLARE_STRING(ENABLE_JOYSTICK);
DECLARE_STRING(MOUSE_INPUT);
DECLARE_STRING(INVERT_MOUSE_Y);
DECLARE_STRING(LANGUAGE_SELECTION);
DECLARE_STRING(NONE);
DECLARE_STRING(HYDROGEN);
DECLARE_STRING(HYDROGEN_DESCRIPTION);
DECLARE_STRING(LIQUID_OXYGEN);
DECLARE_STRING(LIQUID_OXYGEN_DESCRIPTION);
DECLARE_STRING(METAL_ORE);
DECLARE_STRING(CARBON_ORE);
DECLARE_STRING(CARBON_ORE_DESCRIPTION);
DECLARE_STRING(METAL_ALLOYS);
DECLARE_STRING(PLASTICS);
DECLARE_STRING(FRUIT_AND_VEG);
DECLARE_STRING(ANIMAL_MEAT);
DECLARE_STRING(LIVE_ANIMALS);
DECLARE_STRING(LIQUOR);
DECLARE_STRING(GRAIN);
DECLARE_STRING(TEXTILES);
DECLARE_STRING(FERTILIZER);
DECLARE_STRING(WATER);
DECLARE_STRING(MEDICINES);
DECLARE_STRING(CONSUMER_GOODS);
DECLARE_STRING(COMPUTERS);
DECLARE_STRING(ROBOTS);
DECLARE_STRING(PRECIOUS_METALS);
DECLARE_STRING(INDUSTRIAL_MACHINERY);
DECLARE_STRING(FARM_MACHINERY);
DECLARE_STRING(MINING_MACHINERY);
DECLARE_STRING(AIR_PROCESSORS);
DECLARE_STRING(SLAVES);
DECLARE_STRING(HAND_WEAPONS);
DECLARE_STRING(BATTLE_WEAPONS);
DECLARE_STRING(NERVE_GAS);
DECLARE_STRING(NARCOTICS);
DECLARE_STRING(MILITARY_FUEL);
DECLARE_STRING(RUBBISH);
DECLARE_STRING(RADIOACTIVES);
DECLARE_STRING(MISSILE_UNGUIDED);
DECLARE_STRING(MISSILE_GUIDED);
DECLARE_STRING(MISSILE_SMART);
DECLARE_STRING(MISSILE_NAVAL);
DECLARE_STRING(ATMOSPHERIC_SHIELDING);
DECLARE_STRING(ATMOSPHERIC_SHIELDING_DESCRIPTION);
DECLARE_STRING(ECM_BASIC);
DECLARE_STRING(ECM_BASIC_DESCRIPTION);
DECLARE_STRING(SCANNER);
DECLARE_STRING(SCANNER_DESCRIPTION);
DECLARE_STRING(ECM_ADVANCED);
DECLARE_STRING(ECM_ADVANCED_DESCRIPTION);
DECLARE_STRING(SHIELD_GENERATOR);
DECLARE_STRING(SHIELD_GENERATOR_DESCRIPTION);
DECLARE_STRING(LASER_COOLING_BOOSTER);
DECLARE_STRING(LASER_COOLING_BOOSTER_DESCRIPTION);
DECLARE_STRING(CARGO_LIFE_SUPPORT);
DECLARE_STRING(CARGO_LIFE_SUPPORT_DESCRIPTION);
DECLARE_STRING(AUTOPILOT);
DECLARE_STRING(AUTOPILOT_DESCRIPTION);
DECLARE_STRING(RADAR_MAPPER);
DECLARE_STRING(RADAR_MAPPER_DESCRIPTION);
DECLARE_STRING(FUEL_SCOOP);
DECLARE_STRING(FUEL_SCOOP_DESCRIPTION);
DECLARE_STRING(CARGO_SCOOP);
DECLARE_STRING(CARGO_SCOOP_DESCRIPTION);
DECLARE_STRING(HYPERCLOUD_ANALYZER);
DECLARE_STRING(HYPERCLOUD_ANALYZER_DESCRIPTION);
DECLARE_STRING(HULL_AUTOREPAIR);
DECLARE_STRING(HULL_AUTOREPAIR_DESCRIPTION);
DECLARE_STRING(SHIELD_ENERGY_BOOSTER);
DECLARE_STRING(SHIELD_ENERGY_BOOSTER_DESCRIPTION);
DECLARE_STRING(DRIVE_CLASS1);
DECLARE_STRING(DRIVE_CLASS2);
DECLARE_STRING(DRIVE_CLASS3);
DECLARE_STRING(DRIVE_CLASS4);
DECLARE_STRING(DRIVE_CLASS5);
DECLARE_STRING(DRIVE_CLASS6);
DECLARE_STRING(DRIVE_CLASS7);
DECLARE_STRING(DRIVE_CLASS8);
DECLARE_STRING(DRIVE_CLASS9);
DECLARE_STRING(DRIVE_MIL1);
DECLARE_STRING(DRIVE_MIL2);
DECLARE_STRING(DRIVE_MIL3);
DECLARE_STRING(DRIVE_MIL4);
DECLARE_STRING(PULSECANNON_1MW);
DECLARE_STRING(PULSECANNON_DUAL_1MW);
DECLARE_STRING(PULSECANNON_2MW);
DECLARE_STRING(PULSECANNON_RAPID_2MW);
DECLARE_STRING(PULSECANNON_4MW);
DECLARE_STRING(PULSECANNON_10MW);
DECLARE_STRING(PULSECANNON_20MW);
DECLARE_STRING(MININGCANNON_17MW);
DECLARE_STRING(MININGCANNON_17MW_DESCRIPTION);
DECLARE_STRING(SMALL_PLASMA_ACCEL);
DECLARE_STRING(LARGE_PLASMA_ACCEL);
DECLARE_STRING(CLEAN);
DECLARE_STRING(HYPERSPACE_ARRIVAL_CLOUD);
DECLARE_STRING(HYPERSPACE_DEPARTURE_CLOUD);
DECLARE_STRING(TYPE);
DECLARE_STRING(CLIENT);
DECLARE_STRING(LOCATION);
DECLARE_STRING(DUE);
DECLARE_STRING(REWARD);
DECLARE_STRING(STATUS);
DECLARE_STRING(CARGO_INVENTORY);
DECLARE_STRING(JETTISON);
DECLARE_STRING(JETTISONED_1T_OF_X);
DECLARE_STRING(COMBAT_RATING);
DECLARE_STRING(CRIMINAL_RECORD);
DECLARE_STRING(SHIP_INFORMATION_HEADER);
DECLARE_STRING(HYPERDRIVE);
DECLARE_STRING(FREE);
DECLARE_STRING(USED);
DECLARE_STRING(TOTAL_WEIGHT);
DECLARE_STRING(FRONT_WEAPON);
DECLARE_STRING(REAR_WEAPON);
DECLARE_STRING(HYPERSPACE_RANGE);
DECLARE_STRING(NO_MOUNTING);
DECLARE_STRING(N_LIGHT_YEARS_N_MAX);
DECLARE_STRING(SHIP_INFORMATION);
DECLARE_STRING(REPUTATION);
DECLARE_STRING(MISSIONS);
DECLARE_STRING(SHIFT);
DECLARE_STRING(CTRL);
DECLARE_STRING(ALT);
DECLARE_STRING(META);
DECLARE_STRING(JOY);
DECLARE_STRING(BUTTON);
DECLARE_STRING(HAT);
DECLARE_STRING(DIRECTION);
DECLARE_STRING(X);
DECLARE_STRING(Y);
DECLARE_STRING(Z);
DECLARE_STRING(AXIS);
DECLARE_STRING(WEAPONS);
DECLARE_STRING(TARGET_OBJECT_IN_SIGHTS);
DECLARE_STRING(FIRE_LASER);
DECLARE_STRING(SHIP_ORIENTATION);
DECLARE_STRING(FAST_ROTATION_CONTROL);
DECLARE_STRING(PITCH_UP);
DECLARE_STRING(PITCH_DOWN);
DECLARE_STRING(YAW_LEFT);
DECLARE_STRING(YAW_RIGHT);
DECLARE_STRING(ROLL_LEFT);
DECLARE_STRING(ROLL_RIGHT);
DECLARE_STRING(MANUAL_CONTROL_MODE);
DECLARE_STRING(THRUSTER_MAIN);
DECLARE_STRING(THRUSTER_RETRO);
DECLARE_STRING(THRUSTER_VENTRAL);
DECLARE_STRING(THRUSTER_DORSAL);
DECLARE_STRING(THRUSTER_PORT);
DECLARE_STRING(THRUSTER_STARBOARD);
DECLARE_STRING(SPEED_CONTROL_MODE);
DECLARE_STRING(INCREASE_SET_SPEED);
DECLARE_STRING(DECREASE_SET_SPEED);
DECLARE_STRING(TOGGLE_LUA_CONSOLE);
DECLARE_STRING(JOYSTICK_INPUT);
DECLARE_STRING(PITCH);
DECLARE_STRING(ROLL);
DECLARE_STRING(YAW);
DECLARE_STRING(MISSILE);
DECLARE_STRING(HARMLESS);
DECLARE_STRING(MOSTLY_HARMLESS);
DECLARE_STRING(POOR);
DECLARE_STRING(AVERAGE);
DECLARE_STRING(ABOVE_AVERAGE );
DECLARE_STRING(COMPETENT);
DECLARE_STRING(DANGEROUS);
DECLARE_STRING(DEADLY);
DECLARE_STRING(ELITE);
DECLARE_STRING(SIMULATING_UNIVERSE_EVOLUTION_N_BYEARS);
DECLARE_STRING(TOMBSTONE_EPITAPH);
DECLARE_STRING(MM_START_NEW_GAME_EARTH);
DECLARE_STRING(MM_START_NEW_GAME_E_ERIDANI);
DECLARE_STRING(MM_START_NEW_GAME_DEBUG);
DECLARE_STRING(MM_LOAD_SAVED_GAME);
DECLARE_STRING(MM_QUIT);
DECLARE_STRING(SCREENSHOT_FILENAME_TEMPLATE);
DECLARE_STRING(PIONEERING_PILOTS_GUILD);
DECLARE_STRING(RIGHT_ON_COMMANDER);
DECLARE_STRING(ALERT_CANCELLED);
DECLARE_STRING(SHIP_DETECTED_NEARBY);
DECLARE_STRING(DOWNGRADING_ALERT_STATUS);
DECLARE_STRING(LASER_FIRE_DETECTED);
DECLARE_STRING(SOMEWHERE_POLICE);
DECLARE_STRING(WE_HAVE_NO_BUSINESS_WITH_YOU);
DECLARE_STRING(YOU_MUST_PAY_FINE_OF_N_CREDITS);
DECLARE_STRING(PAY_THE_FINE_NOW);
DECLARE_STRING(HANG_UP);
DECLARE_STRING(TRADING_ILLEGAL_GOODS);
DECLARE_STRING(UNLAWFUL_WEAPONS_DISCHARGE);
DECLARE_STRING(PIRACY);
DECLARE_STRING(MURDER);
DECLARE_STRING(INDEPENDENT);
DECLARE_STRING(EARTH_FEDERATION);
DECLARE_STRING(INDEPENDENT_CONFEDERATION);
DECLARE_STRING(EMPIRE);
DECLARE_STRING(NO_ESTABLISHED_ORDER);
DECLARE_STRING(HARD_CAPITALIST);
DECLARE_STRING(CAPITALIST);
DECLARE_STRING(MIXED_ECONOMY);
DECLARE_STRING(PLANNED_ECONOMY);
DECLARE_STRING(NO_CENTRAL_GOVERNANCE);
DECLARE_STRING(EARTH_FEDERATION_COLONIAL_RULE);
DECLARE_STRING(EARTH_FEDERATION_DEMOCRACY);
DECLARE_STRING(IMPERIAL_RULE);
DECLARE_STRING(LIBERAL_DEMOCRACY);
DECLARE_STRING(SOCIAL_DEMOCRACY);
DECLARE_STRING(CORPORATE_SYSTEM);
DECLARE_STRING(MILITARY_DICTATORSHIP);
DECLARE_STRING(COMMUNIST);
DECLARE_STRING(PLUTOCRATIC_DICTATORSHIP);
DECLARE_STRING(VIOLENT_ANARCHY);
DECLARE_STRING(X_CANNOT_BE_TOLERATED_HERE);
DECLARE_STRING(SECTOR_X_Y_Z);
DECLARE_STRING(CURRENT_SYSTEM);
DECLARE_STRING(SELECTED_SYSTEM);
DECLARE_STRING(HYPERSPACE_TARGET);
DECLARE_STRING(FOLLOWING_SELECTION);
DECLARE_STRING(LOCKED);
DECLARE_STRING(EXACT_MATCH_X);
DECLARE_STRING(NOT_FOUND_BEST_MATCH_X);
DECLARE_STRING(NOT_FOUND);
DECLARE_STRING(QUADRUPLE_SYSTEM);
DECLARE_STRING(TRIPLE_SYSTEM);
DECLARE_STRING(BINARY_SYSTEM);
DECLARE_STRING(ENABLED_AUTOMATIC_SYSTEM_SELECTION);
DECLARE_STRING(DISABLED_AUTOMATIC_SYSTEM_SELECTION);
DECLARE_STRING(FUEL_SCOOP_ACTIVE_N_TONNES_H_COLLECTED);
DECLARE_STRING(CARGO_SCOOP_ACTIVE_1_TONNE_X_COLLECTED);
DECLARE_STRING(CARGO_BAY_LIFE_SUPPORT_LOST);
DECLARE_STRING(NO_FREE_SPACE_FOR_ITEM);
DECLARE_STRING(SHIP_IS_FULLY_LADEN);
DECLARE_STRING(YOU_DO_NOT_HAVE_ANY_X);
DECLARE_STRING(FRONT_VIEW);
DECLARE_STRING(REAR_VIEW);
DECLARE_STRING(EXTERNAL_VIEW);
DECLARE_STRING(NAVIGATION_STAR_MAPS);
DECLARE_STRING(COMMS);
DECLARE_STRING(GALAXY_SECTOR_VIEW);
DECLARE_STRING(SYSTEM_ORBIT_VIEW);
DECLARE_STRING(STAR_SYSTEM_INFORMATION);
DECLARE_STRING(GALACTIC_VIEW);
DECLARE_STRING(NO_ALERT);
DECLARE_STRING(SHIP_NEARBY);
DECLARE_STRING(DOCKING_CLEARANCE_EXPIRED);
DECLARE_STRING(MESSAGE_FROM_X);
DECLARE_STRING(SELECT_A_TARGET);
DECLARE_STRING(FRONT);
DECLARE_STRING(REAR);
DECLARE_STRING(POLICE_SHIP_REGISTRATION);
DECLARE_STRING(CLEARANCE_ALREADY_GRANTED_BAY_N);
DECLARE_STRING(CLEARANCE_GRANTED_BAY_N);
DECLARE_STRING(CLEARANCE_DENIED_NO_BAYS);
DECLARE_STRING(ITEM_IS_OUT_OF_STOCK);
DECLARE_STRING(BROWN_DWARF);
DECLARE_STRING(WHITE_DWARF);
DECLARE_STRING(STAR_M);
DECLARE_STRING(STAR_K);
DECLARE_STRING(STAR_G);
DECLARE_STRING(STAR_F);
DECLARE_STRING(STAR_A);
DECLARE_STRING(STAR_B);
DECLARE_STRING(STAR_O);
DECLARE_STRING(STAR_M_GIANT);
DECLARE_STRING(STAR_K_GIANT);
DECLARE_STRING(STAR_G_GIANT);
DECLARE_STRING(STAR_AF_GIANT);
DECLARE_STRING(STAR_B_GIANT);
DECLARE_STRING(STAR_O_GIANT);
DECLARE_STRING(STAR_M_SUPER_GIANT);
DECLARE_STRING(STAR_K_SUPER_GIANT);
DECLARE_STRING(STAR_G_SUPER_GIANT);
DECLARE_STRING(STAR_AF_SUPER_GIANT);
DECLARE_STRING(STAR_B_SUPER_GIANT);
DECLARE_STRING(STAR_O_SUPER_GIANT);
DECLARE_STRING(STAR_M_HYPER_GIANT);
DECLARE_STRING(STAR_K_HYPER_GIANT);
DECLARE_STRING(STAR_G_HYPER_GIANT);
DECLARE_STRING(STAR_AF_HYPER_GIANT);
DECLARE_STRING(STAR_B_HYPER_GIANT);
DECLARE_STRING(STAR_O_HYPER_GIANT);
DECLARE_STRING(STAR_M_WF);
DECLARE_STRING(STAR_B_WF);
DECLARE_STRING(STAR_O_WF);
DECLARE_STRING(STAR_S_BH);
DECLARE_STRING(STAR_IM_BH);
DECLARE_STRING(STAR_SM_BH);
DECLARE_STRING(VERY_LARGE_GAS_GIANT);
DECLARE_STRING(LARGE_GAS_GIANT);
DECLARE_STRING(MEDIUM_GAS_GIANT);
DECLARE_STRING(SMALL_GAS_GIANT);
DECLARE_STRING(ASTEROID);
DECLARE_STRING(MASSIVE);
DECLARE_STRING(LARGE);
DECLARE_STRING(TINY);
DECLARE_STRING(SMALL);
DECLARE_STRING(COMMA_HIGHLY_VOLCANIC);
DECLARE_STRING(HIGHLY_VOLCANIC);
DECLARE_STRING(ICE_WORLD);
DECLARE_STRING(ROCKY_PLANET);
DECLARE_STRING(OCEANICWORLD);
DECLARE_STRING(PLANET_CONTAINING_LIQUID_WATER);
DECLARE_STRING(PLANET_WITH_SOME_ICE);
DECLARE_STRING(ROCKY_PLANET_CONTAINING_COME_LIQUIDS);
DECLARE_STRING(WITH_NO_SIGNIFICANT_ATMOSPHERE);
DECLARE_STRING(TENUOUS);
DECLARE_STRING(THIN);
DECLARE_STRING(THICK);
DECLARE_STRING(VERY_DENSE);
DECLARE_STRING(WITH_A);
DECLARE_STRING(O2_ATMOSPHERE);
DECLARE_STRING(CO2_ATMOSPHERE);
DECLARE_STRING(CO_ATMOSPHERE);
DECLARE_STRING(CH4_ATMOSPHERE);
DECLARE_STRING(H_ATMOSPHERE);
DECLARE_STRING(HE_ATMOSPHERE);
DECLARE_STRING(AR_ATMOSPHERE);
DECLARE_STRING(S_ATMOSPHERE);
DECLARE_STRING(N_ATMOSPHERE);
DECLARE_STRING(AND_HIGHLY_COMPLEX_ECOSYSTEM);
DECLARE_STRING(AND_INDIGENOUS_PLANT_LIFE);
DECLARE_STRING(AND_INDIGENOUS_MICROBIAL_LIFE);
DECLARE_STRING(ORBITAL_STARPORT);
DECLARE_STRING(STARPORT);
DECLARE_STRING(UNKNOWN);
DECLARE_STRING(UNEXPLORED_SYSTEM_NO_DATA);
DECLARE_STRING(SMALL_SCALE_PROSPECTING_NO_SETTLEMENTS);
DECLARE_STRING(SMALL_INDUSTRIAL_OUTPOST);
DECLARE_STRING(SOME_ESTABLISHED_MINING);
DECLARE_STRING(YOUNG_FARMING_COLONY);
DECLARE_STRING(INDUSTRIAL_COLONY);
DECLARE_STRING(MINING_COLONY);
DECLARE_STRING(OUTDOOR_AGRICULTURAL_WORLD);
DECLARE_STRING(HEAVY_INDUSTRY);
DECLARE_STRING(EXTENSIVE_MINING);
DECLARE_STRING(THRIVING_OUTDOOR_WORLD);
DECLARE_STRING(INDUSTRIAL_HUB_SYSTEM);
DECLARE_STRING(VAST_STRIP_MINE);
DECLARE_STRING(HIGH_POPULATION_OUTDOOR_WORLD);
DECLARE_STRING(SOMEWHERE_SPACEPORT);
DECLARE_STRING(SOMEWHERE_STARPORT);
DECLARE_STRING(MASS);
DECLARE_STRING(N_WHATEVER_MASSES);
DECLARE_STRING(SOLAR);
DECLARE_STRING(EARTH);
DECLARE_STRING(SURFACE_TEMPERATURE);
DECLARE_STRING(SURFACE_GRAVITY);
DECLARE_STRING(N_CELSIUS);
DECLARE_STRING(N_YEARS);
DECLARE_STRING(N_DAYS);
DECLARE_STRING(ORBITAL_PERIOD);
DECLARE_STRING(PERIAPSIS_DISTANCE);
DECLARE_STRING(APOAPSIS_DISTANCE);
DECLARE_STRING(ECCENTRICITY);
DECLARE_STRING(AXIAL_TILT);
DECLARE_STRING(N_DEGREES);
DECLARE_STRING(DAY_LENGTH);
DECLARE_STRING(N_EARTH_DAYS);
DECLARE_STRING(COUNT_STARPORTS);
DECLARE_STRING(STARPORTS);
DECLARE_STRING(MAJOR_IMPORTS);
DECLARE_STRING(MINOR_IMPORTS);
DECLARE_STRING(MAJOR_EXPORTS);
DECLARE_STRING(MINOR_EXPORTS);
DECLARE_STRING(ILLEGAL_GOODS);
DECLARE_STRING(UNEXPLORED_SYSTEM_STAR_INFO_ONLY);
DECLARE_STRING(PLANETARY_INFO);
DECLARE_STRING(ECONOMIC_INFO);
DECLARE_STRING(DEMOGRAPHICS);
DECLARE_STRING(STABLE_SYSTEM_WITH_N_MAJOR_BODIES_STARPORTS);
DECLARE_STRING(BODY);
DECLARE_STRING(BODIES);
DECLARE_STRING(SYSTEM_TYPE);
DECLARE_STRING(GOVERNMENT_TYPE);
DECLARE_STRING(ECONOMY_TYPE);
DECLARE_STRING(ALLEGIANCE);
DECLARE_STRING(POPULATION);
DECLARE_STRING(OVER_N_BILLION);
DECLARE_STRING(OVER_N_MILLION);
DECLARE_STRING(A_FEW_THOUSAND);
DECLARE_STRING(NO_REGISTERED_INHABITANTS);
DECLARE_STRING(SECTOR_COORDINATES);
DECLARE_STRING(SYSTEM_NUMBER);
DECLARE_STRING(NAME);
DECLARE_STRING(ROTATIONAL_PERIOD);
DECLARE_STRING(RADIUS);
DECLARE_STRING(SEMI_MAJOR_AXIS);
DECLARE_STRING(TIME_POINT);
DECLARE_STRING(UNEXPLORED_SYSTEM_NO_SYSTEM_VIEW);
DECLARE_STRING(WHEELS_ARE_UP);
DECLARE_STRING(WHEELS_ARE_DOWN);
DECLARE_STRING(OBJECT_LABELS_ARE_ON);
DECLARE_STRING(OBJECT_LABELS_ARE_OFF);
DECLARE_STRING(HYPERSPACE_JUMP);
DECLARE_STRING(TAKEOFF);
DECLARE_STRING(MANUAL_CONTROL);
DECLARE_STRING(COMPUTER_SPEED_CONTROL);
DECLARE_STRING(AUTOPILOT_ON);
DECLARE_STRING(SHIP_VELOCITY_BY_REFERENCE_OBJECT);
DECLARE_STRING(DISTANCE_FROM_SHIP_TO_NAV_TARGET);
DECLARE_STRING(SHIP_ALTITUDE_ABOVE_TERRAIN);
DECLARE_STRING(EXTERNAL_ATMOSPHERIC_PRESSURE);
DECLARE_STRING(HULL_TEMP);
DECLARE_STRING(WEAPON_TEMP);
DECLARE_STRING(HULL_INTEGRITY);
DECLARE_STRING(SHIELD_INTEGRITY);
DECLARE_STRING(LAUNCH_PERMISSION_DENIED_BUSY);
DECLARE_STRING(HYPERSPACE_JUMP_ABORTED);
DECLARE_STRING(LANDED);
DECLARE_STRING(DOCKING);
DECLARE_STRING(DOCKED);
DECLARE_STRING(HYPERSPACE);
DECLARE_STRING(SET_SPEED_KM_S);
DECLARE_STRING(SET_SPEED_M_S);
DECLARE_STRING(KM_S_RELATIVE_TO);
DECLARE_STRING(M_S_RELATIVE_TO);
DECLARE_STRING(N_DISTANCE_TO_TARGET);
DECLARE_STRING(IN_TRANSIT_TO_N_X_X_X);
DECLARE_STRING(ALT_IN_METRES);
DECLARE_STRING(PRESSURE_N_BAR);
DECLARE_STRING(NO_HYPERDRIVE);
DECLARE_STRING(MASS_N_TONNES);
DECLARE_STRING(SHIELD_STRENGTH_N);
DECLARE_STRING(CARGO_N);
DECLARE_STRING(HYPERSPACE_ARRIVAL_CLOUD_REMNANT);
DECLARE_STRING(SHIP_MASS_N_TONNES);
DECLARE_STRING(DATE_DUE_N);
DECLARE_STRING(SOURCE);
DECLARE_STRING(DESTINATION);
DECLARE_STRING(HYPERSPACING_IN_N_SECONDS);
DECLARE_STRING(NAVIGATION_TARGETS_IN_THIS_SYSTEM);
DECLARE_STRING(YOU_NO_MONEY);
DECLARE_STRING(FINE_PAID_N_BUT_N_REMAINING);
DECLARE_STRING(FINE_PAID_N);
DECLARE_STRING(SET_HYPERSPACE_DESTINATION_TO);
DECLARE_STRING(NO_TARGET_SELECTED);
DECLARE_STRING(REQUEST_DOCKING_CLEARANCE);
DECLARE_STRING(AUTOPILOT_DOCK_WITH_STATION);
DECLARE_STRING(PAY_FINE_REMOTELY);
DECLARE_STRING(AUTOPILOT_FLY_TO_VICINITY_OF);
DECLARE_STRING(AUTOPILOT_ENTER_LOW_ORBIT_AROUND);
DECLARE_STRING(AUTOPILOT_ENTER_MEDIUM_ORBIT_AROUND);
DECLARE_STRING(AUTOPILOT_ENTER_HIGH_ORBIT_AROUND);
DECLARE_STRING(SET_HYPERSPACE_TARGET_TO_FOLLOW_THIS_DEPARTURE);
DECLARE_STRING(FAILED);
DECLARE_STRING(COMPLETED);
DECLARE_STRING(ACTIVE);
DECLARE_STRING(DISTANCE_LY);
DECLARE_STRING(SYSTEM);

}

#endif
