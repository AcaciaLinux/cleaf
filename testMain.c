//Compile: gcc testMain.c -lcleaf

#include <cleaf/cleaf.h>
#include <cleaf/cleafcore.h>

int main(){
	cleaf_init(LOGLEVEL_A);

	void* leaf = cleafcore_new();

	cleafcore_a_update(leaf);
}
