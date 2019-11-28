#include "TurnUpSwitchToRight.h"
#include "MoveFSM.h"

TurnUpSwitchToRight::TurnUpSwitchToRight()
{
	for (int i = 0; i < frames; i++)MyMoveOffsets[i] = &MovementCollection::OffsetsTurnUpEndRight;
	
}
void TurnUpSwitchToRight::Show() const
{
	
}
const MoveState* TurnUpSwitchToRight::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	int row = chead->getRow();
	int col = chead->getCol() + 1; // looking ahead after turn -> Right
	
	SpawnGrid::Obstacle obst = GridManager::Inspect(row, col);

	if (obst == SpawnGrid::Obstacle::Clear)
	{
		pNextState = &MoveFSM::StateMoveRightAndUpwards;
	}
	else if (obst == SpawnGrid::Obstacle::Blocked) // Edge, shroom or letter?
	{
		if (row != SpawnGrid::TOP_PLAYER_ROW)
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