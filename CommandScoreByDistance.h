#ifndef _CommandScoreByDistance
#define _CommandScoreByDistance

#include "CommandScore.h"

class CmdScoreByDistance : public CmdScore
{
private:
	int dNear;
	int dMed;
	int dFar;
	int vNear;
	int vMed;
	int vFar;

public:
	CmdScoreByDistance(int dNear, int dMed, int dFar,
		int vNear, int vMed, int vFar);

	virtual void Execute() override;


};
#endif