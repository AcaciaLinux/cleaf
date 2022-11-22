/**
 * @file		leafcore_dist.h
 * @author		Max Kofler (kofler.max.dev@gmail.com)
 * @brief		A header for managing leaf compatibility
 * @copyright	Copyright (c) 2022
 */

#ifndef __CLEAF_LEAFCORE_DIST_H__
#define __CLEAF_LEAFCORE_DIST_H__

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


#endif
