#include "MushroomObjectPool.h"
#include "Game Components/TEAL/CommonElements.h"
#include "Mushroom.h"


MushroomObjectPool::MushroomObjectPool()
{

}

MushroomObjectPool::~MushroomObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Mushroom* MushroomObjectPool::getMushroom()
{
	Mushroom* m;

	if (recycledItems.empty())
	{
		
		m = new Mushroom();
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
void MushroomObjectPool::ReturnMushroom(Mushroom* m)
{
	recycledItems.push(static_cast<Mushroom *>(m));
}