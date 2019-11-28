#include "MoveLeftAndUpwards.h"
#include "MoveFSM.h"

MoveLeftAndUpwards::MoveLeftAndUpwards()
{
	std::cout << "Initializing MoveLeftAndUpwards state\n";

	for (int i = 0; i < frames; i++)MyMoveOffsets[i] = &MovementCollection::OffsetsStraightLeft;
}
void MoveLeftAndUpwards::Show() const
{
	
}
const MoveState* MoveLeftAndUpwards::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	int row = chead->getRow();
	int col = chead->getCol() - 1; // looking ahead while left
	
	SpawnGrid::Obstacle obst = GridManager::Inspect(row,col);

	if (obst == SpawnGrid::Obstacle::Clear)
	{
		pNextState = &MoveFSM::StateMoveLeftAndUpwards;
	}
	else if (obst == SpawnGrid::Obstacle::Blocked) // Edge, shroom or letter?
	{
		if (row == SpawnGrid::TOP_PLAYER_ROW)
			pNextState = &MoveFSM::StateTurnDownSwitchToRight;
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