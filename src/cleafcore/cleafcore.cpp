#include "cleafcore.h"
#include "log.h"

#include <leafcore/leafcore.h>

extern "C" {

	void* cleafcore_new(){
		FUN();
		return new Leafcore();
	}

	void cleafcore_delete(void* leaf){
		FUN();
		delete (Leafcore*) leaf;
	}

}