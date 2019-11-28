#ifndef _ScoreManager
#define _ScoreManager

#include <queue>

class CmdScore;

class ScoreManager
{
public:
	// events
	enum class ScoreEvents { FleaKilled, ScorpionKilled, MushroomKilled, MushroomPoisonKilled, SpiderKilled, CentipedeHeadKilled, CentipedeBodyKilled };

	static void AddScore(int val);

	static CmdScore* GetScoreCommand(ScoreEvents ev) {return Instance().privateGetScoreCommand(ev);};

	static void SendScoreCmd(CmdScore* c) { Instance().privateSendScoreCmd(c); };
	static void ProcessScores();
	static void Terminate() { Instance().privTerminate(); };
private:
	// Score values;
	static const int FleaDeath = 100;
	static const int ScorpionDeath = 1000;
	static const int MushroomDeath = 1;
	static const int MushroomPoisonDeath = 5;

	static const int SpiderDeathFar = 300;
	static const int SpiderDistFar = 9999;

	static const int SpiderDeathMedium = 600;
	static const int SpiderDistMedium = 99;

	static const int SpiderDeathNear = 900;
	static const int SpiderDistNear = 9;

	static const int CentipedeHeadDeath = 100;
	static const int CentipedeBodyDeath = 10;
	std::queue<CmdScore*> QueueCmds;
	CmdScore* FleaKilled;
	CmdScore* ScorpionKilled;
	CmdScore* MushroomKilled;
	CmdScore* PoisonMushroomKilled;
	CmdScore* SpiderKilled;
	CmdScore* CentipedeHeadKilled;
	CmdScore* CentipedeBodyKilled;
	static ScoreManager* ptrInstance;
	ScoreManager();
	~ScoreManager();
	static ScoreManager& Instance()	    // Access reference (all public methods will be static)
	{
		if (!ptrInstance)
			ptrInstance = new ScoreManager;
		return *ptrInstance;
	};

	void privProcessScore();
	void privTerminate();
	void privateSendScoreCmd(CmdScore* c);
	CmdScore* privateGetScoreCommand(ScoreEvents event);
	


};
#endif