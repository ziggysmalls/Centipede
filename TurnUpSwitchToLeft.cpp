#include "TurnUpSwitchToLeft.h"
#include "MoveFSM.h"

TurnUpSwitchToLeft::TurnUpSwitchToLeft()
{
	for (int i = 0; i < frames; i++)MyMoveOffsets[i] = &MovementCollection::OffsetsTurnUpEndLeft;
}
void TurnUpSwitchToLeft::Show() const
{
	
}
const MoveState* TurnUpSwitchToLeft::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	int row = chead->getRow();
	int col = chead->getCol() - 1; // looking ahead after turn -> left
	
	SpawnGrid::Obstacle obst = GridManager::Inspect(row, col);

	if (obst == SpawnGrid::Obstacle::Clear)
	{
		pNextState = &MoveFSM::StateMoveLeftAndUpwards;
	}
	else if (obst == SpawnGrid::Obstacle::Blocked) // Edge, shroom or letter?
	{
		if (row != SpawnGrid::TOP_PLAYER_ROW)
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