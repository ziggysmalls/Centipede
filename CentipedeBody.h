#ifndef _CentipedeBody
#define _CentipedeBody
#include "Game Components/TEAL/CommonElements.h"
#include "Centipede.h"
class CentipedeBody : public Centipede
{
public:
	CentipedeBody();
	~CentipedeBody() = default ;
	CentipedeBody(const CentipedeBody&) = delete;
	CentipedeBody& operator = (const CentipedeBody&) = delete;
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	virtual void Split();
	void Initialize();
	void Initialize(int r, int c, const MoveState* st, int index);
	void Initialize(sf::Vector2f pos, const MoveState* st, int index);
	virtual void ChangeToHead(int ind);
	void Initialize(Centipede* next);
	virtual Centipede* getPrev() { return prev; };
	virtual Centipede* getNext() { return next; };
	int getIndex() { return index; };
	virtual void setPrev(Centipede* p) { prev = p; };
	virtual void setNext(Centipede* n) { next = n; };
	virtual void Collision(GameObject* other) {};
	void Collision(Bullet* other);
	void Collision(Blaster* other);
	void SetAnimations();
private:
	
	int col;
	int row;
	int count = 0;
	float SPEED = 2.0f;
	
	//sf::Vector2f Pos;
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;
};
#endif

