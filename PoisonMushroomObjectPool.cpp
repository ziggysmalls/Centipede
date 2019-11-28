#include "PoisonMushroomObjectPool.h"
#include "Game Components/TEAL/CommonElements.h"
#include "PoisonMushroom.h"


PoisonMushroomObjectPool::PoisonMushroomObjectPool()
{

}

PoisonMushroomObjectPool::~PoisonMushroomObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

PoisonMushroom* PoisonMushroomObjectPool::getPoisonMushroom()
{
	PoisonMushroom* m;

	if (recycledItems.empty())
	{
		ConsoleMsg::WriteLine("New PoisonMushroom"); // For illustration purposes

		m = new PoisonMushroom();
	}
	else
	{
		ConsoleMsg::WriteLine("Recycled PoisonMushroom"); // For illustration purposes

		m = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

		// Tell the object to register itself to the scene
		m->RegisterToCurrentScene();
	}

	return m;
}
void PoisonMushroomObjectPool::ReturnPoisonMushroom(PoisonMushroom* m)
{
	recycledItems.push(static_cast<PoisonMushroom*>(m));
}