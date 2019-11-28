#ifndef _GridCell
#define _GridCell
#include "Game Components/TEAL/CommonElements.h"
class Mushroom;
class Flea;

class GridCell :public GameObject
{
public:
	GridCell();
	virtual int GetHealth();
	bool isPoisoned();
	virtual void Repair();
	virtual void Initialize();
	virtual sf::Vector2f GetPosition();

protected:

	bool isPoison;
	int health;
	sf::Vector2f Pos;
};
#endif _Grid// !_Grid


