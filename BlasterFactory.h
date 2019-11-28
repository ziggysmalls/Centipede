#ifndef _BlasterFactory
#define _BlasterFactory

#include "Game Components/TEAL/CommonElements.h"
// Forward Declaration
#include "Blaster.h"
#include "BlasterObjectPool.h"
class GameObject;
class BlasterFactory
{
private:

	BlasterObjectPool myBlasterPool;
	static BlasterFactory* InstancePtr;
	BlasterFactory() {};
	BlasterFactory(const BlasterFactory&) {};
	BlasterFactory& operator =(const BlasterFactory&) {};
	~BlasterFactory() {};
	static BlasterFactory& Instance()
	{
		if (!InstancePtr)
			InstancePtr = new BlasterFactory();
		return *InstancePtr;
	};
	Blaster* privateCreateBlaster();
	Blaster* privateCreateBlaster(InputController* input);
	void privateRecycleBlaster(GameObject* m);

public:

	static Blaster* CreateBlaster() { return Instance().privateCreateBlaster(); };
	static Blaster* CreateBlaster(InputController* input) { return Instance().privateCreateBlaster(input); };
	static void RecycleBlaster(GameObject* m) { Instance().privateRecycleBlaster(m); };
	static void Terminate();
};
#endif



