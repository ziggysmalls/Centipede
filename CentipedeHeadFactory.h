#ifndef _CentipedeHeadFactory
#define _CentipedeHeadFactory
#include "Game Components/TEAL/CommonElements.h"
#include "CentipedeHead.h"
#include "CentipedeHeadObjectPool.h"
#include "SoundManager.h"
class GameObject;
class SoundCommandLoop;
class CmdScore;
class CentipedeHeadFactory

	// Forward Declaration
{
private:


	static CentipedeHeadFactory* InstancePtr;
	CentipedeHeadFactory() = default;
	CentipedeHeadFactory(const CentipedeHeadFactory&) = delete;
	CentipedeHeadFactory& operator =(const CentipedeHeadFactory&) = delete;
	~CentipedeHeadFactory() {};
	static CentipedeHeadFactory& Instance()
	{
		if (!InstancePtr)
			InstancePtr = new CentipedeHeadFactory();
		return *InstancePtr;
	};

	CentipedeHeadObjectPool myCentipedeHeadPool;

	void privateInitialize();
	void privateReportSound();
	void privatePauseSound();
	void privateReportDeath();
	CentipedeHead* privateCreateCentipedeHead();
	void privateCreateWholeCentipede(int s);
	CentipedeHead* privateCreateCentipedeHead(int r, int c, const MoveState* st);
	CentipedeHead* privateCreateCentipedeHead(sf::Vector2f pos, const MoveState* st,int index);
	CentipedeHead* privateCreateCentipedeHead(sf::Vector2f pos, const MoveState* st,int index, Centipede* prev);

	void privateRecycleCentipedeHead(GameObject* s);
	void privateTerminate();
	CommandSoundLoop* pSound;
	CmdScore* pScore;


public:
	static CentipedeHead* CreateCentipedeHead(int r, int c, const MoveState* st) { return Instance().privateCreateCentipedeHead(r, c, st); };
	static CentipedeHead* CreateCentipedeHead(sf::Vector2f pos, const MoveState* st, int index) { return Instance().privateCreateCentipedeHead(pos, st,index); };
	static CentipedeHead* CreateCentipedeHead(sf::Vector2f pos, const MoveState* st, int index, Centipede* prev) { return Instance().privateCreateCentipedeHead(pos, st, index, prev); };
	static void Initialize() { Instance().privateInitialize(); };
	static void CreateWholeCentipede(int s) {Instance().privateCreateWholeCentipede(s); }
	static void ReportSound() { Instance().privateReportSound(); };
	static CentipedeHead* CreateCentipedeHead() { return Instance().privateCreateCentipedeHead(); };
	static void RecycleCentipedeHead(GameObject* m) { Instance().privateRecycleCentipedeHead(m); };
	static void PauseSound() { Instance().privatePauseSound(); };
	static void ReportDeath() { Instance().privateReportDeath(); };
	static void Terminate() { Instance().privateTerminate(); };
};
#endif


