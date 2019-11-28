#ifndef _MoveState
#define _MoveState
#include "CentipedeHead.h"
#include "MovementCollection.h"
#include "GridManager.h"
#include "SpawnGrid.h"

#include <iostream>

struct OffsetArray;
class MoveState
{
public:
	MoveState() {};
	const OffsetArray* GetMoveOffsets(int i) const { return MyMoveOffsets[i]; }
	const int GetFrames() const { return frames; }
	
	virtual const MoveState* GetNextState(CentipedeHead* chead) const = 0;
	virtual void Show() const = 0;
protected:
	static const int frames = 8;
	const OffsetArray* MyMoveOffsets[frames];
};
#endif
