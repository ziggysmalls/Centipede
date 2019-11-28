#include "AttractorInput.h"
#include "Blaster.h"
#include "FleaFactory.h"
#include "SpiderFactory.h"
#include "ScorpionFactory.h"
#include "GridManager.h"
#include "SpawnGrid.h"
#include "Game Components/TEAL/CommonElements.h"
AttractorInput::AttractorInput()
	

{
	player = nullptr;
	Roll = 0;
	
}
void AttractorInput::Input(Blaster* blaster)
{
	player = blaster;
	
}

void AttractorInput::ControllerUpdate()
{
	
	Roll = rand() % 40;
	if (Roll == 0)
	{
		int PrevMove = DirectionX;
		if (PrevMove == 1) DirectionX = -1;
		else DirectionX = 1;
	}
	if (Roll == 1)
	{
		int PrevDir = DirectionY;
		if (PrevDir == -1) DirectionY = 1;
		else DirectionY = -1;
	}

	Pos.x = player->getPos().x;
	Pos.y = player->getPos().y;
	Pos.x += (int)DirectionX * blasterSpeed;
	Pos.y += (int)DirectionY * blasterSpeed;
	Tools::Clamp<float>(Pos.x, spriteBumper, WindowManager::Window().getSize().x - spriteBumper);
	Tools::Clamp<float>(Pos.y, yUpperbound, yLowerbound);
	player->setPos(Pos);
	player->Fire();

}

void AttractorInput::Destroy()
{

}
