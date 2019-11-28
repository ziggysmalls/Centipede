#ifndef _Explosion
#define _Explosion

#include "Game Components\TEAL\CommonElements.h"

class Explosion : public GameObject
{
public:
	Explosion() { };
	void Initialize(float xpos, float ypos);
	virtual void Draw();
	virtual void Update();

private:
	int frames;
	AnimatedSprite MainSprite;
	sf::Vector2f Pos;

};
#endif 