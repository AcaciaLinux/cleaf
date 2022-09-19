#include "log.h"
#include "cleafconfig.h"

#include <leafcore/leafconfig.h>

#include <string>
#include <cstring>

extern "C"{

	void cleafconfig_setRootDir(cleaf_config* conf, const char* dir){
		FUN();
		((leaf_config_t*)conf)->setRootDir(std::string(dir));
		LOGAPI("[cleaf] Setting cleafconfig root directory to " + std::string(dir));
	}

	void leafconfig_setRedownload(cleaf_config* conf, cleaf_config_redownload redownload){
		FUN();

		((leaf_config_t*)conf)->redownload = (config_redownload)redownload;
		LOGAPI("[cleaf] Setting redownload mode to " + std::to_string((int)redownload));
	}

	void cleafconfig_setBoolConfig(cleaf_config* conf, cleaf_bool_config config, int option){
		FUN();

		bool state = option;

		switch (config){
		
		case CLEAF_B_CONFIG_NOASK:
			((leaf_config_t*)conf)->noAsk = state;
			break;

		case CLEAF_B_CONFIG_FORCEOVERWRITE:
			((leaf_config_t*)conf)->forceOverwrite = state;
			break;

		case CLEAF_B_CONFIG_RUNPREINSTALL:
			((leaf_config_t*)conf)->runPreinstall = state;
			break;

		case CLEAF_B_CONFIG_RUNPOSTINSTALL:
			((leaf_config_t*)conf)->runPostinstall = state;
			break;

		}

		LOGAPI("[cleaf] Set boolean config " + std::to_string(config) + " to " + std::to_string(state));

	}

	int leafconfig_getBoolConfig(cleaf_config* conf, cleaf_bool_config config){
		FUN();

		int res = -1;

		switch (config){
		
		case CLEAF_B_CONFIG_NOASK:
			res = ((leaf_config_t*)conf)->noAsk;
			break;

		case CLEAF_B_CONFIG_FORCEOVERWRITE:
			res = ((leaf_config_t*)conf)->forceOverwrite;
			break;

		case CLEAF_B_CONFIG_RUNPREINSTALL:
			res = ((leaf_config_t*)conf)->runPreinstall;
			break;

		case CLEAF_B_CONFIG_RUNPOSTINSTALL:
			res = ((leaf_config_t*)conf)->runPostinstall;
			break;

		}

		LOGAPI("[cleaf] Got state of bool config " + std::to_string(config) + ": " + std::to_string(res));

		return res;

	}

	char* cleafconfig_getStringConfig(cleaf_config* conf, cleaf_string_config config){
		FUN();

		std::string res;

		switch (config){

		case CLEAF_S_ROOTDIR:
			res = ((leaf_config_t*)conf)->rootDir;
			break;

		case CLEAF_S_CACHEDIR:
			res = ((leaf_config_t*)conf)->cacheDir();
			break;

		case CLEAF_S_DOWNLOADDIR:
			res = ((leaf_config_t*)conf)->downloadDir();
			break;

		case CLEAF_S_PACKAGESDIR:
			res = ((leaf_config_t*)conf)->packagesDir();
			break;

		case CLEAF_S_CONFIGDIR:
			res = ((leaf_config_t*)conf)->configDir();
			break;

		case CLEAF_S_INSTALLEDDIR:
			res = ((leaf_config_t*)conf)->installedDir();
			break;

		case CLEAF_S_PKGLISTPATH:
			res = ((leaf_config_t*)conf)->pkgListPath();
			break;

		}

		LOGAPI("[cleaf] Got state of string config " + std::to_string(config) + ": \"" + res + "\"");

		char* resString = new char[res.length()+1];
		std::strcpy(resString, res.c_str());
		resString[res.length()] = 0;

		return resString;

	}

}
