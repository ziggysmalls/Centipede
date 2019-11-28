#include "Bullet.h"
#include "Blaster.h"
#include "SoundManager.h"
#include "CommandSoundPlay.h"
#include "BulletFactory.h"
Bullet::Bullet()
{

	bitmap = ResourceManager::GetTextureBitmap("Bullet");
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Bullet"), 1, 1);
	MainSprite.SetAnimation(0, 0,false,false);

	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, (MainSprite.getTextureRect().height / 2.0f));
	MainSprite.setScale(1, 1);
	SetCollider(MainSprite, bitmap, true);
	RegisterCollision<Bullet>(*this);
}
Bullet::~Bullet()
{

}
void Bullet::Initialize(Blaster* blaster, float startPosX, float startPosY)
{
	//set up callback pointer to player
	player = blaster;
	//set position 
	Pos.x = startPosX;
	Pos.y = startPosY;
	RegisterCollision<Bullet>(*this);
	BulletFactory::ReportSound();
	
}

void Bullet::Update()
{
	
	
		this->Pos.y -= bulletSpeed;
		// checks for bullet going off screen, mark it for destroy
		if (Pos.y < -MainSprite.getTextureRect().height)
		{
			MarkForDestroy();
		}
		// updates sprite position
		MainSprite.setPosition(this->Pos);
	
	
	
}

void Bullet::Destroy()
{
	// call back to player to reload bullet 
	player->Reload();
	DeregisterCollision<Bullet>(*this);
	
}
void Bullet::Draw()
{
	WindowManager::Window().draw(MainSprite);
}
