#ifndef _HANDLED_EXCEPTION_H_
#define _HANDLED_EXCEPTION_H_

#include "DLLImport.h"
#include "ExceptionHandler.h"

class SANDBOXLIB_API HandledException
{
public:
	virtual void handle(ExceptionHandler const& handler = []() {}) throw();
};

#endif
