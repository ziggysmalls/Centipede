#include "GridCellObjectPool.h"
#include "Game Components/TEAL/CommonElements.h"
#include "GridCell.h"


GridCellObjectPool::GridCellObjectPool()
{

}

GridCellObjectPool::~GridCellObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

GridCell* GridCellObjectPool::getGridCell()
{
	GridCell* m;

	if (recycledItems.empty())
	{
		ConsoleMsg::WriteLine("New Grid Cell"); // For illustration purposes

		m = new GridCell();
	}
	else
	{
		ConsoleMsg::WriteLine("Recycled Grid Cell"); // For illustration purposes

		m = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

		// Tell the object to register itself to the scene
		m->RegisterToCurrentScene();
	}

	return m;
}
void GridCellObjectPool::ReturnGridCell(GridCell* m)
{
	recycledItems.push(static_cast<GridCell*>(m));
}