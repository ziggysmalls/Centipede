#include "SoundManager.h"

#include "Game Components/TEAL/CommonElements.h"
#include "CommandSoundPlay.h"
#include "CommandSoundLoop.h"

SoundManager* SoundManager::InstancePtr = nullptr;

SoundManager::SoundManager()
{
	FireSnd.setBuffer(ResourceManager::GetSound("fire1"));
	FireSnd.setPitch(PITCH);
	FireSnd.setVolume(VOL2);

	CentipedeBeat.setBuffer(ResourceManager::GetSound("Beat"));
	CentipedeBeat.setPitch(PITCH);
	CentipedeBeat.setVolume(VOL);
	CentipedeBeat.setLoop(true);

	ScorpionBeat.setBuffer(ResourceManager::GetSound("scorpionNew"));
	ScorpionBeat.setPitch(PITCH);
	ScorpionBeat.setVolume(VOL);
	ScorpionBeat.setLoop(true);

	SpiderBeat.setBuffer(ResourceManager::GetSound("spiderNew"));
	SpiderBeat.setPitch(PITCH);
	SpiderBeat.setVolume(VOL);
	SpiderBeat.setLoop(true);

	FleaSnd.setBuffer(ResourceManager::GetSound("fleaNew"));
	FleaSnd.setPitch(PITCH);
	FleaSnd.setVolume(VOL);

	PlayerDeathSnd.setBuffer(ResourceManager::GetSound("Death"));
	PlayerDeathSnd.setPitch(PITCH);
	PlayerDeathSnd.setVolume(VOL);

	MushRegenSnd.setBuffer(ResourceManager::GetSound("Bonus"));
	MushRegenSnd.setPitch(PITCH);
	MushRegenSnd.setVolume(VOL);
	
		FleaSound = new CommandSoundPlay(FleaSnd);
		BulletSound = new CommandSoundPlay(FireSnd);
		

			centipedeSound = new CommandSoundLoop(CentipedeBeat);
			ScorpionSound = new CommandSoundLoop(ScorpionBeat);
			SpiderSound = new CommandSoundLoop(SpiderBeat);
		
}

CommandSoundPlay* SoundManager::privateGetSoundCommand(SoundEvents event)
{
	CommandSoundPlay* pCommand = nullptr;

	switch (event)
	{
	case SoundEvents::FleaSound:
		pCommand = FleaSound;
		break;
	case SoundEvents::FireSound:
		pCommand = BulletSound;
		break;
	
	default:
		assert(false);
		break;
	}
	
	return pCommand;
}

CommandSoundLoop* SoundManager::privateGetSoundLoopCommand(SoundLoopStartEvents event)
{
	CommandSoundLoop* pCommand = nullptr;

	switch (event)
	{
	case SoundLoopStartEvents::CentipedeSoundStrt:
		pCommand = centipedeSound;
		break;
	case SoundLoopStartEvents::ScorpionSoundStrt:
		pCommand = ScorpionSound;
		break;
	case SoundLoopStartEvents::SpiderSoundStrt:
		pCommand = SpiderSound;
		break;
	default:
		assert(false);
		break;
	}

	return pCommand;
}

void SoundManager::PlaySound(sf::Sound& snd)
{
	snd.play();
}

void SoundManager::StopSound(sf::Sound& snd)
{
	snd.stop();
}

void SoundManager::SendSoundCommand(CommandSoundPlay* command)
{
	Instance().QueueSoundPlayCommand.push(command);
}

void SoundManager::SendPauseCommand(CommandSoundLoop* command)
{
	Instance().QueueSoundPauseCommand.push(command);
}
SoundManager::~SoundManager()
{
	delete FleaSound;
	FleaSound = nullptr;
	delete BulletSound;
	BulletSound = nullptr;

	delete centipedeSound;
	centipedeSound = nullptr;
	delete ScorpionSound;
	ScorpionSound = nullptr;
	delete SpiderSound;
	SpiderSound = nullptr;
}



void SoundManager::privateProcessSound()
{
	CommandSoundPlay* pCommand;

	while (!QueueSoundPlayCommand.empty())
	{
		pCommand = QueueSoundPlayCommand.front();
		pCommand->Execute();

		QueueSoundPlayCommand.pop();
		
	}
}


void SoundManager::privatePauseSound()
{
	CommandSoundPlay* pCommand;

	while (!QueueSoundPauseCommand.empty())
	{
		pCommand = QueueSoundPauseCommand.front();
		pCommand->Pause();

		QueueSoundPauseCommand.pop();
	}
}

void SoundManager::privateTerminate()
{
	
	delete InstancePtr;
	InstancePtr = nullptr;
}