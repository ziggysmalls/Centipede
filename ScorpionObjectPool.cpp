#include "ScorpionObjectPool.h"
#include "Game Components/TEAL/CommonElements.h"
#include "Scorpion.h"


ScorpionObjectPool::ScorpionObjectPool()
{

}

ScorpionObjectPool::~ScorpionObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Scorpion* ScorpionObjectPool::getScorpion()
{
	Scorpion* m;

	if (recycledItems.empty())
	{
		ConsoleMsg::WriteLine("New Scorpion"); // For illustration purposes

		m = new Scorpion();
	}
	else
	{
		ConsoleMsg::WriteLine("Recycled Scorpion"); // For illustration purposes

		m = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

		// Tell the object to register itself to the scene
		m->RegisterToCurrentScene();
	}

	return m;
}
void ScorpionObjectPool::ReturnScorpion(Scorpion* s)
{
	recycledItems.push(static_cast<Scorpion*>(s));
}