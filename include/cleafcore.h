#ifndef __CLEAF_LEAFCORE_H__
#define __CLEAF_LEAFCORE_H__

#include "cleafconfig.h"

#ifdef __cplusplus
extern "C" {
#endif

	/**
	 * @brief	Creates a new leafcore instance
	 */
	void* 		cleafcore_new();

	/**
	 * @brief	Removes the supplied leafcore instance
	 */
	void 		cleafcore_delete(void* leaf);

	/**
	 * @brief	Reads the package list at the supplied path
	 * @param	leaf				The leaf instance to work with
	 * @param	path				The path to the package list
	 * @return	int					0, else the leaf error code
	 */
	int			cleafcore_readPackageList(void* leaf, char* path);

	/**
	 * @brief	Reads the package list at its path in the leafconfig
	 * @param	leaf				The leaf instance to work with
	 * @return	int					0, else the leaf error code
	 */
	int			cleafcore_readDefaultPackageList(void* leaf);

	/**
	 * @brief	Parses all the installed packages to determine which packages are already installed on the systems
	 * @param	leaf				The leaf instance to work with
	 * @return	int					0, else the leaf error code
	 */
	int			cleafcore_parseInstalled(void* leaf);

	/**
	 * @brief	Updates the local package list
	 * @param	leaf				The leaf instance to work with
	 * @return	int					0, else the leaf error code
	 */
	int 		cleafcore_a_update(void* leaf);

	/**
	 * @brief	Installs the supplied packages to the root
	 * @param	leaf				The leaf instance to work with
	 * @param	countPackages		The amount of packages to process
	 * @param	packages			A char string array containg the package names
	 * @return	int					0, else the leaf error code
	 */
	int 		cleafcore_a_install(void* leaf, int countPackages, char** packages);

#ifdef __cplusplus
}
#endif

#endif
