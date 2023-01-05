#include "log.h"

#define FRIEND_LEAFCORE
#include "leafcore/leafcore.h"
#include "leafcore_dist.h"

#include "cleafconfig.h"

#include <leafcore/leafconfig.h>

#include <string>
#include <cstring>

extern "C"{

	void cleafconfig_setRootDir(void* cleafcore, const char* dir){
		FUN();
		((Leafcore*)cleafcore)->getConfig().setRootDir(dir);
		LOGAPI("[cleaf] Setting cleafconfig root directory to " + std::string(dir));
	}

	void leafconfig_setRedownload(void* cleafcore, cleaf_config_redownload redownload){
		FUN();

		((Leafcore*)cleafcore)->getConfig().redownload = (config_redownload)redownload;
		LOGAPI("[cleaf] Setting redownload mode to " + std::to_string((int)redownload));
	}

	void cleafconfig_setBoolConfig(void* cleafcore, cleaf_bool_config config, int option){
		FUN();

		bool state = option;

		switch (config){
		
		case CLEAF_B_CONFIG_NOASK:
			((Leafcore*)cleafcore)->getConfig().noAsk = state;
			break;

		case CLEAF_B_CONFIG_FORCEOVERWRITE:
			((Leafcore*)cleafcore)->getConfig().forceOverwrite = state;
			break;

		case CLEAF_B_CONFIG_RUNPREINSTALL:
			((Leafcore*)cleafcore)->getConfig().runPreinstall = state;
			break;

		case CLEAF_B_CONFIG_RUNPOSTINSTALL:
			((Leafcore*)cleafcore)->getConfig().runPostinstall = state;
			break;

		case CLEAF_B_CONFIG_NOPROGRESS:
			#if LEAFCORE_V_MINOR > 2 || LEAFCORE_V_MINOR == 2 && LEAFCORE_V_PATCH >= 3
				((Leafcore*)cleafcore)->getConfig().noProgress = state;
			#else
				e_feature_missing("leafconfig.noProgress", 0, 2, 3);
			#endif
			break;

		case CLEAF_B_CONFIG_FORCE:
			#if LEAFCORE_V_MINOR > 3 || LEAFCORE_V_MINOR == 3 && LEAFCORE_V_PATCH >= 0
				((Leafcore*)cleafcore)->getConfig().force = state;
			#else
				e_feature_missing("leafconfig.force", 0, 2, 3);
			#endif
			break;

		case CLEAF_B_CONFIG_CHECKREMOTEHASHES:
			#if LEAFCORE_V_MINOR > 4 || LEAFCORE_V_MINOR == 4 && LEAFCORE_V_PATCH >= 0
				((Leafcore*)cleafcore)->getConfig().checkRemoteHashUpgrade = state;
			#else
				e_feature_missing("leafconfig.checkRemoteHashUpgrade", 0, 2, 3);
			#endif
			break;

		}

		LOGAPI("[cleaf] Set boolean config " + std::to_string(config) + " to " + std::to_string(state));

	}

	int leafconfig_getBoolConfig(void* cleafcore, cleaf_bool_config config){
		FUN();

		int res = -1;

		switch (config){
		
		case CLEAF_B_CONFIG_NOASK:
			res = ((Leafcore*)cleafcore)->getConfig().noAsk;
			break;

		case CLEAF_B_CONFIG_FORCEOVERWRITE:
			res = ((Leafcore*)cleafcore)->getConfig().forceOverwrite;
			break;

		case CLEAF_B_CONFIG_RUNPREINSTALL:
			res = ((Leafcore*)cleafcore)->getConfig().runPreinstall;
			break;

		case CLEAF_B_CONFIG_RUNPOSTINSTALL:
			res = ((Leafcore*)cleafcore)->getConfig().runPostinstall;
			break;

		case CLEAF_B_CONFIG_NOPROGRESS:
			#if LEAFCORE_V_MINOR > 2 || LEAFCORE_V_MINOR == 2 && LEAFCORE_V_PATCH >= 3
				res = ((Leafcore*)cleafcore)->getConfig().noProgress;
			#else
				res = false;
				e_feature_missing("leafconfig.noProgress", 0, 2, 3);
			#endif
			break;

		case CLEAF_B_CONFIG_FORCE:
			#if LEAFCORE_V_MINOR > 3 || LEAFCORE_V_MINOR == 3 && LEAFCORE_V_PATCH >= 0
				res = ((Leafcore*)cleafcore)->getConfig().force;
			#else
				res = false;
				e_feature_missing("leafconfig.force", 0, 2, 3);
			#endif
			break;

		case CLEAF_B_CONFIG_CHECKREMOTEHASHES:
			#if LEAFCORE_V_MINOR > 4 || LEAFCORE_V_MINOR == 4 && LEAFCORE_V_PATCH >= 0
				res = ((Leafcore*)cleafcore)->getConfig().checkRemoteHashUpgrade;
			#else
				res = false;
				e_feature_missing("leafconfig.force", 0, 2, 3);
			#endif
			break;

		}

		LOGAPI("[cleaf] Got state of bool config " + std::to_string(config) + ": " + std::to_string(res));

		return res;

	}

	int cleafconfig_setStringConfig(void* cleafcore, cleaf_string_config config, const char* option_c_str){
		FUN();

		std::string option(option_c_str);

		switch (config){

			case CLEAF_S_ROOTDIR: {
				LOGAPI("[cleaf] Setting leafconfig rootDir to '" + option + "'");
				((Leafcore*)cleafcore)->getConfig().rootDir = option;
				break;
			}

			case CLEAF_S_PKGLISTURL: {
				LOGAPI("[cleaf] Setting leafconfig pkgListURL to '" + option + "'");
				((Leafcore*)cleafcore)->getConfig().pkgListURL = option;
				break;
			}

			case CLEAF_S_CACHEDIR:
			case CLEAF_S_DOWNLOADDIR:
			case CLEAF_S_PACKAGESDIR:
			case CLEAF_S_CONFIGDIR:
			case CLEAF_S_INSTALLEDDIR:
			case CLEAF_S_PKGLISTPATH: {
				LOGUE("[cleaf] Tried to write read-only leaf string config " + std::to_string((int) config));
				return -2;
			}

			default: {
				LOGUE("[cleaf] Unknown string config id " + std::to_string((int) config));
				return -1;
			}
		}
		return 0;
	}

	char* cleafconfig_getStringConfig(void* cleafcore, cleaf_string_config config){
		FUN();

		std::string res;

		switch (config){

		case CLEAF_S_ROOTDIR:
			res = ((Leafcore*)cleafcore)->getConfig().rootDir;
			break;

		case CLEAF_S_CACHEDIR:
			res = ((Leafcore*)cleafcore)->getConfig().cacheDir();
			break;

		case CLEAF_S_DOWNLOADDIR:
			res = ((Leafcore*)cleafcore)->getConfig().downloadDir();
			break;

		case CLEAF_S_PACKAGESDIR:
			res = ((Leafcore*)cleafcore)->getConfig().packagesDir();
			break;

		case CLEAF_S_CONFIGDIR:
			res = ((Leafcore*)cleafcore)->getConfig().configDir();
			break;

		case CLEAF_S_INSTALLEDDIR:
			res = ((Leafcore*)cleafcore)->getConfig().installedDir();
			break;

		case CLEAF_S_PKGLISTPATH:
			res = ((Leafcore*)cleafcore)->getConfig().pkgListPath();
			break;

		}

		LOGAPI("[cleaf] Got state of string config " + std::to_string(config) + ": \"" + res + "\"");

		char* resString = new char[res.length()+1];
		std::strcpy(resString, res.c_str());
		resString[res.length()] = 0;

		return resString;

	}

}
