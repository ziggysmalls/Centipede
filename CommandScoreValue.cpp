#include "CommandScoreValue.h"
#include <iostream>
#include "ScoreManager.h"
#include "Game Components/TEAL/CommonElements.h"

CmdScoreValue::CmdScoreValue(int val)
	: points(val)
{
	ConsoleMsg::WriteLine("Score Command created: Points = %i\n" + Tools::ToString( val));
}

void CmdScoreValue::Execute()
{
	ConsoleMsg::WriteLine("Score Command Executing\n");
	ScoreManager::AddScore(points);
}