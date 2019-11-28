#ifndef _Bullet
#define _Bullet
#include "Game Components/TEAL/CommonElements.h"
class Blaster;
class Mushroom;
class PoisonMushroom;
class CommandSoundPlay;
class Bullet : public GameObject
{
public:
	Bullet();
	~Bullet();
	void Initialize(Blaster* player, float xPos, float yPos);
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	virtual void Collision(GameObject* GO) {};
	

	
	

private:
	const float bulletSpeed = 10;
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;
	sf::Vector2f Pos;
	float startX;
	float startY;
	Blaster *player;
	
};
#endif // !_Bullet


