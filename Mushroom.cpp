#include "Mushroom.h"
#include "Bullet.h"
#include "Blaster.h"
#include "GridCell.h"
#include "GridManager.h"
#include "MushroomFactory.h"
Mushroom::Mushroom()
{
	bitmap = &ResourceManager::GetTextureBitmap("Mushroom");
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2,1,0,7,false);
	MainSprite.setOrigin(0,0);
	MainSprite.setScale(1,1);
	SetCollider(MainSprite, *bitmap);
	isPoison = false;
}
void Mushroom::Initialize(float xPosition, float yPosition)
{
	isPoison = false;
	health = MaxHealth;
	MainSprite.SetAnimation(0, 3, false, false);
	MainSprite.SetFrame(0);
	mX = xPosition;
	mY = yPosition;
	Pos = sf::Vector2f(xPosition, yPosition);
	RegisterCollision<Mushroom>(*this);
}
void Mushroom::Update()
{
	MainSprite.Update();
	MainSprite.setPosition(Pos);
}
void Mushroom::Repair()
{
	Initialize(mX, mY);
}
int Mushroom::GetHealth()
{
	return health;
}
void Mushroom::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Mushroom::Collision(Bullet* other)
{
	if (health > 1)
	{
		health--;
		MainSprite.NextFrame();
	}
	if (health <=1)
	{
  		GridManager::ClearGridPosition(Pos.y, Pos.x);
		MarkForDestroy();
		MushroomFactory::ReportDeath();
	}
	
	other->MarkForDestroy();
}

void Mushroom::Destroy()
{
	
	health = 4;
	DeregisterCollision<Mushroom>(*this);
}
