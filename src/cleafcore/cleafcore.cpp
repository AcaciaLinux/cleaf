#include "cleafcore.h"
#include "log.h"

#define FRIEND_LEAFCORE
#include <leafcore/leafcore.h>
#include <leafcore/error.h>
#include <leafcore/leafconfig.h>

extern "C" {

	void* cleafcore_new(){
		FUN();
		return new Leafcore();
	}

	void cleafcore_delete(void* cleaf){
		FUN();
		delete (Leafcore*) cleaf;
	}

	int cleafcore_a_update(void* cleaf){
		Leafcore* leaf = (Leafcore*)cleaf;
		try{
			leaf->a_update();
		} catch (LeafError* e){
			LOGUE("Update failed: " + e->what());
			return e->getErrorCode();
		}
		return 0;
	}

}