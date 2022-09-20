#include "log.h"
#include "cleafcore.h"

#include <leafcore/leafcore.h>
#include <leafcore/error.h>

extern "C" {

	int cleafcore_readPackageList(void* cleaf, char* path){
		FUN();
		Leafcore* leaf = (Leafcore*) cleaf;

		try{
			leaf->parsePackageList(std::string(path));
		} catch (LeafError* e){
			LOGUE("Parsing package list failed: " + e->what());
			return e->getErrorCode();
		}

		return 0;
	}

	int cleafcore_readDefaultPackageList(void* cleaf){
		FUN();
		Leafcore* leaf = (Leafcore*) cleaf;

		try{
			leaf->parsePackageList();
		} catch (LeafError* e){
			LOGUE("Parsing package list failed: " + e->what());
			return -1;
		}

		return 0;
	}

}
