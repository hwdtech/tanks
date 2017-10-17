#ifndef _IBATTLE_H_
#define _IBATTLE_H_

#include "BattleException.h"
#include "DLLImport.H"

class SANDBOXLIB_API IBattle
{
public:
	virtual void process() throw(BattleException) = 0;
};

#endif
