
#include "CritterManager.h"
#include "FleaFactory.h"
#include "ScorpionFactory.h"
#include "SpiderFactory.h"
#include "CentipedeHead.h"
#include "SpawnGrid.h"
#include "CentipedeHeadFactory.h"
#include "CentipedeBodyFactory.h"
#include "GridManager.h"
#include "PlayerManager.h"

CritterManager* CritterManager::InstancePtr = nullptr;

CritterManager::CritterManager()
{
	

	

};

CritterManager::~CritterManager()
{
	
	InstancePtr = nullptr;
}

void CritterManager::Update()
{
	privateSpawnFlea();
}

void CritterManager::LaunchWave()
{
	// launching all critters

	privateSpawnWholeCentipede(currentWave->CentipedeLength);
	privateSpawnSpider();
	privateSpawnScorpion();
}


void CritterManager::privateSpawnWholeCentipede(int s)
{
	for (int i = 0; i < s; i++)
	{
		if (head == nullptr)
		{
			head = CentipedeHeadFactory::CreateCentipedeHead();
			wholeCentipede.push_back(head);
			curr = head;
		
		}
		else
		{
			Centipede* body = CentipedeBodyFactory::CreateCentipedeBody();
			wholeCentipede.push_back(body);
			curr->setPrev(body);
			curr->getPrev()->setNext(curr);
			curr = curr->getPrev();
		}
	}
	head = nullptr;
	curr = nullptr;

	
}
void CritterManager::privateSendPointer(GameObject* object)
{
	Critters.push_back(object);
}
void CritterManager::privateWipeWave()
{
	// iterating through and destroying game objects wiping them for respawn
	while (Critters.size() != 0)
	{
		Critters.front()->MarkForDestroy();
		Critters.pop_front();
	}
	
	while (wholeCentipede.size() != 0)
	{
		wholeCentipede.front()->MarkForDestroy();
		wholeCentipede.pop_front();
	}
}
void CritterManager::privateSpawnFlea()
{
	// checks if the flea can be spawned based on the trigger value for the flea to spawn
	float temp = GridManager::ReturnMushrooms();
	if (currentWave->fleaIsOn == true && temp < currentWave->TriggerValue && isFleaSpawned == false)
	{
		fleaPtr = FleaFactory::CreateFlea();
		
		isFleaSpawned = true;
	}


}

void CritterManager::privateSpawnScorpion()
{
	// critter manager method used to call alarm and set the frequency for the scorpion
	if (currentWave->scorpionIsOn == true)
	{
		SetAlarm(0, currentWave->scorpionFrequency);
	}
}

void CritterManager::privateSpawnSpider()
{
	// critter manager method used to call alarm and set frequence for the spider
	if (currentWave->spiderIsOn == true)
	{
		SetAlarm(1, currentWave->spiderFrequency);
	}
}

void CritterManager::privateSpawnCentipedeHead()
{
	// method used to spawn random heads depending on the wave
	Centipede* centi =CentipedeHeadFactory::CreateCentipedeHead();
	wholeCentipede.push_back(centi);
	//wholeCentipede.push_back(centi);
}

void CritterManager::privateLoadData(WaveData* data)
{
	currentWave = data;
	// Spawn critters right after updating the wave settings
	LaunchWave();
}

void CritterManager::Alarm0()
{
	//creates the scorpion
	numScorpions++;
	ScorPtr = ScorpionFactory::CreateScorpion();

	
}

void CritterManager::Alarm1()
{
	// creates the spider
	numSpiders++;
	spiderPtr = SpiderFactory::CreateSpider();

}

void CritterManager::privateResetScorpion()
{
	// resets the scorpion
	numScorpions--;
	privateSpawnScorpion();
}
void CritterManager::privateResetFlea()
{
	// resets the flea
	isFleaSpawned = false;
}
void CritterManager::privateResetSpider()
{
	numSpiders--;
	privateSpawnSpider();
}

void CritterManager::privHeadDestroyed(Centipede* pHead)
{
 	numCtpHeads--;
	wholeCentipede.remove(pHead);
	if (wholeCentipede.size() == 0)
	{
		PlayerManager::UpdateCurrentPlayerWave();
	}

}
void CritterManager::privateBodyDestroyed(Centipede* pBody)
{
	wholeCentipede.remove(pBody);
}
void CritterManager::privateCritterDestroyed(GameObject* object)
{
	Critters.remove(object);
}

void CritterManager::privateResetCentipede()
{
	privateSpawnWholeCentipede(currentWave->CentipedeLength);
}
void CritterManager::privHeadCreated(Centipede* pHead)
{
	wholeCentipede.push_front(pHead);
}
void CritterManager::privHeadCreated()
{
	numCtpHeads++;
}
void CritterManager::privateResetWave()
{
	privateWipeWave();
	LaunchWave();
}
void CritterManager::Destroy()
{

}

void CritterManager::Terminate()
{
	

}
