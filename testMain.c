//Compile: gcc testMain.c -lleafcore

#include <cleaf/cleafcore.h>

int main(){
	cleaf_init();

	void* leaf = cleaf_new();

	cleaf_delete(leaf);
}