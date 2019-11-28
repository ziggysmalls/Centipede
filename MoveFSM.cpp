#include "MoveFSM.h"
#include "MovementCollection.h"

const MoveRightAndDownwards MoveFSM::StateMoveRightAndDownwards;
const MoveRightAndUpwards  MoveFSM::StateMoveRightAndUpwards;
const MoveLeftAndDownwards  MoveFSM::StateMoveLeftAndDownwards;
const MoveLeftAndUpwards  MoveFSM::StateMoveLeftAndUpwards;
const TurnDownSwitchToLeft MoveFSM::StateTurnDownSwitchToLeft;
const TurnDownSwitchToRight MoveFSM::StateTurnDownSwitchToRight;
const TurnUpSwitchToLeft MoveFSM::StateTurnUpSwitchToLeft;
const TurnUpSwitchToRight MoveFSM::StateTurnUpSwitchToRight;