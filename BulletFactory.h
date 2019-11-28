#ifndef _BulletFactory
#define _BulletFactory

#include "Game Components/TEAL/CommonElements.h"
// Forward Declaration
#include "Bullet.h"
#include "BulletObjectPool.h"
#include "CommandSoundPlay.h"
class GameObject;
class BulletFactory
{
private:

	BulletObjectPool myBulletPool;
	static BulletFactory* InstancePtr;
	CommandSoundPlay* pSound;
	BulletFactory() = default;
	BulletFactory(const BulletFactory&) = delete;
	BulletFactory& operator =(const BulletFactory&) = delete;
	~BulletFactory();
	static BulletFactory& Instance()
	{
		if (!InstancePtr)
			InstancePtr = new BulletFactory();
		return *InstancePtr;
	};
	void privateInitialize();
	Bullet* privateCreateBullet(float xpos, float ypos);
	void privateReportSound();
	void privateTerminate();
	void privateRecycleBullet(GameObject* m);
	
public:

	static Bullet* CreateBullet(float xpos,float ypos) { return Instance().privateCreateBullet(xpos,ypos); };
	static void Initialize() { Instance().privateInitialize(); };
	static void RecycleBullet(GameObject* m) { Instance().privateRecycleBullet(m); };
	static void ReportSound() { Instance().privateReportSound(); };
	static void Terminate() {Instance().privateTerminate();
};
	
};
#endif



