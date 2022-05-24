#include "log.h"
#include "cleafconfig.h"

#include <leafcore/leafconfig.h>

extern "C"{

	void cleafconfig_setRootDir(const char* dir){
		lConfig.setRootDir(std::string(dir));
	}

}
