//Compile: gcc testMain.c -lcleaf

#include <cleaf/cleaf.h>
#include <cleaf/cleafcore.h>
#include <cleaf/cleafconfig.h>

#include <malloc.h>
#include <string.h>

int main(){
	cleaf_init(LOGLEVEL_API);
	void* leaf = cleafcore_new();

	cleafconfig_setRootDir(leaf, "./root/");

	cleafconfig_setBoolConfig(leaf, CLEAF_B_CONFIG_NOASK, 1);
	cleafconfig_setBoolConfig(leaf, CLEAF_B_CONFIG_NOPROGRESS, 0);
	cleafconfig_setBoolConfig(leaf, CLEAF_B_CONFIG_FORCE, 0);

	cleafconfig_setStringConfig(leaf, CLEAF_S_PKGLISTURL, "https://api.acacialinux.org/?get=packagelist");

	if (cleafcore_a_update(leaf) != 0)
		goto fail;

	char* packages[] = {
		"base"
	};

	cleafcore_readDefaultPackageList(leaf);

	if (cleafcore_a_install(leaf, 1, packages) != 0)
		goto fail;

	cleafcore_a_upgrade(leaf, 0, NULL);

	char* log = cleaf_get_log();
	printf("\n\n");
	printf("---------- LEAF VERBOSE LOG ----------\n%s", log);
	printf("-------- END LEAF VERBOSE LOG --------\n");
	cleaf_delete_log(log);
	
	return 0;

fail:
	cleafcore_delete(leaf);
	return -1;

}
