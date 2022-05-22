#ifndef __CLEAF_LEAFCORE_H__
#define __CLEAF_LEAFCORE_H__

#ifdef __cplusplus
extern "C" {
#endif

	/**
	 * @brief	Creates a new leafcore instance
	 */
	void* cleafcore_new();

	/**
	 * @brief	Removes the supplied leafcore instance
	 */
	void cleafcore_delete(void* leaf);

#ifdef __cplusplus
}
#endif

#endif
