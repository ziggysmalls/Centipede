#ifndef _CommandSoundPlay
#define _CommandSoundPlay

#include "CommandSound.h"

class CommandSoundPlay : public CommandSound
{
public:
	CommandSoundPlay() = delete;
	~CommandSoundPlay() = default;
	CommandSoundPlay(sf::Sound& snd);

	virtual void Execute() override;
	virtual void Pause();

protected:
	sf::Sound sound; // Sound
};

#endif _CommandSound

