#ifndef _ScorpionObjectPool
#define _ScoprionObjectPool
#include <stack>
class Scorpion;
class ScorpionObjectPool
{
private:
	std::stack<Scorpion*> recycledItems;
public:
	ScorpionObjectPool();
	ScorpionObjectPool(const ScorpionObjectPool&) = delete;
	ScorpionObjectPool& operator= (const ScorpionObjectPool&) = delete;
	~ScorpionObjectPool();
	Scorpion* getScorpion();
	void ReturnScorpion(Scorpion* s);



};
#endif _FleaObjectPool

