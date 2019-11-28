
#ifndef _CommandSoundLoop
#define _CommandSoundLoop

#include "CommandSoundPlay.h"

class CommandSoundLoop : public CommandSoundPlay
{
public:
	CommandSoundLoop() = delete;
	~CommandSoundLoop() = default;
	CommandSoundLoop(sf::Sound& snd);

	virtual void Execute() override;
	virtual void Pause();

private:
	sf::Sound sound; // Sound
};

#endif _CommandSoundLoop
