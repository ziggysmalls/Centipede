#ifndef _Scorpion
#define _Scorpion
#include "Game Components/TEAL/CommonElements.h"
#include "Mushroom.h"
class GridCell;
class GridManager;
class Bullet;
class Scorpion : public GameObject
{
public:
	Scorpion();
	void Initialize();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	virtual void Alarm0();
	virtual void Collision(GameObject* GO) {};
	void Collision(Bullet* other);
	void Collision(Mushroom* other);
	const float ScorpionSpeed = 2.0f;



private:
	int direction;
	int ScorpionHealth = 1;
	const float yUpperbound = 488;
	const  int windowWidth = 480;
	sf::Vector2f Pos;
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;
};
#endif // !_Scorpion

