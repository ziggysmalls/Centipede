#ifndef _CmdScore
#define _CmdScore
#include "Game Components/TEAL/CommonElements.h"

class CmdScore
{
public:
	// Note: the Excecute method must NOT have _any_ paramters
	virtual void Execute() = 0;
};
#endif
