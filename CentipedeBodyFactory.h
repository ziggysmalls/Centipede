#ifndef _CentipedeBodyFactory
#define _CentipedeBodyFactory
#include "Game Components/TEAL/CommonElements.h"
#include "CentipedeBody.h"
#include "CentipedeBodyObjectPool.h"

class GameObject;
class CmdScore;
class CentipedeBodyFactory

	// Forward Declaration
{
private:


	static CentipedeBodyFactory* InstancePtr;
	CentipedeBodyFactory() = default;
	CentipedeBodyFactory(const CentipedeBodyFactory&) = delete;
	CentipedeBodyFactory& operator =(const CentipedeBodyFactory&) = delete;
	~CentipedeBodyFactory() {};
	static CentipedeBodyFactory& Instance()
	{
		if (!InstancePtr)
			InstancePtr = new CentipedeBodyFactory();
		return *InstancePtr;
	};

	CentipedeBodyObjectPool myCentipedeBodyPool;
	CmdScore* pScore;

	CentipedeBody* privateCreateCentipedeBody();
	CentipedeBody* privateCreateCentipedeBody(Centipede* next);
	CentipedeBody* privateCreateCentipedeBody(int r, int c, const MoveState* st, int index);
	CentipedeBody* privateCreateCentipedeBody(sf::Vector2f pos, const MoveState* st, int index);
	void privateRecycleCentipedeBody(GameObject* s);
	void privateInitialize();
	void privateReportDeath();
	void privateTerminate();

public:

	static CentipedeBody* CreateCentipedeBody() { return Instance().privateCreateCentipedeBody(); };
	static CentipedeBody* CreateCentipedeBody(Centipede* next) { Instance().privateCreateCentipedeBody(next); };
	static CentipedeBody* CreateCentipedeBody(sf::Vector2f pos, const MoveState* st, int index) { return Instance().privateCreateCentipedeBody(pos, st, index); }
	static CentipedeBody* CreateCentipedeBody(int row, int col, const MoveState* state, int index) { return Instance().privateCreateCentipedeBody(row, col, state, index); };
	static void RecycleCentipedeBody(GameObject* m) { Instance().privateRecycleCentipedeBody(m); };
	static void ReportDeath() { Instance().privateReportDeath(); };
	static void Initialize() { Instance().privateInitialize(); };
	static void Terminate() { Instance().privateTerminate(); };
};
#endif


