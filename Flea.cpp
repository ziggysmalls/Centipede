#include "Flea.h"
#include "Bullet.h"
#include "GridManager.h"
#include "GridCell.h"
#include "FleaFactory.h"
#include "ExplosionFactory.h"
#include "WaveManager.h"
#include "CritterManager.h"
#include "SoundManager.h"
#include "CommandSoundPlay.h"
Flea::Flea()
{
	// constructor method intializing private variables
	bitmap = ResourceManager::GetTextureBitmap("Flea");
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Flea"), 2, 2, 32,0,3);
	

	MainSprite.setOrigin(0, 0);
	MainSprite.setPosition(Pos);
	SetCollider(MainSprite, bitmap, true);
	
	
	
}
void Flea::Initialize()
{
	// initializing position and randomizing the start x position for the flea
	float xInitial;
	fleaHealth = 2;
	speedMultiplier = 1;
	xInitial = (rand() % (windowWidth - 1));
	xInitial = GridManager::ConvertFloatToGridUnits(xInitial);
	xInitial = GridManager::ConvertGridUnitsToFloat(xInitial);
	Pos.x = xInitial;
	Pos.y = yInitial;
	FleaFactory::ProcessSound();
	RegisterCollision<Flea>(*this);



}
Flea::~Flea()
{
}

void Flea::Update()
{
	
	Pos.y += fleaSpeed * speedMultiplier;
	float MushroomSpawn;
	// randomize the spawn position along the column
	MushroomSpawn = (rand() % 100);
	if (MushroomSpawn <= MushroomChance && fleaHealth > 1)
		GridManager::SpawnMushroomAtPosition(Pos.x, Pos.y);
	MainSprite.Update();
	MainSprite.setPosition(Pos);
	if (Pos.y >= WindowManager::Window().getSize().y)

	{
		CritterManager::CritterDestroyed(this);
		MarkForDestroy();
	}
	CritterManager::SpawnFlea();
	
	
	}
void Flea::Draw()
{
	WindowManager::Window().draw(MainSprite);
}
void Flea::Collision(Bullet* other)
{
	fleaHealth--;
	if (fleaHealth == 1)
	{
		speedMultiplier = 2;
	}
	if (fleaHealth == 0)
	{
		CritterManager::CritterDestroyed(this);
		MarkForDestroy();
		FleaFactory::ReportDeath();
	}
	
	other->MarkForDestroy();
	ExplosionFactory::CreateExplosion(Pos.x,Pos.y);
	
}
void Flea::Destroy()
{
	CritterManager::ResetFlea();
	DeregisterCollision<Flea>(*this);
	
}

