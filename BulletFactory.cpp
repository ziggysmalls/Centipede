#include "BulletFactory.h"
#include "Bullet.h"
#include "PlayerManager.h"
#include "SoundManager.h"

BulletFactory* BulletFactory::InstancePtr = nullptr;
Bullet* BulletFactory::privateCreateBullet(float xpos,float ypos)
{
	Bullet* BulletPtr = myBulletPool.getBullet();


	BulletPtr->SetExternalManagement(RecycleBullet);

 	
	
	
	BulletPtr->Initialize(PlayerManager::ReturnCurrentPlayer(),xpos,ypos);

	return BulletPtr;
}
void BulletFactory::privateInitialize()
{
	pSound = SoundManager::GetSoundCommand(SoundManager::SoundEvents::FireSound);
}
void BulletFactory::privateReportSound()
{
	SoundManager::SendSoundCommand(pSound);
	SoundManager::ProcessSounds();
}
void BulletFactory::privateRecycleBullet(GameObject* f)
{
	myBulletPool.ReturnBullet(static_cast<Bullet*>(f));
}
BulletFactory::~BulletFactory()
{
	
}
void BulletFactory::privateTerminate()
{
	
	delete InstancePtr;
	InstancePtr = nullptr;
}
