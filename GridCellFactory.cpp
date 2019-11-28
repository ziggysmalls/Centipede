#include "GridCellFactory.h"
#include "GridCell.h"
#include "GridCellObjectPool.h"

GridCellFactory* GridCellFactory::InstancePtr = nullptr;

GridCell* GridCellFactory::privateCreateGridCell()
{
	GridCell* GCPtr = myGridCellPool.getGridCell();

	GCPtr->SetExternalManagement(RecycleGridCell);
	
	GCPtr->Initialize();

	return GCPtr;
}
void GridCellFactory::privateRecycleGridCell(GameObject* GC)
{
	myGridCellPool.ReturnGridCell(static_cast<GridCell*>(GC));
}
void GridCellFactory::Terminate()
{
	delete InstancePtr;
	InstancePtr = nullptr;
}
