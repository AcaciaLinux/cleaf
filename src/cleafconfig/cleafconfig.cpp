#include "log.h"
#include "cleafconfig.h"

#include <leafcore/leafconfig.h>

#include <string>
#include <cstring>

extern "C"{

	void leafconfig_setRedownload(cleaf_config_redownload redownload){
		FUN();

		lConfig.redownload = (config_redownload)redownload;
	}

	void cleafconfig_setRootDir(const char* dir){
		lConfig.setRootDir(std::string(dir));
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

	}

	int leafconfig_getBoolConfig(cleaf_bool_config config){
		FUN();

		switch (config){
		
		case CLEAF_B_CONFIG_NOASK:
			return lConfig.noAsk;

		case CLEAF_B_CONFIG_FORCEOVERWRITE:
			return lConfig.forceOverwrite;

		case CLEAF_B_CONFIG_RUNPREINSTALL:
			return lConfig.runPreinstall;

		case CLEAF_B_CONFIG_RUNPOSTINSTALL:
			return lConfig.runPostinstall;

		}

		return 255;

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

		char* resString = new char[res.length()+1];
		std::strcpy(resString, res.c_str());
		resString[res.length()] = 0;

		return resString;

	}

}
