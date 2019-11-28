#include "CentipedeHeadObjectPool.h"

#include "Game Components/TEAL/CommonElements.h"
#include "CentipedeHead.h"


CentipedeHeadObjectPool::CentipedeHeadObjectPool()
{

}

CentipedeHeadObjectPool::~CentipedeHeadObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

CentipedeHead* CentipedeHeadObjectPool::getCentipedeHead()
{
	CentipedeHead* m;

	if (recycledItems.empty())
	{
		
		m = new CentipedeHead();
	}
	else
	{
		
		m = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

		// Tell the object to register itself to the scene
		m->RegisterToCurrentScene();
	}

	return m;
}
void CentipedeHeadObjectPool::ReturnCentipedeHead(CentipedeHead* s)
{
	recycledItems.push(static_cast<CentipedeHead*>(s));
}