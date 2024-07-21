class SensorTemplateLaser;
class SensorTemplateDataLink;

class CfgVehicles
{
	class I_LT_01_AT_F;
	class TMTM_I_LT_01_HAT_base: I_LT_01_AT_F
	{
		scope = 1;
		author = "Blah2355";
		class Components;
		class Turrets;
		class TurretsBase: Turrets
		{
			class MainTurret;
			class MainTurretBase: MainTurret
			{
				class Components;
				class ComponentsTurret: Components
				{
					class VehicleSystemsDisplayManagerComponentLeft;
					class VehicleSystemsDisplayManagerComponentRight;
				};
			};
		};
		class AnimationSources;
	};
	
	class TMTM_I_LT_01_HAT_F: TMTM_I_LT_01_HAT_base
	{
		scope = 2;
		scopeCurator = 2;
		displayName = "AWC 305 Nyx (HAT)";
		editorSubcategory="EdSubcat_Tanks";
		radarType = 2;
		
		class Library
		{
			libTextDesc = "The AWC 305 Nyx (HAT) is a heavy AT Nyx variant, equipped with laser guided 120mm MARUK ATGM.";
		};
		
		class Components: Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class DataLinkSensorComponent: SensorTemplateDataLink
					{
					};
					class LaserSensorComponent: SensorTemplateLaser
					{
						animDirection = "mainTurret";
					};
				};
			};
		};
		
		receiveRemoteTargets = true;
		reportRemoteTargets = false;
		reportOwnPosition = true;
		
		class Turrets: TurretsBase
		{
			class MainTurret: MainTurretBase
			{
				weapons[] = {"SmokeLauncher", "HMG_127", "TMTM_LAHAT"};
				magazines[] = {"SmokeLauncherMag", "100Rnd_127x99_mag_Tracer_Red", "100Rnd_127x99_mag_Tracer_Red", "100Rnd_127x99_mag_Tracer_Red", "100Rnd_127x99_mag_Tracer_Red", "2Rnd_120mm_LG_missiles", "2Rnd_120mm_LG_missiles", "2Rnd_120mm_LG_missiles"};
				
				class Components: ComponentsTurret
				{
					class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsDisplayManagerComponentLeft
					{
						defaultDisplay="MissileDisplay";
						class Components: Components
						{
							class SensorsDisplay
							{
								componentType = "SensorsDisplayComponent";
								range[] = {4000, 2000, 1000};
								//showTargetTypes = 1+2+4+1024;
								resource = "RscCustomInfoSensors";
							};
							class MissileDisplay
							{
								componentType = "TransportFeedDisplayComponent";
								source = "Missile";
							};
						};
					};
					class VehicleSystemsDisplayManagerComponentRight: VehicleSystemsDisplayManagerComponentRight
					{
						defaultDisplay="SensorDisplay";
						class Components: Components
						{
							class SensorDisplay
							{
								componentType = "SensorsDisplayComponent";
								range[] = {4000, 2000, 1000};
								//showTargetTypes = 1+2+4+1024;
								resource = "RscCustomInfoSensors";
							};
							class MissileDisplay
							{
								componentType = "TransportFeedDisplayComponent";
								source = "Missile";
							};
						};
					};
				};
			};
		};
		
		class AnimationSources: AnimationSources
		{
			class Missiles_revolving
			{
				source="revolving";
				weapon="TMTM_LAHAT";
			};
			class Missiles_reloadMagazine
			{
				source="reloadMagazine";
				weapon="TMTM_LAHAT";
			};
		};
	};
};