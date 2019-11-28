#ifndef _MoveRightAndDownwards
#define _MoveRightAndDownwards
#include "MoveState.h"

class MoveRightAndDownwards: public MoveState
{
public:
	MoveRightAndDownwards();
	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void Show() const override;
};
#endif

