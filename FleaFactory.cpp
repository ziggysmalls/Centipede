#include "FleaFactory.h"
#include "Flea.h"
#include "CritterManager.h"

FleaFactory* FleaFactory::InstancePtr = nullptr;
Flea* FleaFactory::privateCreateFlea()
{
	Flea* FleaPtr = myFleaPool.getFlea();


	FleaPtr->SetExternalManagement(RecycleFlea);



	FleaPtr->Initialize();
	CritterManager::SendCritterPointer(FleaPtr);
	return FleaPtr;
}
void FleaFactory::privateInitialize()
{
	pSound = SoundManager::GetSoundCommand(SoundManager::SoundEvents::FleaSound);
	pScore = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::FleaKilled);

}
void FleaFactory::privateProccessSound()
{
	SoundManager::SendSoundCommand(pSound);
	SoundManager::ProcessSounds();
}
void FleaFactory::privateReportDeath()
{
	ScoreManager::SendScoreCmd(pScore);
}
void FleaFactory::privateRecycleFlea(GameObject* f)
{
	myFleaPool.ReturnFlea(static_cast<Flea*>(f));
}
void FleaFactory::privateTerminate()
{
	
	
	delete InstancePtr;
	InstancePtr = nullptr;
}
