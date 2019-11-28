#include "SpiderFactory.h"
#include "Spider.h"
#include "CritterManager.h"
#include "ScoreManager.h"

SpiderFactory* SpiderFactory::InstancePtr = nullptr;

Spider* SpiderFactory::privateCreateSpider()
{
	Spider* SpiderPtr = mySpiderPool.getSpider();
	
	SpiderPtr->SetExternalManagement(RecycleSpider);

	SpiderPtr->Initialize();
	CritterManager::SendCritterPointer(SpiderPtr);
	return SpiderPtr;
}
void SpiderFactory::privateInitialize()
{

		pSound = SoundManager::GetSoundCommand(SoundManager::SoundLoopStartEvents::SpiderSoundStrt);
		pScore = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::SpiderKilled);
}
void SpiderFactory::privateReportSound()
{
	SoundManager::SendSoundCommand((CommandSoundPlay*)pSound);
	SoundManager::ProcessSounds();
}
void SpiderFactory::privateReportDeath()
{
	ScoreManager::SendScoreCmd(pScore);
}
void SpiderFactory::privatePauseSound()
{
	SoundManager::SendPauseCommand(pSound);
	SoundManager::PauseSounds();
}
void SpiderFactory::privateRecycleSpider(GameObject* f)
{
	mySpiderPool.ReturnSpider(static_cast<Spider*>(f));
}
void SpiderFactory::privateTerminate()
{
	
	
	delete InstancePtr;
	InstancePtr = nullptr;
}
