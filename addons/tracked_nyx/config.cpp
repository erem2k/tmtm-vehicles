#include "script_component.hpp"

class CfgPatches {
	class ADDON {
		name = COMPONENT_NAME;
		units[] = {
			"TMTM_I_LT_01_HAT_F"
		};
		weapons[] =	{
			"TMTM_LAHAT"
		};
		magazines[] = {
			"2Rnd_120mm_LG_missiles"
		};
		requiredAddons[] = {
			"tmtm_vehicles_main",
			"A3_Armor_F_Tank_LT_01"
		};

		requiredVersion = REQUIRED_VERSION;
		
		author = MOD_AUTHOR;
		url = MOD_URL;
		version = VERSION;
		versionStr = QUOTE(VERSION_STR);
		versionAr[] = {QUOTE(VERSION_AR)};
	};
};

#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
