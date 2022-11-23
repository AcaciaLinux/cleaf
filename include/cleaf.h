#ifndef __CLEAF_H__
#define __CLEAF_H__

#include "loglevels.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

	/**
	 * @brief	Reports the major version of leafcore
	 */
	unsigned int cleaf_get_leafcore_major();

	/**
	 * @brief	Reports the minor version of leafcore
	 */
	unsigned int cleaf_get_leafcore_minor();

	/**
	 * @brief	Reports the patch version of leafcore
	 */
	unsigned int cleaf_get_leafcore_patch();

	/**
	 * @brief	Initializes the cleaf runtime with some leaf dependencies such as the Log module
	 * @param	level			The loglevel to use
	 */
	void 						cleaf_init(enum loglevel level);

	/**
	 * @brief	Applies the supplied loglevel to the Log module
	 * @param	level			The loglevel to use
	 */
	void 						cleaf_setLogLevel(enum loglevel level);

	/**
	 * @brief	Returns a char* to the leaf log, delete it using cleaf_delete_log()
	 */
	char*						cleaf_get_log();

	/**
	 * @brief	Remove the memory allocated by cleaf_get_log()
	 */
	void						cleaf_delete_log(char*);

	/**
	 * @brief	Clears the internal log stringstream
	 */
	void						cleaf_clear_log();

#ifdef __cplusplus
}
#endif

#endif
