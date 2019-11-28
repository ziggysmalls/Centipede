#ifndef _Centipede
#define _Centipede

#include "Game Components/TEAL/CommonElements.h"
#include "ExplosionFactory.h"

// Forward declarations

class Bullet;
class Blaster;
class MoveState;
// base class declaration of methods and variables
class Centipede : public GameObject
{
public:
	// Big 4
	Centipede() = default;
	~Centipede() = default;
	Centipede(const Centipede&) = delete;
	Centipede& operator = (const Centipede&) = delete;

	virtual Centipede* getPrev() { return prev; };
	virtual Centipede* getNext() { return next; };
	virtual sf::Vector2f getPos(){return Pos;};
	virtual int getCol() { return col; };
	virtual int getRow() { return row; };
	virtual int getIndex() {return index;};
	virtual void Split() {};
	virtual void ChangeToHead(int index) {};
	virtual void setPrev(Centipede* p) { prev = p; };
	virtual void setNext(Centipede* n) { next = n; };

	const MoveState* pCurrentState = nullptr;

	Centipede* prev = nullptr;
	Centipede* next = nullptr;
	sf::Vector2f Pos;
	sf::Vector2f startPos;
	int index;
	int row;
	int col;


};
#endif