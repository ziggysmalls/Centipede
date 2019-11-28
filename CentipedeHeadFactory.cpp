#include "CentipedeHeadFactory.h"
#include "CentipedeHead.h"
#include "CentipedeHeadObjectPool.h"
#include "CentipedeBodyFactory.h"
#include "CritterManager.h"
#include "ScoreManager.h"

CentipedeHeadFactory* CentipedeHeadFactory::InstancePtr = nullptr;

CentipedeHead* CentipedeHeadFactory::privateCreateCentipedeHead()
{
	CentipedeHead* Ptr = myCentipedeHeadPool.getCentipedeHead();

	Ptr->SetExternalManagement(RecycleCentipedeHead);

	Ptr->Initialize();

	return Ptr;


}
void CentipedeHeadFactory::privateInitialize()
{
	pSound = SoundManager::GetSoundCommand(SoundManager::SoundLoopStartEvents::CentipedeSoundStrt);
	pScore = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::CentipedeHeadKilled);
}
CentipedeHead* CentipedeHeadFactory::privateCreateCentipedeHead(int r, int c, const MoveState* st)
{
	CentipedeHead* Ptr = myCentipedeHeadPool.getCentipedeHead();

	Ptr->SetExternalManagement(RecycleCentipedeHead);

	Ptr->Initialize(r,c,st);
	
	return Ptr;
}
CentipedeHead* CentipedeHeadFactory::privateCreateCentipedeHead(sf::Vector2f pos, const MoveState* st, int index)
{
	CentipedeHead* Ptr = myCentipedeHeadPool.getCentipedeHead();

	Ptr->SetExternalManagement(RecycleCentipedeHead);

	Ptr->Initialize(pos ,st,index);
	
	return Ptr;
}
CentipedeHead* CentipedeHeadFactory::privateCreateCentipedeHead(sf::Vector2f pos, const MoveState* st, int index,Centipede* prev)
{
	CentipedeHead* Ptr = myCentipedeHeadPool.getCentipedeHead();

	Ptr->SetExternalManagement(RecycleCentipedeHead);

	Ptr->Initialize(pos, st, index, prev);
	
	return Ptr;
}

void CentipedeHeadFactory::privateCreateWholeCentipede(int s)
{
	
}
void CentipedeHeadFactory::privateRecycleCentipedeHead(GameObject* GC)
{
	myCentipedeHeadPool.ReturnCentipedeHead(static_cast<CentipedeHead*>(GC));
}
void CentipedeHeadFactory::privateReportSound()
{
	SoundManager::SendSoundCommand((CommandSoundPlay*)pSound);
	SoundManager::ProcessSounds();
}
void CentipedeHeadFactory::privateReportDeath()
{
	ScoreManager::SendScoreCmd(pScore);
}
void CentipedeHeadFactory::privatePauseSound()
{
	SoundManager::SendPauseCommand(pSound);
}
void CentipedeHeadFactory::privateTerminate()
{
	
	
	delete InstancePtr;
	InstancePtr = nullptr;
}
