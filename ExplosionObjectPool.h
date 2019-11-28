#ifndef _ExplosionObjectPool
#define _ExplosionObjectPool
#include <stack>
#include "Game Components/TEAL/CommonElements.h"
class Explosion;
class ExplosionObjectPool
{
private:
	std::stack<Explosion*> recycledItems;
public:
	ExplosionObjectPool();
	ExplosionObjectPool(const ExplosionObjectPool&) = delete;
	ExplosionObjectPool& operator= (const ExplosionObjectPool&) = delete;
	~ExplosionObjectPool();
	Explosion* getExplosion();
	void ReturnFlea(Explosion* f);



};
#endif _FleaObjectPool

