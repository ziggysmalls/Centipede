#ifndef _BlasterObjectPool
#define _BlasterObjectPool
#include <stack>
#include "Game Components/TEAL/CommonElements.h"
class Blaster;
class BlasterObjectPool
{
private:
	std::stack<Blaster*> recycledItems;
public:
	BlasterObjectPool();
	BlasterObjectPool(const BlasterObjectPool&) = delete;
	BlasterObjectPool& operator= (const BlasterObjectPool&) = delete;
	~BlasterObjectPool();
	Blaster* getBlaster();
	void ReturnBlaster(Blaster* f);



};
#endif _FleaObjectPool

