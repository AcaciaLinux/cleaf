#include "log.h"
#include "cleafconfig.h"

#include <leafcore/leafconfig.h>

#include <string>
#include <cstring>

extern "C"{

	void cleafconfig_setRootDir(const char* dir){
		FUN();
		lConfig.setRootDir(std::string(dir));
		LOGAPI("[cleaf] Setting cleafconfig root directory to " + std::string(dir));
	}

	void leafconfig_setRedownload(cleaf_config_redownload redownload){
		FUN();

		lConfig.redownload = (config_redownload)redownload;
		LOGAPI("[cleaf] Setting redownload mode to " + std::to_string((int)redownload));
	}

	void cleafconfig_setBoolConfig(cleaf_bool_config config, int option){
		FUN();

		bool state = option;

		switch (config){
		
		case CLEAF_B_CONFIG_NOASK:
			lConfig.noAsk = state;
			break;

		case CLEAF_B_CONFIG_FORCEOVERWRITE:
			lConfig.forceOverwrite = state;
			break;

		case CLEAF_B_CONFIG_RUNPREINSTALL:
			lConfig.runPreinstall = state;
			break;

		case CLEAF_B_CONFIG_RUNPOSTINSTALL:
			lConfig.runPostinstall = state;
			break;

		}

		LOGAPI("[cleaf] Set boolean config " + std::to_string(config) + " to " + std::to_string(state));

	}

	int leafconfig_getBoolConfig(cleaf_bool_config config){
		FUN();

		int res = -1;

		switch (config){
		
		case CLEAF_B_CONFIG_NOASK:
			res = lConfig.noAsk;
			break;

		case CLEAF_B_CONFIG_FORCEOVERWRITE:
			res = lConfig.forceOverwrite;
			break;

		case CLEAF_B_CONFIG_RUNPREINSTALL:
			res = lConfig.runPreinstall;
			break;

		case CLEAF_B_CONFIG_RUNPOSTINSTALL:
			res = lConfig.runPostinstall;
			break;

		}

		LOGAPI("[cleaf] Got state of bool config " + std::to_string(config) + ": " + std::to_string(res));

		return res;

	}

	char* cleafconfig_getStringConfig(cleaf_string_config config){
		FUN();

		std::string res;

		switch (config){

		case CLEAF_S_ROOTDIR:
			res = lConfig.rootDir;
			break;

		case CLEAF_S_CACHEDIR:
			res = lConfig.cacheDir();
			break;

		case CLEAF_S_DOWNLOADDIR:
			res = lConfig.downloadDir();
			break;

		case CLEAF_S_PACKAGESDIR:
			res = lConfig.packagesDir();
			break;

		case CLEAF_S_CONFIGDIR:
			res = lConfig.configDir();
			break;

		case CLEAF_S_INSTALLEDDIR:
			res = lConfig.installedDir();
			break;

		case CLEAF_S_PKGLISTPATH:
			res = lConfig.pkgListPath();
			break;

		}

		LOGAPI("[cleaf] Got state of string config " + std::to_string(config) + ": \"" + res + "\"");

		char* resString = new char[res.length()+1];
		std::strcpy(resString, res.c_str());
		resString[res.length()] = 0;

		return resString;

	}

}
