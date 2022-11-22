/**
 * @file		cleaf/cleaf.cpp
 * @author		Max Kofler (kofler.max.dev@gmail.com)
 * @brief		The implementation of the cleaf.h header
 * @copyright	Copyright (c) 2022
 */
#include "cleaf.h"
#include "leafcore_dist.h"

#include "log.h"

bool _cleaf_initialized = false;

extern "C"{

	unsigned int cleaf_get_leafcore_major(){
		return CLEAFCORE_LEAFCORE_MAJOR;
	}

	unsigned int cleaf_get_leafcore_minor(){
		return CLEAFCORE_LEAFCORE_MINOR;
	}

	unsigned int cleaf_get_leafcore_patch(){
		return CLEAFCORE_LEAFCORE_PATCH;
	}

	void cleaf_init(enum loglevel level){
		hlog = new Log::Log((Log::level)level);
		hlog->setFeature(Log::FEATURE_PRINTFUNNAMES, false);
		FUN();
		LOGU("[cleaf] Built against leafcore at version " CLEAFCORE_LEAFCORE_VERSION " (" CLEAFCORE_LEAFCORE_CODENAME ")");
		_cleaf_initialized = true;
	}

	void cleaf_setLogLevel(enum loglevel level){
		if(_cleaf_initialized)
			hlog->setLevel((Log::level)level);
	}

}
