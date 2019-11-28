#ifndef _SoundManager
#define _SoundManager

#include "Game Components\TEAL\CommonElements.h"
#include <queue>

// Forward Declarations
class CommandSoundPlay;
class CommandSoundLoop;
class SoundManager
{
public:
	
	// Sound Events
	enum class SoundEvents { FleaSound, FireSound, PlayerDeathSound, MushRegenSound };
	enum class SoundLoopStartEvents { CentipedeSoundStrt, ScorpionSoundStrt, SpiderSoundStrt };

	static void PlaySound(sf::Sound& snd);
	static void StopSound(sf::Sound& snd);

	static CommandSoundPlay* GetSoundCommand(SoundEvents event) {return Instance().privateGetSoundCommand(event); };
	static CommandSoundLoop* GetSoundCommand(SoundLoopStartEvents event) { return Instance().privateGetSoundLoopCommand(event); };

	static void SendSoundCommand(CommandSoundPlay* command);
	
	
	static void SendPauseCommand(CommandSoundLoop* command);

	static void ProcessSounds(){Instance().privateProcessSound();}
	static void PauseSounds() {Instance().privatePauseSound();};
	static void Terminate() { Instance().privateTerminate(); };

private:
	~SoundManager();
	SoundManager();
	float PITCH = 1;
	float VOL = 4;
	float VOL2 = 2;

	// Sounds
	sf::Sound CentipedeBeat;
	sf::Sound ScorpionBeat;
	sf::Sound SpiderBeat;
	

	sf::Sound FleaSnd;
	sf::Sound FireSnd;
	sf::Sound PlayerDeathSnd;
	sf::Sound MushRegenSnd;

	std::queue<CommandSoundPlay*> QueueSoundPlayCommand;
	
	std::queue<CommandSoundPlay*> QueueSoundPauseCommand;
	CommandSoundPlay* FleaSound;
	CommandSoundLoop* centipedeSound;
	CommandSoundLoop* SpiderSound;
	CommandSoundPlay* BulletSound;
	CommandSoundLoop* ScorpionSound;
	
	static SoundManager* InstancePtr;

	static SoundManager& Instance()	// Access reference (all public methods will be static)
	{
		if (!InstancePtr)
			InstancePtr = new SoundManager;
		return *InstancePtr;
	};

	void privateProcessSound();
	void privateTerminate();
	CommandSoundPlay* privateGetSoundCommand(SoundEvents event);
	CommandSoundLoop* privateGetSoundLoopCommand(SoundLoopStartEvents event);
	void privatePauseSound();
	
};

#endif _SoundManager