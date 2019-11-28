#include "MoveRightAndUpwards.h"
#include "MoveFSM.h"
#include "MovementCollection.h"
MoveRightAndUpwards::MoveRightAndUpwards()
{
	for (int i = 0; i < frames; i++)MyMoveOffsets[i] = &MovementCollection::OffsetsStraightRight;
}
void MoveRightAndUpwards::Show() const
{
	
}
const MoveState* MoveRightAndUpwards::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	int row = chead->getRow();
	int col = chead->getCol() + 1; // looking ahead while right
	
	SpawnGrid::Obstacle obst = GridManager::Inspect(row, col);

	if (obst == SpawnGrid::Obstacle::Clear)
	{
		pNextState = &MoveFSM::StateMoveRightAndUpwards;
	}
	else if (obst == SpawnGrid::Obstacle::Blocked) // Edge, shroom or letter?
	{
		if (row == SpawnGrid::TOP_PLAYER_ROW)
			pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
		else
			pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
	}
	else // poison
	{
		// Not implemented
		assert(false && "Poison state not implemented yet!");
		pNextState = nullptr;
	}

	return pNextState;
}
