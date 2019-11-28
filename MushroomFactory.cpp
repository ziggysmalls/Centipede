#include "MushroomFactory.h"
#include "Mushroom.h"
#include "Game Components/TEAL/CommonElements.h"
#include "ScoreManager.h"

MushroomFactory* MushroomFactory::InstancePtr = nullptr;
Mushroom* MushroomFactory::privateCreateMushroom(float xPosition, float yPosition)
{
	Mushroom* mushPtr = myMushroomPool.getMushroom();

	mushPtr->SetExternalManagement(RecycleMushroom);
	
	mushPtr->Initialize(xPosition, yPosition);
	
	return mushPtr;
}

void MushroomFactory::privateRecycleMushroom(GameObject* mushroom)
{
	myMushroomPool.ReturnMushroom(static_cast<Mushroom*>(mushroom));
}
void MushroomFactory::privateInitialize()
{
	pScore = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::MushroomKilled);
}
void MushroomFactory::privateReportDeath()
{
	ScoreManager::SendScoreCmd(pScore);
}
void MushroomFactory::privateTerminate()
{
	
	delete InstancePtr;
	InstancePtr = nullptr;
}
