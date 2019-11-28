#ifndef _PoisonMushroomObjectPool
#define _PoisonMushroomObjectPool
#include <stack>
#include "Game Components/TEAL/CommonElements.h"
class PoisonMushroom;
class PoisonMushroomObjectPool
{
private:
	std::stack<PoisonMushroom*> recycledItems;
public:
	PoisonMushroomObjectPool();
	PoisonMushroomObjectPool(const PoisonMushroomObjectPool&) = delete;
	PoisonMushroomObjectPool& operator= (const PoisonMushroomObjectPool&) = delete;
	~PoisonMushroomObjectPool();
	PoisonMushroom* getPoisonMushroom();
	void ReturnPoisonMushroom(PoisonMushroom* m);



};
#endif _MushroomObjectPool

