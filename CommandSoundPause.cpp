#include "CommandSoundPause.h"
CommandSoundPause::CommandSoundPause(sf::Sound& snd)
	: CommandSoundLoop(snd)
{

}

void CommandSoundPause::Execute()
{
	CommandSoundLoop::Pause();
}