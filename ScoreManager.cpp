#include "ScoreManager.h"

#include <iostream>
#include "CommandScoreValue.h"
#include "CommandScoreByDistance.h"
#include "PlayerManager.h"
ScoreManager* ScoreManager::ptrInstance = nullptr;
ScoreManager::ScoreManager()
{

	FleaKilled = new CmdScoreValue(FleaDeath);
	ScorpionKilled = new CmdScoreValue(ScorpionDeath);
	MushroomKilled = new CmdScoreValue(MushroomDeath);
	SpiderKilled = new CmdScoreByDistance(SpiderDistNear, SpiderDistMedium, SpiderDistFar,
		SpiderDeathNear, SpiderDeathMedium, SpiderDeathFar);
	PoisonMushroomKilled = new CmdScoreValue(MushroomPoisonDeath);
	CentipedeHeadKilled = new CmdScoreValue(CentipedeHeadDeath);
	CentipedeBodyKilled = new CmdScoreValue(CentipedeBodyDeath);
}
	
ScoreManager::~ScoreManager()
{
	delete FleaKilled;
	FleaKilled = nullptr;
	delete ScorpionKilled;
	ScorpionKilled = nullptr;
	delete MushroomKilled;
	MushroomKilled = nullptr;
	 delete PoisonMushroomKilled;
	 PoisonMushroomKilled = nullptr;

	 delete SpiderKilled;
	 SpiderKilled = nullptr;
	 delete CentipedeHeadKilled;
	 CentipedeHeadKilled = nullptr;
	 delete CentipedeBodyKilled;
	 CentipedeBodyKilled = nullptr;
}
CmdScore* ScoreManager::privateGetScoreCommand(ScoreEvents ev)
{
	CmdScore* pCmd = nullptr;
	ConsoleMsg::WriteLine("Score Manager: Constructing score command for ");

	switch (ev)
	{
	case ScoreEvents::FleaKilled:
		ConsoleMsg::WriteLine("FleaDeath\n");
		pCmd = FleaKilled;
		break;
	case ScoreEvents::ScorpionKilled:
		ConsoleMsg::WriteLine("ScorpionDeath\n");
		pCmd = ScorpionKilled;
		break;
	case ScoreEvents::MushroomKilled:
		ConsoleMsg::WriteLine("MushroomDeath\n");
		pCmd = MushroomKilled;
		break;
	case ScoreEvents::SpiderKilled:
		ConsoleMsg::WriteLine("SpiderDeath\n");
		pCmd = SpiderKilled;
		break;
	case ScoreEvents::MushroomPoisonKilled:
		ConsoleMsg::WriteLine("MushroomPoisonDeath\n");
		pCmd = PoisonMushroomKilled;
		break;
	case ScoreEvents::CentipedeHeadKilled:
		pCmd = CentipedeHeadKilled;
		break;
	case ScoreEvents::CentipedeBodyKilled:
		pCmd = CentipedeBodyKilled;
	default:
		ConsoleMsg::WriteLine("<nothing>\n");
		break;
	}

	return pCmd;
}

void ScoreManager::AddScore(int val)
{
	
	// Note: Depending on implementations, this *may* need to be a strategy pattern:
	//      - regular mode: add score to current player
	//      - Critter-recall mode (level change): do nothing
	PlayerManager::SetPlayerScore(val);
}

void ScoreManager::privateSendScoreCmd(CmdScore* c)
{
	QueueCmds.push(c);
}

void ScoreManager::ProcessScores()
{
	Instance().privProcessScore();
}

void ScoreManager::privProcessScore()
{
	

	CmdScore* c;

	while (!QueueCmds.empty())
	{
		c = QueueCmds.front();
		c->Execute();

		QueueCmds.pop();
	}
}

void ScoreManager::privTerminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}