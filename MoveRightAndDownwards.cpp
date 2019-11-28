#include "MoveRightAndDownwards.h"
#include "MovementCollection.h"
#include "MoveFSM.h"
MoveRightAndDownwards::MoveRightAndDownwards()
{
	for (int i = 0; i < frames; i++)MyMoveOffsets[i] = &MovementCollection::OffsetsStraightRight;

}
void MoveRightAndDownwards::Show() const
{
	
}
const MoveState* MoveRightAndDownwards::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	int row = chead->getRow();
	int col = chead->getCol() + 1; // looking ahead while right
	SpawnGrid::Obstacle obst = GridManager::Inspect(row, col);

	if (obst == SpawnGrid::Obstacle::Clear)
	{
		pNextState = &MoveFSM::StateMoveRightAndDownwards;
	}
	else if (obst == SpawnGrid::Obstacle::Blocked) // Edge, shroom or letter?
	{
		if (row == SpawnGrid::BOTTOM_ROW)
			pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
		else
			pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
	}
	else // poison
	{
		// Not implemented
		assert(false && "Poison state not implemented yet!");
		pNextState = nullptr;
	}

	return pNextState;
}