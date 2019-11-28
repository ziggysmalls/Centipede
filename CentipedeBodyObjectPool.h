#ifndef _CentipedeBodyObjectPool
#define _CentipedeBodyObjectPool
#include <stack>
#include "Game Components/TEAL/CommonElements.h"
class CentipedeBody;
class CentipedeBodyObjectPool
{
private:
	std::stack<CentipedeBody*> recycledItems;
public:
	CentipedeBodyObjectPool();
	CentipedeBodyObjectPool(const CentipedeBodyObjectPool&) = delete;
	CentipedeBodyObjectPool& operator= (const CentipedeBodyObjectPool&) = delete;
	~CentipedeBodyObjectPool();
	CentipedeBody* getCentipedeBody();
	void ReturnCentipedeBody(CentipedeBody* GC);
};
#endif _CentipedeHeadObjectPool

