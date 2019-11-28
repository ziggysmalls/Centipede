#include "TurnDownSwitchToRight.h"
#include "MoveFSM.h"

TurnDownSwitchToRight::TurnDownSwitchToRight()
{
	
	for (int i = 0; i < frames; i++)MyMoveOffsets[i] = &MovementCollection::OffsetsTurnDownEndRight;
}

void TurnDownSwitchToRight::Show() const
{
	
}

const MoveState* TurnDownSwitchToRight::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	int row = chead->getRow();
	int col = chead->getCol() + 1; // looking ahead after turn -> right
	SpawnGrid::Obstacle obst = GridManager::Inspect(row, col);

	if (obst == SpawnGrid::Obstacle::Clear)
	{
		pNextState = &MoveFSM::StateMoveRightAndDownwards;
	}
	else if (obst == SpawnGrid::Obstacle::Blocked) // Edge, shroom or letter?
	{
		if (row != SpawnGrid::BOTTOM_ROW)
			pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
		else if (row == SpawnGrid::BOTTOM_ROW)
			pNextState = &MoveFSM::StateMoveRightAndDownwards;
	
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