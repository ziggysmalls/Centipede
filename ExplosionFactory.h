#ifndef _ExplosionFactory
#define _ExplosionFactory

#include "Game Components/TEAL/CommonElements.h"
// Forward Declaration
#include "Explosion.h"
#include "ExplosionObjectPool.h"
class GameObject;
class ExplosionFactory
{
private:

	ExplosionObjectPool myExplosionPool;
	static ExplosionFactory* InstancePtr;
	ExplosionFactory() {};
	ExplosionFactory(const ExplosionFactory&) {};
	ExplosionFactory& operator =(const ExplosionFactory&) {};
	~ExplosionFactory() {};
	static ExplosionFactory& Instance()
	{
		if (!InstancePtr)
			InstancePtr = new ExplosionFactory();
		return *InstancePtr;
	};
	Explosion* privateCreateExplosion(float x,float y);
	void privateRecycleExplosion(GameObject* m);

public:

	static Explosion* CreateExplosion(float x, float y) { return Instance().privateCreateExplosion(x,y); };
	static void RecycleExplosion(GameObject* m) { Instance().privateRecycleExplosion(m); };
	static void Terminate();
};
#endif

