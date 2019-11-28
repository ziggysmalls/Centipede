#include "PoisonMushroomFactory.h"
#include "ScoreManager.h"
#include "Game Components/TEAL/CommonElements.h"


PoisonMushroomFactory* PoisonMushroomFactory::InstancePtr = nullptr;
PoisonMushroom* PoisonMushroomFactory::privateCreatePoisonMushroom(float xPosition, float yPosition, int previousHealth)
{
	PoisonMushroom* mushPtr = myPoisonMushroomPool.getPoisonMushroom();


	mushPtr->SetExternalManagement(RecycleMushroom);



	mushPtr->Initialize(xPosition, yPosition, previousHealth);

	return mushPtr;
}
void PoisonMushroomFactory::privateInitialize()
{
	pScore = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::MushroomPoisonKilled);
}
void PoisonMushroomFactory::privateReportDeath()
{
	ScoreManager::SendScoreCmd(pScore);
}
void PoisonMushroomFactory::privateRecyclePoisonMushroom(GameObject* mushroom)
{
	myPoisonMushroomPool.ReturnPoisonMushroom(static_cast<PoisonMushroom*>(mushroom));
}

void PoisonMushroomFactory::privateTerminate()
{
	
	delete InstancePtr;
	InstancePtr = nullptr;
}
