#include "PoisonMushroom.h"
#include "GridCell.h"
#include "GridManager.h"
#include "Bullet.h"
#include "PoisonMushroomFactory.h"
PoisonMushroom::PoisonMushroom()
{
	health = MaxHealth;
	isPoison = true;
	bitmap = &ResourceManager::GetTextureBitmap("Mushroom");
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2);
	MainSprite.setOrigin(0, 0);
	MainSprite.setScale(1, 1);
	Pos.x = 0;
	Pos.y = 0;
	SetCollider(MainSprite, *bitmap, true);


}
void PoisonMushroom::Initialize(float xPosition, float yPosition,int previousHealth)
{
	health = previousHealth;
	isPoison = true;
	MainSprite.SetAnimation(4, 7, false, false);
	
	for (int i = 0; i < (MaxHealth - previousHealth); i++)
	{
		
		MainSprite.NextFrame();
		MainSprite.SetFrame((MainSprite.GetFrameCount() / 2) + MainSprite.GetFrame());

	}

	Pos = sf::Vector2f(xPosition, yPosition);
	RegisterCollision<PoisonMushroom>(*this);
	MainSprite.setPosition(Pos);
}
void PoisonMushroom::Update()
{
	MainSprite.Update();
	MainSprite.setPosition(Pos);
}
int PoisonMushroom::GetHealth()
{
	return health;
}
void PoisonMushroom::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void PoisonMushroom::Collision(Bullet* other)
{
	if (health > 1)
	{
		health--;
		MainSprite.NextFrame();
	}
	if (health <= 1)
	{
        GridManager::ClearGridPosition(Pos.y, Pos.x);
		MarkForDestroy();
		PoisonMushroomFactory::ReportDeath();
		
	}
	other->MarkForDestroy();
}

void PoisonMushroom::Destroy()
{
	
	health = 4;
	DeregisterCollision<PoisonMushroom>(*this);
}
