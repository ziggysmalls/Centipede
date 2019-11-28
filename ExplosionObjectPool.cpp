#include "ExplosionObjectPool.h"
#include "Game Components/TEAL/CommonElements.h"
#include "Explosion.h"


ExplosionObjectPool::ExplosionObjectPool()
{

}

ExplosionObjectPool::~ExplosionObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Explosion* ExplosionObjectPool::getExplosion()
{
	Explosion* m;

	if (recycledItems.empty())
	{
		ConsoleMsg::WriteLine("New Flea"); // For illustration purposes

		m = new Explosion();
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
void ExplosionObjectPool::ReturnFlea(Explosion* m)
{
	recycledItems.push(static_cast<Explosion*>(m));
}