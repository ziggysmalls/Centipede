#ifndef _GridCellFactory
#define _GridCellFactory

#include <stack>
#include "Game Components/TEAL/CommonElements.h"
#include "GridCellObjectPool.h"
class GridCell;
class GridCellFactory
{
private: 
	GridCellObjectPool myGridCellPool;
	static GridCellFactory* InstancePtr;
	GridCellFactory() {};
	GridCellFactory(const GridCellFactory&) {};
	GridCellFactory& operator= (const GridCellFactory&) {};
	~GridCellFactory() {};

	static GridCellFactory& Instance()
	{
		if (!InstancePtr)
			InstancePtr = new GridCellFactory();
		return *InstancePtr;
	};

	GridCell* privateCreateGridCell();
	void privateRecycleGridCell(GameObject* GC);
public:
	
	static GridCell* CreateGridCell() { return Instance().privateCreateGridCell(); };
	static void RecycleGridCell(GameObject* GC) { Instance().privateRecycleGridCell(GC); };
	static void Terminate();

};
#endif

