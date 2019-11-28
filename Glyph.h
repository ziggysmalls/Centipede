// Glyph

#ifndef _Glyph
#define _Glyph

#include "SFML\Graphics.hpp"
#include "Game Components/TEAL/CommonElements.h"
class SpriteSheet; // forward declaration

class Glyph : public GameObject
{
private:
	SpriteSheet* sprsheet;
	int cellIndex;
	sf::Vector2f position;
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;

public:
	Glyph();
	void Initialize();
	Glyph(SpriteSheet* sheet, int cellInd, sf::Vector2f pos);
	void Initialize(SpriteSheet* sheet, int cellInd, sf::Vector2f pos);
	virtual void Draw();
};


#endif _Glyph