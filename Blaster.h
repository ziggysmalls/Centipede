#ifndef _Blaster
#define _Blaster
#include "Game Components/TEAL/CommonElements.h"

//forward Declaration
class Bullet;
class Mushroom;
class Spider;
class Flea;
class Centipede;
class InputController;

class Blaster : public GameObject
{
public:
	
	Blaster();
	~Blaster();
	Blaster(const Blaster&) = delete;
	Blaster& operator = (const Blaster&) = delete;
	void Initialize(InputController* Controller);
	void Initialize();
	;
	virtual void Update();
	virtual void Draw();
	virtual void Collision(GameObject* GO) {};
	void Collision(Mushroom* other);
	void Collision(Spider* other);
	void Collision(Flea* other);
	void Collision(Centipede* other);
	virtual void Destroy();
	void Up();
	void Down();
	void Left();
	void Right();
	void Fire();
	void Reload();
	void DeathCheck();
	void setPos(sf::Vector2f Pos);
	void setInput(InputController* input);
	void Death(); 
	void Respawn();
	sf::Vector2f getPos();
	
	
	// setting blaster speed
	const float blasterSpeed = 5;
	// upper bound of player area
	const float yUpperbound = 404;

	// lower bound of player area
	const float	yLowerbound = 488;
	// starting x position
	const float startX = 240;
	// starting y position
	const float startY = 488;
	// bumper used to properly keep the player within the x axis
	const float spriteBumper = 8;

	private:
	
	
	float xPrev;
	float yPrev;
	bool isLoaded;
	int playerLives;



	const static int initialLives = 2;
	Bullet* bullet;
	sf::Vector2f Pos;
	sf::Vector2f respawnPos;
	InputController* input;

	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;

	

};
#endif

