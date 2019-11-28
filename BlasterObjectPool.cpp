// Ezequiel Arrieta 2019
#include "BlasterObjectPool.h"
#include "Game Components/TEAL/CommonElements.h"
#include "Blaster.h"
#include "KeyBoardInput.h"

BlasterObjectPool::BlasterObjectPool()
{

}

BlasterObjectPool::~BlasterObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Blaster* BlasterObjectPool::getBlaster()
{
	Blaster* m;

	if (recycledItems.empty())
	{
		ConsoleMsg::WriteLine("New Blaster"); // For illustration purposes

		m = new Blaster();
	}
	else
	{
		ConsoleMsg::WriteLine("Recycled Blaster"); // For illustration purposes

		m = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

		// Tell the object to register itself to the scene
		m->RegisterToCurrentScene();
	}

	return m;
}
void BlasterObjectPool::ReturnBlaster(Blaster* m)
{
	recycledItems.push(static_cast<Blaster*>(m));
}
