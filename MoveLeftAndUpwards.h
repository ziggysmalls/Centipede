#pragma once
#include "MoveState.h"
class MoveLeftAndUpwards : public  MoveState
{
public:
	MoveLeftAndUpwards();
	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void Show() const override;
};

