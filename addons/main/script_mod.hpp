#include "script_version.hpp"

#define PREFIX tmtm_vehicles

#define VERSION     MAJOR.MINOR
#define VERSION_STR MAJOR.MINOR.PATCHLVL.BUILD
#define VERSION_AR  MAJOR,MINOR,PATCHLVL,BUILD

#define QUOTE(var1) #var1

// MINIMAL required version for the Mod. Components can specify others..
#define REQUIRED_VERSION 1.98

#ifdef COMPONENT_BEAUTIFIED
    #define COMPONENT_NAME QUOTE(TMTM Vehicles - COMPONENT_BEAUTIFIED)
#else
    #define COMPONENT_NAME QUOTE(TMTM Vehicles - COMPONENT)
#endif

#define DOUBLES(var1,var2) var1##_##var2
#define ADDON DOUBLES(PREFIX,COMPONENT)

#define MOD_AUTHOR QUOTE(TMTM)
#define MOD_URL "https://github.com/erem2k/tmtm-vehicles"