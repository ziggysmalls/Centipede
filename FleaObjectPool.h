#ifndef _FleaObjectPool
#define _FleaObjectPool
#include <stack>
#include "Game Components/TEAL/CommonElements.h"
class Flea;
class FleaObjectPool
{
private:
	std::stack<Flea*> recycledItems;
public:
	FleaObjectPool();
	FleaObjectPool(const FleaObjectPool&) = delete;
	FleaObjectPool& operator= (const FleaObjectPool&) = delete;
	~FleaObjectPool();
	Flea* getFlea();
	void ReturnFlea(Flea* f);



};
#endif _FleaObjectPool

