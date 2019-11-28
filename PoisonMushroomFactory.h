#ifndef _PoisonMushroomFactory
#define _PoisonMushroomFactory

#include "Game Components/TEAL/CommonElements.h"
// Forward Declaration
#include "PoisonMushroom.h"
#include "PoisonMushroomObjectPool.h"
class GameObject;
class CmdScore;
class PoisonMushroomFactory
{
private:
	static PoisonMushroomFactory* InstancePtr;
	PoisonMushroomObjectPool myPoisonMushroomPool;
	PoisonMushroomFactory() {};
	PoisonMushroomFactory(const PoisonMushroomFactory&) {};
	PoisonMushroomFactory& operator =(const PoisonMushroomFactory&) {};
	~PoisonMushroomFactory() {};
	static PoisonMushroomFactory& Instance()
	{
		if (!InstancePtr)
			InstancePtr = new PoisonMushroomFactory();
		return *InstancePtr;
	};
	CmdScore* pScore;
	PoisonMushroom* privateCreatePoisonMushroom(float xPos, float yPos, int previousHealth);
	void privateReportDeath();
	void privateInitialize();
	void privateTerminate();
	void privateRecyclePoisonMushroom(GameObject* m);


public:

	static PoisonMushroom* CreatePoisonMushroom(float xPosition, float yPosition, int previousHealth) { return Instance().privateCreatePoisonMushroom(xPosition, yPosition, previousHealth); };
	static void RecycleMushroom(GameObject* m) { Instance().privateRecyclePoisonMushroom(m); };
	static void Terminate() {
		Instance().privateTerminate();
	};
	static void ReportDeath() { Instance().privateReportDeath(); };
	static void Initialize() { Instance().privateInitialize(); };
};
#endif

