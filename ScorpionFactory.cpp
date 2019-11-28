#include "ScorpionFactory.h"
#include "Scorpion.h"
#include "CritterManager.h"
#include "ScoreManager.h"

ScorpionFactory* ScorpionFactory::InstancePtr = nullptr;
Scorpion* ScorpionFactory::privateCreateScorpion()
{
	Scorpion* ScorpionPtr = myScorpionPool.getScorpion();


	ScorpionPtr->SetExternalManagement(RecycleScorpion);



	ScorpionPtr->Initialize();
	CritterManager::SendCritterPointer(ScorpionPtr);
	return ScorpionPtr;
}
void ScorpionFactory::privateInitialize()
{
	pSound = SoundManager::GetSoundCommand(SoundManager::SoundLoopStartEvents::ScorpionSoundStrt);
	pScore = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::ScorpionKilled);
}
void ScorpionFactory::privateReportSound()
{
	SoundManager::SendSoundCommand((CommandSoundPlay*)pSound);
	SoundManager::ProcessSounds();
}
void ScorpionFactory::privatePauseSound()
{
	SoundManager::SendPauseCommand(pSound);
	SoundManager::PauseSounds();
}
void ScorpionFactory::privateReportDeath()
{
	ScoreManager::SendScoreCmd(pScore);
}
void ScorpionFactory::privateRecycleScorpion(GameObject* f)
{
	myScorpionPool.ReturnScorpion(static_cast<Scorpion*>(f));
}
void ScorpionFactory::privateTerminate()
{
	
	
	delete InstancePtr;
	InstancePtr = nullptr;
}
