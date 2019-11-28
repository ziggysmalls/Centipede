#ifndef _CentipedeHead
#define _CentipedeHead
#include "Game Components/TEAL/CommonElements.h"
#include "Centipede.h"
class MoveState;
class Bullet;
class CentipedeHead : public Centipede
{
	public:
	CentipedeHead();
	~CentipedeHead() =default;
	CentipedeHead(const CentipedeHead&) = delete;
	CentipedeHead& operator = (const CentipedeHead&) = delete;
	// initializer methods
	void Initialize();
	void Initialize(int r, int c, const MoveState* st);
	void Initialize(sf::Vector2f pos, const MoveState* st, int index);
	void Initialize(sf::Vector2f pos, const MoveState* st, int index, Centipede* prev);
	// collision methods
	virtual void Collision(GameObject* other) {};
	void Collision(Bullet* other);
	void Collision(Blaster* other);
	// getters and setters
	virtual int getCol() { return col; };
	 virtual int getRow() { return row; };
	 int getIndex() { return index; };
	virtual Centipede* getPrev() { return prev; };
	 virtual Centipede* getNext() { return next; };
	 sf::Vector2f getPos() { return Pos; };
	 virtual void setPrev(Centipede* p) { prev = p; };
	 virtual void setNext(Centipede* n) { next = n; };
	 
	 // virtual functions for all game objects
	 virtual void Update();
	 virtual void Draw();
	 virtual void Destroy();
	 void SetAnimations();

private:
	
	float SPEED;
	int counter = 0;
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;
};
#endif

