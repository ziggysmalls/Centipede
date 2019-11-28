#ifndef _BulletObjectPool
#define _BulletObjectPool
#include <stack>
#include "Game Components/TEAL/CommonElements.h"
class Bullet;
class BulletObjectPool
{
private:
	std::stack<Bullet*> recycledItems;
public:
	BulletObjectPool();
	BulletObjectPool(const BulletObjectPool&) = delete;
	BulletObjectPool& operator= (const BulletObjectPool&) = delete;
	~BulletObjectPool();
	Bullet* getBullet();
	void ReturnBullet(Bullet* f);



};
#endif _FleaObjectPool

