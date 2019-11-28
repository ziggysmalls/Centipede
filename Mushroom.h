#ifndef _Mushroom
#define _Mushroom
#include "Game Components/TEAL/CommonElements.h"
#include "GridCell.h"
// Forward Declaration
class Bullet;
class Blaster;
class GridCell;
class Mushroom : public GridCell
{
public:
	Mushroom();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	virtual void Collision(GameObject* GO) {};
	virtual void Collision(Bullet* other);
	virtual int GetHealth();
	 virtual void Repair();
	void Initialize(float xPosition, float yPosition);
private:
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap* bitmap;
	
	int currentHealth;
	int MaxHealth = 4;
	float mX;
	float mY;
	
	
}; 
#endif  _Mushroom// !_Mushroom


