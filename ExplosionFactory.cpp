#include "ExplosionFactory.h"
#include "Explosion.h"


ExplosionFactory* ExplosionFactory::InstancePtr = nullptr;
Explosion* ExplosionFactory::privateCreateExplosion(float x, float y)
{
	Explosion* Ptr = myExplosionPool.getExplosion();


	Ptr->SetExternalManagement(RecycleExplosion);



	Ptr->Initialize(x, y);

	return Ptr;
}
void ExplosionFactory::privateRecycleExplosion(GameObject* f)
{
	myExplosionPool.ReturnFlea(static_cast<Explosion*>(f));
}
void ExplosionFactory::Terminate()
{
	delete InstancePtr;
	InstancePtr = nullptr;
}
