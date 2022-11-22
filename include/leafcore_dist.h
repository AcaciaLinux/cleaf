/**
 * @file		leafcore_dist.h
 * @author		Max Kofler (kofler.max.dev@gmail.com)
 * @brief		A header for managing leaf compatibility
 * @copyright	Copyright (c) 2022
 */

#include <climits>

#ifndef __CLEAF_LEAFCORE_DIST_H__
#define __CLEAF_LEAFCORE_DIST_H__

#define EC_FEATURE_MISSING INT_MIN

//Check if leafcore does have dist.h (from 0.2.0 on)
#if __has_include("leafcore/dist.h")
	#include "leafcore/dist.h"
	#define LEAFCORE_HAS_DIST_H 1
#endif

//If leafcore has dist.h, check if it defines the version numbers
#ifdef LEAFCORE_HAS_DIST_H
	#define CLEAFCORE_LEAFCORE_MAJOR LEAFCORE_V_MAYOR
	#define CLEAFCORE_LEAFCORE_MINOR LEAFCORE_V_MINOR
	#define CLEAFCORE_LEAFCORE_PATCH LEAFCORE_V_PATCH
	#define CLEAFCORE_LEAFCORE_VERSION LEAFCORE_VERSION
	#define CLEAFCORE_LEAFCORE_CODENAME LEAFCORE_CODENAME
#else
	#define CLEAFCORE_LEAFCORE_MAJOR 0
	#define CLEAFCORE_LEAFCORE_MINOR 1
	#define CLEAFCORE_LEAFCORE_PATCH 3
	#define CLEAFCORE_LEAFCORE_VERSION "<= 0.1.3"
	#define CLEAFCORE_LEAFCORE_CODENAME "UNKNOWN"
#endif

#ifdef __cplusplus
extern "C" {
#endif
	/**
	 * @brief	Displays an error explaining the feature is unavailable in the leafcore version used
	 * @param	f_name			The name of the feature
	 * @param	required_major	The required major version of leafcore for this feature
	 * @param	required_minor	The required minor version of leafcore for this feature
	 * @param	required_patch	The required patch version of leafcore for this feature (default = 0)
	 * @return	int				A negative return code (to use "return e_feature_missing()")
	 */
	int e_feature_missing(const char* f_name, unsigned int required_major, unsigned int required_minor, unsigned int required_patch = 0);

	/**
	 * @brief	Returns the error code that gets returned if a leafcore feature is missing
	 */
	int get_ec_feature_missing();
#ifdef __cplusplus
}
#endif

#endif
