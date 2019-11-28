#ifndef _GridCellObjectPool
#define _GridCellObjectPool
#include <stack>
#include "Game Components/TEAL/CommonElements.h"
class GridCell;
class GridCellObjectPool
{
private:
 std::stack<GridCell*> recycledItems;
public:
	GridCellObjectPool();
	GridCellObjectPool(const GridCellObjectPool&) = delete;
	GridCellObjectPool& operator= (const GridCellObjectPool&) = delete;
	~GridCellObjectPool();
	GridCell* getGridCell();
	void ReturnGridCell(GridCell* GC);
};
#endif _GridCellObjectPool

