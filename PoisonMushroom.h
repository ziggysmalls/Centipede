#ifndef _PoisonMushroom
#define _PoisonMushroom


#include "Game Components/TEAL/CommonElements.h"
#include "GridCell.h"
#include "Mushroom.h"
class Bullet;
class GridCell;
class PoisonMushroom :public Mushroom
{
public:
	PoisonMushroom() ;
	virtual void Update();
	virtual void Draw() ;
	virtual void Destroy();
	virtual void Collision(GameObject* GO) {};
	virtual void Collision(Bullet* other) ;
	virtual int GetHealth();
	void Initialize(float xPosition, float yPosition, int previousHealth);
private:
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap* bitmap;

	int currentHealth;
	int MaxHealth = 4;
};
#endif

