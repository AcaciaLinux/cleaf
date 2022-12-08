/**
 * @file		cleaf/cleaf.cpp
 * @author		Max Kofler (kofler.max.dev@gmail.com)
 * @brief		The implementation of the cleaf.h header
 * @copyright	Copyright (c) 2022
 */
#include "cleaf.h"
#include "leafcore_dist.h"

#include "log.h"

bool _cleaf_initialized = false;

#include <cstring>
#include <iostream>
#include <sstream>
std::stringstream _ss_log;

extern "C"{

	unsigned int cleaf_get_leafcore_major(){
		return CLEAFCORE_LEAFCORE_MAJOR;
	}

	unsigned int cleaf_get_leafcore_minor(){
		return CLEAFCORE_LEAFCORE_MINOR;
	}

	unsigned int cleaf_get_leafcore_patch(){
		return CLEAFCORE_LEAFCORE_PATCH;
	}

	void cleaf_init(enum loglevel level){
		hlog = new Log::Log();
		FUN();
		LOGU("[cleaf] Built against leafcore at version " CLEAFCORE_LEAFCORE_VERSION " (" CLEAFCORE_LEAFCORE_CODENAME ")");
		_cleaf_initialized = true;

		{	//Add the std::cout stream
			Log::stream_config c;
			c.loglevel = (Log::level)level;
			c.print_function_names = false;
			hlog->addStream(std::cout, c);
		}

		{
			Log::stream_config c;
			c.loglevel = Log::I;
			c.print_function_names = false;
			hlog->addStream(_ss_log, c);
		}
	}

	void cleaf_setLogLevel(enum loglevel level){
		if(_cleaf_initialized){
			Log::stream_config* c = hlog->getStreamConf(std::cout);
			if (c == nullptr){
				LOGUE("[cleaf] Failed to retrieve stream! (This is a bug)");
				return;
			}

			c->loglevel = (Log::level)level;
		}
	}

	char* cleaf_get_log(){
		#if LEAFCORE_V_MINOR > 2 || LEAFCORE_V_MINOR == 2 && LEAFCORE_V_PATCH >= 2
			std::string curLog = _ss_log.str();
			char* res = (char*)std::malloc(curLog.length() + 1);
			std::strcpy(res, curLog.c_str());
			return res;
		#else
			e_feature_missing("Log with streams", 0, 2, 2);
			return NULL;
		#endif
	}

	void cleaf_delete_log(char* log){
		std::free(log);
	}

	void cleaf_clear_log(){
		_ss_log.str("");
	}

}
