#include "CommandScoreByDistance.h"
#include <iostream>
#include "ScoreManager.h"

CmdScoreByDistance::CmdScoreByDistance(int dn, int dm, int df,
	int vn, int vm, int vf)
	: dNear(dn), dMed(dm), dFar(df), vNear(vn), vMed(vm), vFar(vf)
{
	ConsoleMsg::WriteLine("Score by distance command created");
	ConsoleMsg::WriteLine("\tdist <= %i  is worth %i points\n" + Tools::ToString(dNear) + Tools::ToString( vNear));
	ConsoleMsg::WriteLine("\tdist <= %i  is worth %i points\n"+ Tools::ToString( dMed) + Tools::ToString( vMed));
	ConsoleMsg::WriteLine("\tdist <= %i  is worth %i points\n" + Tools::ToString(dFar) + Tools::ToString( vFar));
}

void CmdScoreByDistance::Execute()
{
	int ans = 300;
	
	// Realistically: this cmd also gets the position of the player and spider on death to compute the distance
	// This data is passed to the command before sending it to the broker.

	// processing distance to score:
	if (ans <= dNear)
	{
		ConsoleMsg::WriteLine("\tNear range detected:\n");
		ScoreManager::AddScore(vNear);
	}
	else if (ans <= dMed)
	{
		ConsoleMsg::WriteLine("\tMedium range detected:\n");
		ScoreManager::AddScore(vMed);
	}
	else
	{
		printf("\tFar range detected:\n");
		ScoreManager::AddScore(vFar);
	}
}