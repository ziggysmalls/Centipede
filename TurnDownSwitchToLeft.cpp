#include "TurnDownSwitchToLeft.h"
#include "MoveFSM.h"

TurnDownSwitchToLeft::TurnDownSwitchToLeft()
{
	for (int i = 0; i < frames; i++)MyMoveOffsets[i] = &MovementCollection::OffsetsTurnDownEndLeft;
}
void TurnDownSwitchToLeft::Show() const
{
}
const MoveState* TurnDownSwitchToLeft::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	int row = chead->getRow();
	int col = chead->getCol() - 1; // looking ahead after turn ->left
	SpawnGrid::Obstacle obst = GridManager::Inspect(row, col);

	if (obst == SpawnGrid::Obstacle::Clear)
	{
		pNextState = &MoveFSM::StateMoveLeftAndDownwards;
	}
	else if (obst == SpawnGrid::Obstacle::Blocked) // Edge, shroom or letter?
	{
		if (row != SpawnGrid::BOTTOM_ROW)
			pNextState = &MoveFSM::StateTurnDownSwitchToRight;
		else if (row == SpawnGrid::BOTTOM_ROW)
			pNextState = &MoveFSM::StateMoveLeftAndDownwards;
		else
			pNextState = &MoveFSM::StateTurnUpSwitchToRight;
	}
	else // poison
	{
		// Not implemented
		assert(false && "Poison state not implemented yet!");
		pNextState = nullptr;
	}

	return pNextState;
}