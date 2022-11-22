//Compile: gcc testMain.c -lcleaf

#include <cleaf/cleaf.h>
#include <cleaf/cleafcore.h>
#include <cleaf/cleafconfig.h>

#include <malloc.h>
#include <string.h>

int main(){
	cleaf_init(LOGLEVEL_U);
	void* leaf = cleafcore_new();

	cleafconfig_setRootDir(leaf, "./root/");

	cleafconfig_setBoolConfig(leaf, CLEAF_B_CONFIG_NOASK, 1);	

	if (cleafcore_a_update(leaf) != 0)
		goto fail;

	char* packages[] = {
		"base"
	};

	cleafcore_readDefaultPackageList(leaf);

	if (cleafcore_a_install(leaf, 1, packages) != 0)
		goto fail;
	
	return 0;

fail:
	cleafcore_delete(leaf);
	return -1;

}
