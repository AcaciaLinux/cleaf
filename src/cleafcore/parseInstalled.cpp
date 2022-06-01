#include "log.h"
#include "cleafcore.h"

#include <leafcore/leafcore.h>
#include <leafcore/error.h>

#include <deque>
#include <string>

extern "C" {

	int cleafcore_parseInstalled(void* cleafcore){
		FUN();
		Leafcore* leaf = (Leafcore*) cleafcore;

		try {
			leaf->parseInstalled();
		} catch (LeafError* e){
			LOGUE("Parsing installed files failed: " + e->what());
			return -1;
		}

		return 0;
	}

}
