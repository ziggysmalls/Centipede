#ifndef _MoveFSM
#define _MoveFSM
#include "MoveState.h"
#include "TurnDownSwitchToLeft.h"
#include "MoveLeftAndDownwards.h"
#include "MoveRightAndDownwards.h"
#include "MoveLeftAndUpwards.h"
#include "MoveRightAndUpwards.h"
#include "TurnDownSwitchToLeft.h"
#include "TurnDownSwitchToRight.h"
#include "TurnUpSwitchToLeft.h"
#include "TurnUpSwitchToRight.h"
class MoveFSM
{
private:

public:
	static const MoveRightAndDownwards StateMoveRightAndDownwards;
	static const MoveRightAndUpwards StateMoveRightAndUpwards;
	static const MoveLeftAndDownwards StateMoveLeftAndDownwards;
	static const MoveLeftAndUpwards StateMoveLeftAndUpwards;
	static const TurnDownSwitchToLeft StateTurnDownSwitchToLeft;
	static const TurnDownSwitchToRight StateTurnDownSwitchToRight;
	static const TurnUpSwitchToLeft StateTurnUpSwitchToLeft;
	static const TurnUpSwitchToRight StateTurnUpSwitchToRight;
};
#endif
