#include "BulletObjectPool.h"
#include "Game Components/TEAL/CommonElements.h"
#include "Bullet.h"


BulletObjectPool::BulletObjectPool()
{

}

BulletObjectPool::~BulletObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Bullet* BulletObjectPool::getBullet()
{
	Bullet* m;

	if (recycledItems.empty())
	{
		ConsoleMsg::WriteLine("New Bullet"); // For illustration purposes

		m = new Bullet();
	}
	else
	{
		ConsoleMsg::WriteLine("Recycled Bullet"); // For illustration purposes

		m = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

		// Tell the object to register itself to the scene
		m->RegisterToCurrentScene();
	}

	return m;
}
void BulletObjectPool::ReturnBullet(Bullet* m)
{
	recycledItems.push(static_cast<Bullet*>(m));
}
