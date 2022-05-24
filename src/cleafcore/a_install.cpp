#include "log.h"
#include "cleafcore.h"

#include <leafcore/leafcore.h>
#include <leafcore/error.h>

#include <deque>
#include <string>

extern "C" {

	int cleafcore_a_install(void* cleafcore, int countPackages, char** c_packages){
		FUN();
		Leafcore* leaf = (Leafcore*) cleafcore;
		LOGD("Got " + std::to_string(countPackages) + " packages to install");

		std::deque<std::string> packages;

		for (int i = 0; i < countPackages; i++){
			packages.push_back(std::string(c_packages[i]));
			LOGD("Got package \"" + packages.back() + "\" at index " + std::to_string(i));
		}

		try{
			leaf->a_install(packages);
		} catch (LeafError* e){
			LOGUE("Install failed: " + e->what());
			return -1;
		}

		return 0;

	}

}