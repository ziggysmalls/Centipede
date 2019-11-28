#include "GridCell.h"
#include "Mushroom.h"
#include "Flea.h"
#include "GridManager.h"
GridCell::GridCell()
{}

void GridCell::Initialize()
{
	health = 4;
	Pos.x = 0.0f;
	Pos.y = 0.0f;
}
void GridCell::Repair()
{
	
}

int GridCell::GetHealth()
{
	return health;
}
sf::Vector2f GridCell::GetPosition()
{
	return Pos;
}
bool GridCell::isPoisoned()
{
	return isPoison; 
}
