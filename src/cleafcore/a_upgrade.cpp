#include "log.h"
#include "cleafcore.h"
#include "leafcore_dist.h"

#include <leafcore/leafcore.h>
#include <leafcore/error.h>

#include <deque>
#include <string>

extern "C" {

	int cleafcore_a_upgrade(void* cleafcore, int countPackages, char** c_packages){
		FUN();
	
		#if CLEAFCORE_LEAFCORE_MINOR >= 2
			Leafcore* leaf = (Leafcore*) cleafcore;
			LOGAPI("[cleaf] Got " + std::to_string(countPackages) + " packages to change");

			std::deque<std::string> packages;

			for (int i = 0; i < countPackages; i++){
				packages.push_back(std::string(c_packages[i]));
				LOGAPI("[cleaf] Got package \"" + packages.back() + "\" at index " + std::to_string(i));
			}

			try{
				leaf->a_upgrade(packages);
			} catch (LeafError* e){
				LOGUE("Change failed: " + e->what());
				return e->getErrorCode();
			}

			return 0;
		#else
			return e_feature_missing("a_upgrade", 0, 3);
		#endif
	}

}
