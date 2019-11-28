#include "Scorpion.h"
#include "Bullet.h"
#include "GridManager.h"
#include "CritterManager.h"
#include "GridCell.h"
#include "ScorpionFactory.h"
#include  "Mushroom.h"
#include  "WaveManager.h"
#include "ExplosionFactory.h"

Scorpion::Scorpion()
{
	bitmap = ResourceManager::GetTextureBitmap("Scorpion");
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Scorpion"), 4, 1, 15);
	MainSprite.SetAnimation(0, 3, true, true);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(1, 1);
	MainSprite.setPosition(Pos);
	SetCollider(MainSprite, bitmap, true);
	
	
	
	
}
void Scorpion::Initialize()
{
	float yPosition;
	float xPosition = -8.0f;
	yPosition = fmod(rand(), yUpperbound /1.5f);
	yPosition = GridManager::ConvertFloatToGridUnits(yPosition);
	yPosition = GridManager::ConvertGridUnitsToFloat(yPosition);
	yPosition += MainSprite.getTextureRect().height / 2.0f;
	ScorpionFactory::ReportSound();
	ScorpionHealth = 1;
	direction = (rand() % 2);
	if (direction == 0)
	{
		MainSprite.scale(1, 1);
		direction = -1;
		xPosition = windowWidth + (MainSprite.getTextureRect().width / 2.0f);
	}
	else if (direction == 1)
	{
		MainSprite.scale(-1, 1);
		direction = 1;
		xPosition = 0 - (MainSprite.getTextureRect().width / 2.0f);
	}
	Pos.x = xPosition;
	Pos.y = yPosition;
	
	RegisterCollision<Scorpion>(*this);
}

void Scorpion::Update()
{

	Pos.x += ScorpionSpeed * direction;
	MainSprite.Update();
	MainSprite.setPosition(Pos);

	if (direction == -1 && Pos.x <= 0)
	{
		CritterManager::ResetScorpion();
		CritterManager::CritterDestroyed(this);
		MarkForDestroy();
	}

	else if (direction == 1 && Pos.x >= WindowManager::Window().getSize().x)
	{
		CritterManager::ResetScorpion();
		CritterManager::CritterDestroyed(this);
		MarkForDestroy();
	}
	
	
}
void Scorpion::Alarm0()
{
	
}
void Scorpion::Draw()
{
	WindowManager::Window().draw(MainSprite);
}
void Scorpion::Collision(Bullet* other)
{
	ScorpionHealth -= 1;
	if (ScorpionHealth == 0)
	{
		CritterManager::ResetScorpion();
		MarkForDestroy();
		ScorpionFactory::ReportDeath();
	}
	CritterManager::CritterDestroyed(this);
	other->MarkForDestroy();
	ExplosionFactory::CreateExplosion(Pos.x, Pos.y);
	
}
void Scorpion::Collision(Mushroom* other)
{
	if (GridManager::CheckGridPosition(Pos.x, Pos.y) == true)
	{
		GridManager::ConvertToPoisonMushroom(Pos.x, Pos.y);
	}
}
void Scorpion::Destroy()
{
	
	ScorpionHealth = 1;
	ScorpionFactory::PauseSound();
	DeregisterCollision<Scorpion>(*this);
	
}
