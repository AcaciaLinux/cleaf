/**
 * @file		leafcore_dist/getSet.cpp
 * @author		Max Kofler (kofler.max.dev@gmail.com)
 * @brief		The implementation of leafcore_dist.h getter and setter
 * @copyright	Copyright (c) 2022
 */
#include "log.h"

#include "leafcore_dist.h"

extern "C" {
	int get_ec_feature_missing(){
		return EC_FEATURE_MISSING;
	}
}
