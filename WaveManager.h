#ifndef _WaveManager
#define _WaveManager
#include "SFML/Graphics.hpp"


struct WaveData
{
	//Centipede Settings
	int CentipedeLength;
	int	CentipedeSpeed;
	int headCount;
	int headSpeed;
	// Flea Settings
	bool fleaIsOn;
	int TriggerValue; 
	// Scorpion Settings
	bool scorpionIsOn;
	float scorpionFrequency; 
	// Spider Settings
	bool spiderIsOn;
	float spiderFrequency;  
	float spiderSpeed;
};

class GameObject;

class WaveManager
{
private:
	static WaveManager* InstancePtr;					// set up as a singleton

	WaveManager() = default;							
	WaveManager(const WaveManager&) = delete;			
	WaveManager& operator=(const WaveManager&) = delete;
	~WaveManager() = default;							

	static WaveManager& Instance()					// Access reference (all public methods will be static)
	{
		if (!InstancePtr)
			InstancePtr = new WaveManager();
		return *InstancePtr;
	};

	void privateInitializeWave();
	void privateInitializeWave(int w);
	void privateUpdateWave();
	void privateParseFile();
	int ind = 0;
	int wavesParsed;
	
	static const int waveSize = 8;  // # of waves
	WaveData waveArray[waveSize]{};

public:
	static void InitializeWave() { Instance().privateInitializeWave(); };
	static void InitializeWave(int w) { Instance().privateInitializeWave(w); };
	static void Terminate();
	static void UpdateWave() { Instance().privateUpdateWave(); };
	static void ParseFile() { Instance().privateParseFile(); };
	enum stringCode { Wave, CentipedeLength, CentipedeSpeed, HeadCount, HeadSpeed, FleaOn, TriggerValue, ScorpionOn, ScorpionFrequency, SpiderOn, SpiderFrequency, SpiderSpeed, empty };
	stringCode hash(std::string const& inString);
};

#endif _WaveManager

