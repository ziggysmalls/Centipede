#ifndef _CommandSound
#define _CommandSound
#include "Game Components/TEAL/CommonElements.h"


class CommandSound 
{
public:
	CommandSound() = default;
	~CommandSound() = default;
	CommandSound(const CommandSound&) = delete;
	CommandSound& operator = (const CommandSound&) = delete;

	virtual void Execute() = 0;
	

};

#endif _CommandSound