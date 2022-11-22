/**
 * @file		
 * @author		Max Kofler (kofler.max.dev@gmail.com)
 * @brief		The implementation of 
 * @copyright	Copyright (c) 2022
 */
#include "log.h"

#include "leafcore_dist.h"

int e_feature_missing(const char* f_name, unsigned int required_major, unsigned int required_minor, unsigned int required_patch){
	FUN();

	LOGU("!!!!! [cleaf] !!!!!");
	LOGU("The used feature \"" + std::string(f_name) + "\" is unavailable in this version of leafcore: ");
	LOGU("It requires version " + std::to_string(required_major) + "." + std::to_string(required_minor) + "." + std::to_string(required_patch));
	LOGU("The current leafcore version is " LEAFCORE_VERSION);
	LOGU("!!!!! [cleaf] !!!!!");

	return -1;
}
