#ifndef _CentipedeHeadObjectPool
#define _CentipedeHeadObjectPool
#include <stack>
#include "Game Components/TEAL/CommonElements.h"
class CentipedeHead;
class CentipedeHeadObjectPool
{
private:
	std::stack<CentipedeHead*> recycledItems;
public:
	CentipedeHeadObjectPool();
	CentipedeHeadObjectPool(const CentipedeHeadObjectPool&) = delete;
	CentipedeHeadObjectPool& operator= (const CentipedeHeadObjectPool&) = delete;
	~CentipedeHeadObjectPool();
	CentipedeHead* getCentipedeHead();
	void ReturnCentipedeHead(CentipedeHead* GC);
};
#endif _CentipedeHeadObjectPool

