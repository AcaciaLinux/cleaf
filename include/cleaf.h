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

#ifdef __cplusplus
}
#endif

#endif
