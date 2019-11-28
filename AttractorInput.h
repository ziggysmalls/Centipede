#ifndef _AtractorInput
#define _AtractorInput
#include "InputController.h"
class AttractorInput : public InputController
{
public:
	
	AttractorInput();
	void Destroy();
	void Input(Blaster* blaster);
	void ControllerUpdate();
	

	
	

private:


	
	int Roll;
	int DirectionX = 1;
	int DirectionY = 1;
	sf::Vector2f Pos;
	const float blasterSpeed = 5;
	// upper bound of player area
	const float yUpperbound = 404;

	// lower bound of player area
	const float	yLowerbound = 488;
	// starting x position
	const float startX = 240;
	// starting y position
	const float startY = 488;
	// bumper used to properly keep the player within the x axis
	const float spriteBumper = 8;

	
};
#endif
