#ifndef __CLEAF_LEAFCONFIG_H__
#define __CLEAF_LEAFCONFIG_H__

enum cleaf_config_redownload{
	CLEAF_CONFIG_REDOWNLOAD_NONE = 0,
	CLEAF_CONFIG_REDOWNLOAD_SPECIFIED = 1,
	CLEAF_CONFIG_REDOWNLOAD_ALL = 2
};

enum cleaf_bool_config{
	CLEAF_B_CONFIG_NOASK,
	CLEAF_B_CONFIG_FORCEOVERWRITE,
	CLEAF_B_CONFIG_RUNPREINSTALL,
	CLEAF_B_CONFIG_RUNPOSTINSTALL
};

enum cleaf_string_config{
	CLEAF_S_ROOTDIR,
	CLEAF_S_CACHEDIR,
	CLEAF_S_DOWNLOADDIR,
	CLEAF_S_PACKAGESDIR,
	CLEAF_S_CONFIGDIR,
	CLEAF_S_INSTALLEDDIR,
	CLEAF_S_PKGLISTPATH
};

#ifdef __cplusplus
extern "C" {
#endif

	/**
	 * @brief	Sets the root leaf deploys its packages to
	 * @param	rootDir				The directory to work on
	 */
	void		cleafconfig_setRootDir(const char* rootDir);

	/**
	 * @brief	Adjusts leafs redownload behaviour
	 * @param	redownload			The desired behaviour
	 */
	void		cleafconfig_setRedownload(enum cleaf_config_redownload redownload);

	/**
	 * @brief	Sets a boolean leaf config
	 * @param	config				The desired config to modify
	 * @param	option				0 for false, >= 1 for true
	 */
	void		cleafconfig_setBoolConfig(enum cleaf_bool_config config, int option);

	/**
	 * @brief	Gets a boolean leaf config
	 * @param	config				The desired config to query
	 * @return	int					0 for false, 1 for true
	 */
	int			cleafconfig_getBoolConfig(enum cleaf_bool_config config);

	/**
	 * @brief	Gets a string leaf config
	 * @param	config				The desired config to query
	 * @return	char*				A pointer to the string, use free() when finished usage!
	 */
	char*		cleafconfig_getStringConfig(enum cleaf_string_config config);

#ifdef __cplusplus
}
#endif

#endif
