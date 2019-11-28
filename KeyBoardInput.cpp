#include "KeyBoardInput.h"
#include "Blaster.h"
#include "FleaFactory.h"
#include "SpiderFactory.h"
#include "ScorpionFactory.h"
#include "GridManager.h"
#include "Game Components/TEAL/CommonElements.h"
KeyBoardInput::KeyBoardInput()
{
	player = nullptr;
	
	
}
void KeyBoardInput::Input(Blaster* blaster)
{
	player = blaster;
	
}
void KeyBoardInput::ControllerUpdate()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) player->Left();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) player->Right();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) player->Up();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) player->Down();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) player->Fire();
	// for debugging
	
	
}

void KeyBoardInput::Destroy()
{
	
}
