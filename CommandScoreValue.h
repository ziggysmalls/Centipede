#ifndef _CommandScoreValue
#define _CommandScoreValue

#include "CommandScore.h"

class CmdScoreValue : public CmdScore
{
protected:
	int points;	// points to add

public:
	CmdScoreValue() = delete;
	CmdScoreValue(int val);

	virtual void Execute() override;

};
#endif
