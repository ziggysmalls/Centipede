#ifndef _SpawnGrid
#define _SpawnGrid
#include "Game Components/TEAL/CommonElements.h"
#include <queue>
class GridCell;
class Mushroom;

class SpawnGrid : public GameObject
{
public:
	SpawnGrid();
	void SpawnMushrooms();
	void ClearGridPosition(float xCoord, float yCoord);
	void SpawnMushroomAtPosition(float xCoord, float yCoord);
	bool CheckGridPosition(float xCoord, float yCoord);
	int ConvertFloatToGridUnits(float floatCoord);
	float ConvertGridUnitsToFloatCentipedeOffset(int gridCoord);
	float ConvertGridUnitsToFloat(int gridCoord);
	//void SpawnGridObjectAtPosition(float xCoord, float yCoord);
	bool CheckIfPoisonMushroom(float xCoord, float yCoord);
	void ConvertToPoisonMushroom(float xCoord, float yCoord);
	int ReturnMushrooms();
	void RegenMushroomGrid();
	void SaveMushroomLocations();
	void LoadInMushroomsForGrid();
	
	void ClearGrid();
	virtual void Destroy();
	sf::Vector2f GetGridPosition(float xCoord, float yCoord);
	enum Obstacle { Clear, Blocked, Edge };
	static const int TOP_PLAYER_ROW = 25;
	static const int BOTTOM_ROW = 30;
	Obstacle Inspect(int row, int col);
private:
	static const int columns = 30;
	static const int rows = 32;
	const int SpawnChance = 7;
	float Offset = 1.0f;
	float yOffset = 8.0f;
	float PixelSize = 16.0f;
	int TotalMushrooms;
	Mushroom* cell[rows][columns];
	std::queue<sf::Vector2f> storedMushrooms;
};
#endif


