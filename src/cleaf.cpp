#include "cleafcore.h"

#include <leafcore.h>

#include <iostream>

extern "C" {

	void* leaf_new(){
		return new Leafcore();
	}

}