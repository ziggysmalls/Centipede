#include "Explosion.h"

void Explosion::Initialize(float xpos, float ypos)
{
	//think of this object like a particle
	//set sprite and animation
	frames = 0;
	Pos.x = xpos;
	Pos.y = ypos;
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Explosion"), 3, 2, 60.0f, 0, 5, true, true);
	MainSprite.SetAnimation(0, 7, true, false);

	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(2.0f, 2.0f);

	MainSprite.setPosition(Pos);
	SetDrawOrder(1000);
}

void Explosion::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Explosion::Update()
{
	//after six frames have played, destroy this instance
	MainSprite.Update();
	frames++;
	if (frames >= 6)
		MarkForDestroy();
}
