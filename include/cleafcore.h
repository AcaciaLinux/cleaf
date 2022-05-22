#ifndef __CLEAF_LEAFCORE_H__
#define __CLEAF_LEAFCORE_H__

#ifdef __cplusplus
extern "C" {
#endif

void cleaf_init();

void* cleaf_new();

void cleaf_delete(void* leaf);

#ifdef __cplusplus
}
#endif

#endif