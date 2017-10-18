#ifndef _COMMAND_BASED_BATTLE_H_
#define _COMMAND_BASED_BATTLE_H_

#include "DLLImport.h"
#include "IBattle.h"
#include "IBattleCommandInvoker.h"

class SANDBOXLIB_API CommandBasedBattle : public IBattle
{
	IBattleCommandInvoker& commandSource;
public:
	CommandBasedBattle(IBattleCommandInvoker& _commandSource);

	virtual void process() throw (BattleException);
};

#endif
