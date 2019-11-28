#ifndef _MushroomObjectPool
#define _MushroomObjectPool
#include <stack>
#include "Game Components/TEAL/CommonElements.h"
class Mushroom;
class MushroomObjectPool
{
private:
 std::stack<Mushroom*> recycledItems;
public:
	MushroomObjectPool();
	MushroomObjectPool(const MushroomObjectPool&) = delete;
	MushroomObjectPool& operator= (const MushroomObjectPool&) = delete;
	~MushroomObjectPool();
	Mushroom* getMushroom();
	void ReturnMushroom(Mushroom* m);

	

};
#endif _MushroomObjectPool

