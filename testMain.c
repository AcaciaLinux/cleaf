//Compile: gcc testMain.c -lcleaf

#include <cleaf/cleaf.h>
#include <cleaf/cleafcore.h>
#include <cleaf/cleafconfig.h>

#include <malloc.h>
#include <string.h>

int main(){
	cleaf_init(LOGLEVEL_A);

	cleafconfig_setRootDir("./root/");

	void* leaf = cleafcore_new();

	if (cleafcore_a_update(leaf) != 0)
		goto fail;

	char* packages[] = {
		"base"
	};

	printf("Strlen: %i\n", strlen(packages[0]));

	cleafcore_readDefaultPackageList(leaf);

	if (cleafcore_a_install(leaf, 1, packages) != 0)
		goto fail;

	return 0;

fail:
	cleafcore_delete(leaf);
	return -1;

}
