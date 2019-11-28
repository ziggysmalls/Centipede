#include "CentipedeBodyObjectPool.h"

#include "Game Components/TEAL/CommonElements.h"
#include "CentipedeBody.h"


CentipedeBodyObjectPool::CentipedeBodyObjectPool()
{

}

CentipedeBodyObjectPool::~CentipedeBodyObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

CentipedeBody* CentipedeBodyObjectPool::getCentipedeBody()
{
	CentipedeBody* m;

	if (recycledItems.empty())
	{
		ConsoleMsg::WriteLine("New CentipedeBody"); // For illustration purposes

		m = new CentipedeBody();
	}
	else
	{
		ConsoleMsg::WriteLine("Recycled CentipedeBody"); // For illustration purposes

		m = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

		// Tell the object to register itself to the scene
		m->RegisterToCurrentScene();
	}

	return m;
}
void CentipedeBodyObjectPool::ReturnCentipedeBody(CentipedeBody* s)
{
	recycledItems.push(static_cast<CentipedeBody*>(s));
}
