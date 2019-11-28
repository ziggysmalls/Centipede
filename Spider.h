#ifndef _Spider
#define _Spider
#include "Game Components/TEAL/CommonElements.h"
#include <queue>
class Bullet;
class Mushroom;
class CommandSoundLoop;
class Spider : public GameObject
{
public:
	struct SpiderOrders
	{
		float XPosition;
		float YPosition;
	};

	Spider();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	virtual void Alarm0();
	void Initialize();

	
	virtual void Collision(GameObject* other) {};
	void Collision(Bullet* other);
	void Collision(Mushroom* other);

	void EmptyQueue();
	void MoveUp();
	void MoveDown();
	void MoveDiagonalUp();
	void MoveDiagonalDown();
	

private:
	bool direction;
	int DirectionMultiplier;
	float speed;

	sf::Vector2f Pos;

	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;
	CommandSoundLoop* pSound;
	std::queue<SpiderOrders> OrdersQueue;
	SpiderOrders TempOrders;

	
	
	
	const float SpiderSpeed = 3.0f;
	
	const float SpiderUpperBound = 312;
	const float SpiderLowerBound = 488;
	const int windowWidth = 480;
	const int SpiderMinLength = 9;
	const int SpiderMaxLength = 32;
	const float SpiderLeftPos = -8;
	const float SpiderRightPos = 488;
	const float SpiderSpawnHeight = 312;
	
	
	
};
#endif

