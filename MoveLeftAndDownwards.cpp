#include "MoveLeftAndDownwards.h"
#include "MoveFSM.h"


MoveLeftAndDownwards::MoveLeftAndDownwards()
{
	for(int i = 0; i < frames; i++) MyMoveOffsets[i] = &MovementCollection::OffsetsStraightLeft;
}
void MoveLeftAndDownwards::Show() const
{
}

const MoveState* MoveLeftAndDownwards::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	int row = chead->getRow();
	int col = chead->getCol() - 1; // looking ahead while left
	
	
	SpawnGrid::Obstacle obst = GridManager::Inspect(row,col);

	if (obst == SpawnGrid::Obstacle::Clear)
	{
		pNextState = &MoveFSM::StateMoveLeftAndDownwards;
	}
	else if (obst == SpawnGrid::Obstacle::Blocked) // Edge, shroom or letter?
	{
		if (row == SpawnGrid::BOTTOM_ROW)
			pNextState = &MoveFSM::StateTurnUpSwitchToRight;
		else
			pNextState = &MoveFSM::StateTurnDownSwitchToRight;
	}
	else // poison
	{
		// Not implemented
		assert(false && "Poison state not implemented yet!");
		pNextState = nullptr;
	}

	return pNextState;
}