#include "cleafcore.h"
#include "log.h"

#include <leafcore/leafcore.h>

#include <iostream>

static bool _cleaf_initialized = false;

extern "C" {

	void cleaf_init(){
		hlog = new Log::Log(Log::A);
		_cleaf_initialized = true;
	}

	void* cleaf_new(){
		if (!_cleaf_initialized)
			return nullptr;
		return new Leafcore();
	}

	void cleaf_delete(void* leaf){
		delete (Leafcore*) leaf;
	}

}