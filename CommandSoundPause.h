#ifndef _CommandSoundPause
#define _CommandSoundPause

#include "CommandSoundLoop.h"

class CommandSoundPause : public CommandSoundLoop
{
public:
	CommandSoundPause() = delete;
	~CommandSoundPause() = default;
	CommandSoundPause(sf::Sound& snd);

	virtual void Execute() override;

private:
	sf::Sound sound; // Sound
};

#endif _CommandSoundPause