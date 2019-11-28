#include "CommandSoundLoop.h"
#include "SoundManager.h"

CommandSoundLoop::CommandSoundLoop(sf::Sound& snd)
	: CommandSoundPlay(snd)
{

}

void CommandSoundLoop::Execute()
{
	CommandSoundPlay::Execute();
}

void CommandSoundLoop::Pause()
{
	CommandSoundPlay::Pause();
}