#include "CommandSoundPlay.h"
#include "SoundManager.h" 

CommandSoundPlay::CommandSoundPlay(sf::Sound& snd)
	:sound(snd)
{
}

void CommandSoundPlay::Execute()
{
	SoundManager::PlaySound(sound);
}

void CommandSoundPlay::Pause()
{
	SoundManager::StopSound(sound);
}