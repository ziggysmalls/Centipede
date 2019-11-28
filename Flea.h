#ifndef _Flea
#define _Flea
#include "Game Components/TEAL/CommonElements.h"
class Bullet;
class GridCell;
class CommandSound;
class Flea :public GameObject
{
public :
	Flea();
	~Flea();
	Flea(const Flea&) = delete;
	Flea& operator=(const Flea&) = delete;
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	void Initialize();
	virtual void Collision(GameObject* GO) {};
	virtual void Collision(Bullet* other);
	const float fleaSpeed = 2.0f;
private:
	int fleaHealth = 2;
	float speedMultiplier;
	const float yInitial = -8;
	const float MushroomChance = 5.0f;
	const  int windowWidth = 480;
	
	sf::Vector2f Pos;
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;
};
#endif // !_Flea


