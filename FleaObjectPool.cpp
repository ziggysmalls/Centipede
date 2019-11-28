#include "FleaObjectPool.h"
#include "Game Components/TEAL/CommonElements.h"
#include "Flea.h"


FleaObjectPool::FleaObjectPool()
{

}

FleaObjectPool::~FleaObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Flea* FleaObjectPool::getFlea()
{
	Flea* m;

	if (recycledItems.empty())
	{
		ConsoleMsg::WriteLine("New Flea"); // For illustration purposes

		m = new Flea();
	}
	else
	{
		ConsoleMsg::WriteLine("Recycled Flea"); // For illustration purposes

		m = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

		// Tell the object to register itself to the scene
		m->RegisterToCurrentScene();
	}

	return m;
}
void FleaObjectPool::ReturnFlea(Flea* m)
{
	recycledItems.push(static_cast<Flea*>(m));
}