#include "CentipedeBodyFactory.h"
#include "CentipedeBody.h"
#include "CentipedeBodyObjectPool.h"
#include "CritterManager.h"
#include "ScoreManager.h"
CentipedeBodyFactory* CentipedeBodyFactory::InstancePtr = nullptr;

CentipedeBody* CentipedeBodyFactory::privateCreateCentipedeBody()
{
	CentipedeBody* Ptr = myCentipedeBodyPool.getCentipedeBody();

	Ptr->SetExternalManagement(RecycleCentipedeBody);

	Ptr->Initialize();
	
	
	return Ptr;

}
void CentipedeBodyFactory::privateInitialize()
{
	pScore = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::CentipedeBodyKilled);
}

CentipedeBody* CentipedeBodyFactory::privateCreateCentipedeBody(int r, int c, const MoveState* st, int index)
{
	CentipedeBody* Ptr = myCentipedeBodyPool.getCentipedeBody();

	Ptr->SetExternalManagement(RecycleCentipedeBody);

	Ptr->Initialize(r,c,st,index);
	
	return Ptr;
}
CentipedeBody* CentipedeBodyFactory::privateCreateCentipedeBody(Centipede* next)
{
	CentipedeBody* Ptr = myCentipedeBodyPool.getCentipedeBody();

	Ptr->SetExternalManagement(RecycleCentipedeBody);

	Ptr->Initialize(next);
	
	return Ptr;
}
CentipedeBody* CentipedeBodyFactory::privateCreateCentipedeBody(sf::Vector2f pos, const MoveState* st, int index)
{
	CentipedeBody* Ptr = myCentipedeBodyPool.getCentipedeBody();

	Ptr->SetExternalManagement(RecycleCentipedeBody);

	Ptr->Initialize(pos, st, index);
	
	return Ptr;
}
void CentipedeBodyFactory::privateRecycleCentipedeBody(GameObject* GC)
{
	myCentipedeBodyPool.ReturnCentipedeBody(static_cast<CentipedeBody*>(GC));
}
void CentipedeBodyFactory::privateReportDeath()
{
	ScoreManager::SendScoreCmd(pScore);
}
void CentipedeBodyFactory::privateTerminate()
{
	
	delete InstancePtr;
	InstancePtr = nullptr;
}
