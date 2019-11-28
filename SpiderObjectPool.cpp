#include "SpiderObjectPool.h"
#include "Game Components/TEAL/CommonElements.h"
#include "Spider.h"


SpiderObjectPool::SpiderObjectPool()
{

}

SpiderObjectPool::~SpiderObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Spider* SpiderObjectPool::getSpider()
{
	Spider* m;

	if (recycledItems.empty())
	{
		ConsoleMsg::WriteLine("New Spider"); // For illustration purposes

		m = new Spider();
	}
	else
	{
		ConsoleMsg::WriteLine("Recycled Spider"); // For illustration purposes

		m = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

		// Tell the object to register itself to the scene
		m->RegisterToCurrentScene();
	}

	return m;
}
void SpiderObjectPool::ReturnSpider(Spider* s)
{
	recycledItems.push(static_cast<Spider*>(s));
}