#ifndef _SpiderFactory
#define _SpiderFactory

#include "Game Components/TEAL/CommonElements.h"
// Forward Declaration
#include "Spider.h"
#include "SpiderObjectPool.h"
#include "SoundManager.h"
#include "CommandSoundLoop.h"
class GameObject;
class CmdScore;
class SpiderFactory
{
private:

	SpiderObjectPool mySpiderPool;
	static SpiderFactory* InstancePtr;
	SpiderFactory() = default;
	SpiderFactory(const SpiderFactory&) = delete;
	SpiderFactory& operator =(const SpiderFactory&) = delete;
	~SpiderFactory() = default;
	static SpiderFactory& Instance()
	{
		if (!InstancePtr)
			InstancePtr = new SpiderFactory();
		return *InstancePtr;
	};

	Spider* privateCreateSpider();
	void privateReportSound();
	void privateReportDeath();
	void privatePauseSound();
	void privateInitialize();
	void privateTerminate();
	void privateRecycleSpider(GameObject* m);
	CommandSoundLoop* pSound;
	CmdScore* pScore;
public:
	
	static Spider* CreateSpider() { return Instance().privateCreateSpider(); };
	static void RecycleSpider(GameObject* m) { Instance().privateRecycleSpider(m); };
	static void ReportSound() { Instance().privateReportSound(); };
	static void ReportDeath() { Instance().privateReportDeath(); };
	static void PauseSound() { Instance().privatePauseSound(); };
	static void Initialize() { Instance().privateInitialize(); };
	static void Terminate() { Instance().privateTerminate(); };
};
#endif

