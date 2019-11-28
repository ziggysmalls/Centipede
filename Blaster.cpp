// Ezequiel Arrieta 2019
#include "Blaster.h"
#include "Bullet.h"
#include "Spider.h"
#include "Mushroom.h"
#include "Flea.h"
#include "BulletFactory.h"
#include "InputController.h"
#include "GridManager.h"
#include "PlayerManager.h"
#include "ScoreManager.h"


Blaster::Blaster()
{
	// Blaster Constructor that takes in input controller
	bitmap = ResourceManager::GetTextureBitmap("Blaster");
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Blaster"), 1, 1);
	MainSprite.SetAnimation(0, 1);
	MainSprite.SetFrame(0);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, (MainSprite.getTextureRect().height / 2.0f) - 2);
	MainSprite.setScale(1, 1);
	Pos = sf::Vector2f(startX, startY);
	MainSprite.setPosition(Pos);
	respawnPos = Pos;
	playerLives = initialLives;
	SetCollider(MainSprite, bitmap, true);
	RegisterCollision<Blaster>(*this);

	bullet = nullptr;
	
	
	
	SetDrawOrder(10000);
}
void Blaster::Initialize()
{
	// initializer function for the start of the game and subsequent deaths 
	Pos = sf::Vector2f(startX, startY);
	MainSprite.setPosition(Pos);

	isLoaded = true;
	SetCollider(MainSprite, bitmap, true);
	RegisterCollision<Blaster>(*this);

	

	SetDrawOrder(10000);
}
void Blaster::Initialize(InputController* Controller)
{
	Pos = sf::Vector2f(startX, startY);
	MainSprite.setPosition(Pos);
	input = Controller;
	input->Input(this);
	isLoaded = true;
	SetCollider(MainSprite, bitmap, true);
	RegisterCollision<Blaster>(*this);

}
void Blaster::setInput(InputController* inputC)
{
	input = inputC;
	input->Input(this);
}
void Blaster::Reload()
{
	//change the sprite from unloaded to loaded
	//clear active bullet
	bullet = nullptr;
	isLoaded = true;
}
void Blaster::Update()
{
	input->ControllerUpdate();
	ScoreManager::ProcessScores();
}

sf::Vector2f Blaster::getPos()
{
	return this->Pos;
}

void Blaster::Fire()
{
	if (isLoaded == true)
	{
		isLoaded = false;
		//fire the bullet, and store it in the bullet pointer
		bullet = BulletFactory::CreateBullet(Pos.x, Pos.y);
	}
}
void Blaster::DeathCheck()
{
	PlayerManager::CheckPlayerLives();
}
void Blaster::Death()
{
	MarkForDestroy();
}
void Blaster::Respawn()
{
	MainSprite.setPosition(Pos);
	Pos = respawnPos;
}
void Blaster::Up()
{
	//store previous  y position
	yPrev = Pos.y;

	// updates position and uses the blaster speed to move
	Pos.y -= blasterSpeed;

	// uses Clamp to keep the player within the player area
	Tools::Clamp<float>(Pos.y, yUpperbound, yLowerbound);

	// updates the sprites position
	MainSprite.setPosition(Pos);
}
void Blaster::Down()
{
	// stores previous y position
	yPrev = Pos.y;

	// updates position based on blaster speed
	Pos.y += blasterSpeed;

	// uses Clamp to keep the player within the player area
	Tools::Clamp<float>(Pos.y, yUpperbound, yLowerbound);

	// updates sprite position
	MainSprite.setPosition(Pos);
}
void Blaster::Left()
{
	xPrev = Pos.x;

	// updates x position based on the blaster speed
	Pos.x -= blasterSpeed;

	// clamps the x position based on the size of the window along the x axis
	Tools::Clamp<float>(Pos.x, spriteBumper, WindowManager::Window().getSize().x - spriteBumper);

	// updates the sprites position
	MainSprite.setPosition(Pos);
}
void Blaster::Right()
{
	// stores previous x position
	xPrev = Pos.x;

	// updates position based on blaster speed
	Pos.x += blasterSpeed;

	// uses Clamp on the x position based on the size of the window along the x axis
	Tools::Clamp<float>(Pos.x, spriteBumper, WindowManager::Window().getSize().x - spriteBumper);

	//updates the sprites position
	MainSprite.setPosition(Pos);
}
void Blaster::Destroy()
{
	
	playerLives--;
	DeregisterInput();
	DeregisterCollision<Blaster>(*this);
}
Blaster::~Blaster()
{
	input = nullptr;
	delete input;
}
void Blaster::Collision(Mushroom* other)
{
	Pos.x = xPrev;
	Pos.y = yPrev;
}
void Blaster::Collision(Spider* other)
{
	other->MarkForDestroy();
	DeathCheck();
}

void Blaster::Collision(Flea* other)
{
	DeathCheck();
}
void Blaster::setPos(sf::Vector2f Pos)
{
	this->Pos = Pos;
	xPrev = Pos.x;
	yPrev = Pos.y;
	MainSprite.setPosition(Pos);
}
void Blaster::Collision(Centipede* other)
{
	DeathCheck();
}
void Blaster::Draw()
{
	WindowManager::Window().draw(MainSprite);
}
