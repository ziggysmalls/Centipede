#ifndef _SpiderObjectPool
#define _SpiderObjectPool
#include <stack>
#include "Game Components/TEAL/CommonElements.h"
class Spider;
class SpiderObjectPool
{
private:
	 std::stack<Spider*> recycledItems;
public:
	SpiderObjectPool();
	SpiderObjectPool(const SpiderObjectPool&) = delete;
	SpiderObjectPool& operator= (const SpiderObjectPool&) = delete;
	~SpiderObjectPool();
	Spider* getSpider();
	void ReturnSpider(Spider* s);
};
#endif _FleaObjectPool

