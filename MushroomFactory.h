#ifndef _MushroomFactory
#define _MushroomFactory

#include "Game Components/TEAL/CommonElements.h"
// Forward Declaration
#include "Mushroom.h"
#include "MushroomObjectPool.h"
class GameObject;
class CmdScore;
class MushroomFactory
{
private: 
	static MushroomFactory* InstancePtr;
	MushroomObjectPool myMushroomPool;
	MushroomFactory(){};
	MushroomFactory(const MushroomFactory&) {};
	MushroomFactory& operator =(const MushroomFactory&) {};
	~MushroomFactory() {};
	static MushroomFactory& Instance()
	{
		if (!InstancePtr)
			InstancePtr = new MushroomFactory();
		return *InstancePtr;
	};
	CmdScore* pScore;
	Mushroom* privateCreateMushroom(float xPos,float yPos);
	void privateInitialize();
	void privateReportDeath();
	void privateTerminate();
	void privateRecycleMushroom(GameObject* m);


public:
	
	static Mushroom* CreateMushroom(float xPosition, float yPosition) { return Instance().privateCreateMushroom(xPosition, yPosition); };
	static void RecycleMushroom(GameObject* m) { Instance().privateRecycleMushroom(m); };
	static void Initialize() { Instance().privateInitialize(); };
	static void ReportDeath() { Instance().privateReportDeath(); };
	static void Terminate() {
		Instance().privateTerminate();
	};
};
#endif

