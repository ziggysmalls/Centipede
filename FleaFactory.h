#ifndef _FleaFactory
#define _FleaFactory

#include "Game Components/TEAL/CommonElements.h"
// Forward Declaration
#include "Flea.h"
#include "FleaObjectPool.h"
#include  "SoundManager.h"
#include "CommandSoundPlay.h"

#include "ScoreManager.h"
class GameObject;
class CmdScore;
class FleaFactory
{
private:

	FleaObjectPool myFleaPool;
	static FleaFactory* InstancePtr;
	FleaFactory() {};
	FleaFactory(const FleaFactory&) {};
	FleaFactory& operator =(const FleaFactory&) {};
	~FleaFactory() {};
	static FleaFactory& Instance()
	{
		if (!InstancePtr)
			InstancePtr = new FleaFactory();
		return *InstancePtr;
	};
	void privateInitialize();
	void privateProccessSound();
	void privateReportDeath();
	Flea* privateCreateFlea();
	void privateTerminate();
	void privateRecycleFlea(GameObject* m);
	CommandSoundPlay* pSound;
	CmdScore* pScore;

public:
	static void Initialize() { Instance().privateInitialize(); };
	static void ProcessSound() { Instance().privateProccessSound(); };
	static void ReportDeath() { Instance().privateReportDeath(); };
	static Flea* CreateFlea() { return Instance().privateCreateFlea(); };
	static void RecycleFlea(GameObject* m) { Instance().privateRecycleFlea(m); };
	static void Terminate() {Instance().privateTerminate();};
};
#endif

