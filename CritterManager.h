#ifndef _CritterManager
#define _CritterManager

#include "Game Components/TEAL/CommonElements.h"
#include "CentipedeHead.h"
#include "Spider.h"
#include "Scorpion.h"
#include "WaveManager.h"
#include <queue>


class CritterManager : public GameObject
{
private:
	static CritterManager* InstancePtr;					

	CritterManager();
	~CritterManager();
	CritterManager(const CritterManager&) = delete;
	CritterManager& operator=(const CritterManager&) = delete;

	static CritterManager& Instance()					// Access reference (all public methods will be static)
	{
		if (!InstancePtr)
			InstancePtr = new CritterManager();
		return *InstancePtr;
	};

	virtual void Update();
	virtual void Destroy();
	void privateSendPointer(GameObject* object);
	void privateSpawnFlea();
	void privateSpawnSpider();
	void privateSpawnScorpion();
	void privateSpawnWholeCentipede(int s);
	void privateSpawnCentipedeHead();
	void privateLoadData(WaveData* data);
	void privHeadCreated(Centipede* pHead);
	void privHeadCreated();
	void LaunchWave();
	void privateResetCentipede();
	void privateResetSpider();
	void privateResetScorpion();
	void privateResetFlea();
	void privateBodyDestroyed(Centipede* pBody);
	void privHeadDestroyed(Centipede* pHead);
	void privateCritterDestroyed(GameObject* object);
	void privateWipeWave();
	void privateResetWave();
	int numCtpHeads = 0;
	int numSpiders = 0;
	int numScorpions = 0;
	
	
	WaveData* currentWave = nullptr;
	Spider* spiderPtr = nullptr;
	Flea* fleaPtr = nullptr;
	Scorpion* ScorPtr = nullptr;
	Centipede* head = nullptr;
	Centipede* curr = nullptr;
	std::list<Centipede*> wholeCentipede;
	std::list<GameObject*> Critters;
	// used to make sure only 1 instance of the flea is spawned
	bool isFleaSpawned = false;
	int minimumMushrooms;
	virtual void Alarm0();
	virtual void Alarm1();

public:
	static void SpawnWholeCentipede(int s) { Instance().privateSpawnWholeCentipede(s); };
	static void SpawnFlea() { Instance().privateSpawnFlea(); };
	static void SendCritterPointer(GameObject* object) { Instance().privateSendPointer(object); };
	static void LoadWaveData(WaveData* data) { Instance().privateLoadData(data); };
	static void ResetSpider() { Instance().privateResetSpider(); };
	static void ResetFlea() { Instance().privateResetFlea(); };
	static void ResetScorpion() { Instance().privateResetScorpion(); };
	static void ResetCentipede() { Instance().privateResetCentipede(); };
	static void HeadDestroyed(Centipede* pHead) { Instance().privHeadDestroyed(pHead); };
	static void BodyDestroyed(Centipede* pBody) { Instance().privateBodyDestroyed(pBody); };
	static void CritterDestroyed(GameObject* object) { Instance().privateCritterDestroyed(object); };
	static void HeadCreated(Centipede* pHead) { Instance().privHeadCreated(pHead); };
	static void HeadCreated() { Instance().privHeadCreated(); };
	static void WipeWave() { Instance().privateWipeWave(); };
	static void ResetWave() { Instance().privateResetWave(); };
	static void Terminate();


};

#endif _CritterManager
