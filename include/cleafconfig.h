#ifndef __CLEAF_LEAFCONFIG_H__
#define __CLEAF_LEAFCONFIG_H__

#ifdef __cplusplus
extern "C" {
#endif

	/**
	 * @brief	Sets the root leaf deploys its packages to
	 * @param	rootDir				The directory to work on
	 */
	void		cleafconfig_setRootDir(const char* rootDir);

#ifdef __cplusplus
}
#endif

#endif
