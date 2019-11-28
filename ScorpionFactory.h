#ifndef _ScorpionFactory
#define _ScorpionFactory

#include "Game Components/TEAL/CommonElements.h"
// Forward Declaration
#include "Scorpion.h"
#include "ScorpionObjectPool.h"
#include "SoundManager.h"
#include "CommandSoundLoop.h"
class GameObject;
class CmdScore;
class ScorpionFactory
{
private:

	
	static ScorpionFactory* InstancePtr;
	ScorpionFactory() =default;
	ScorpionFactory(const ScorpionFactory&) = delete;
	ScorpionFactory& operator =(const ScorpionFactory&) = delete;
	~ScorpionFactory() {};
	static ScorpionFactory& Instance()
	{
		if (!InstancePtr)
			InstancePtr = new ScorpionFactory();
		return *InstancePtr;
	};

	ScorpionObjectPool myScorpionPool;

	void privateInitialize();
	Scorpion* privateCreateScorpion();
	void privateTerminate();
	void privateRecycleScorpion(GameObject* s);
	void privateReportSound();
	void privatePauseSound();
	void privateReportDeath();
	CommandSoundLoop* pSound;
	CmdScore* pScore;

public:
	
	static Scorpion* CreateScorpion() {return Instance().privateCreateScorpion();};
	static void RecycleScorpion(GameObject* m) {Instance().privateRecycleScorpion(m);};
	static void Initialize() { Instance().privateInitialize(); };
	static void ReportSound() { Instance().privateReportSound(); };
	static void ReportDeath() { Instance().privateReportDeath(); };
	static void PauseSound() { Instance().privatePauseSound(); };
	static void Terminate() { Instance().privateTerminate(); };
};
#endif

