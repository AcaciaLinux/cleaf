#include "cleaf.h"

#include "log.h"

bool _cleaf_initialized = false;

extern "C"{

	void cleaf_init(enum loglevel level){
		hlog = new Log::Log((Log::level)level);
		FUN();
		_cleaf_initialized = true;
	}

	void cleaf_setLogLevel(enum loglevel level){
		if(_cleaf_initialized)
			hlog->setLevel((Log::level)level);
	}

}
