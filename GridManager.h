#ifndef _GridManager
#define _GridManager
#include "Game Components/TEAL/CommonElements.h"
#include "SpawnGrid.h"
class SpawnGrid;

class GridManager
{

private:
	static GridManager* ptrInstance;
	GridManager();
	GridManager(const GridManager&) = delete;
	GridManager& operator= (const GridManager&) = delete;
	~GridManager() = default;
	

	
	static GridManager& Instance()    
	{
		if (!ptrInstance)
			ptrInstance = new GridManager();
		return *ptrInstance;
	};
	void privateSpawnMushrooms();
	int privateReturnMushrooms();
	void privateClearGridPosition(float xCoord, float yCoord);
	float privateConvertGridUnitsToFloat(int gridCoord);
	int privateConvertFloatToGridUnits(float floatCoord);
	void privateConvertToPoisonMushroom(float xCoord, float yCoord);
	bool privateCheckGridPosition(float xCoord, float yCoord);
	bool privateCheckIfPoisoned(float xCoord, float yCoord);
	 sf::Vector2f privateGetGridPosition(float xCoord, float yCoord);
	SpawnGrid::Obstacle privateInspect(int row, int col);
	void privateSpawnMushroomAtPosition(float xCoord, float yCoord);
	void privateRegenMushroomGrid();
	void privateSwapGrids();
	SpawnGrid* privateGetSpawnGrid();
	//void privateSpawnGridObjectAtPosition(float xCoord, float yCoord);
	float privateConvertGridUnitsToFloatCentipedeOffset(int gridCoord);
	SpawnGrid* CurrentGrid;
	SpawnGrid* Player1Grid;
	SpawnGrid* Player2Grid;
public:
	static void Instantiate();
	static void Terminate();
	static void SpawnMushrooms() { Instance().privateSpawnMushrooms(); };
	static int ReturnMushrooms() { return Instance().privateReturnMushrooms(); };
	static SpawnGrid* GetSpawnGrid() { return Instance().privateGetSpawnGrid(); };
	static void ClearGridPosition(float xCoord, float yCoord) { Instance().privateClearGridPosition(xCoord, yCoord); };
	static float ConvertGridUnitsToFloat(int gridCoord) {return Instance().privateConvertGridUnitsToFloat(gridCoord); };
	static int ConvertFloatToGridUnits(float floatCoord) { return Instance().privateConvertFloatToGridUnits(floatCoord); };
	static void ConvertToPoisonMushroom(float xCoord, float yCoord) {Instance().privateConvertToPoisonMushroom(xCoord, yCoord);};
	static bool CheckGridPosition(float xCoord, float yCoord) {return Instance().privateCheckGridPosition(xCoord, yCoord);};
	static bool CheckIfPoisoned(float xCoord, float yCoord) { return Instance().CheckIfPoisoned(xCoord, yCoord); };
	static sf::Vector2f GetGridPosition(float xCoord, float yCoord) {return Instance().GetGridPosition(xCoord, yCoord);};
	static SpawnGrid::Obstacle Inspect(int row, int col) { return Instance().privateInspect(row, col); };
	static void SpawnMushroomAtPosition(float xCoord, float yCoord) { Instance().privateSpawnMushroomAtPosition(xCoord, yCoord); };
	static void RegenMushroomGrid() { Instance().privateRegenMushroomGrid(); };
	static void SwapGrids() {Instance().privateSwapGrids();};
	//static void SpawnGridObjectAtPosition(float xCoord, float yCoord) {Instance().privateSpawnGridObjectAtPosition(xCoord, yCoord);};
	static float ConvertGridUnitsToFloatCentipedeOffset(int gridCoord) { return Instance().privateConvertGridUnitsToFloatCentipedeOffset(gridCoord); };
	
};
#endif // !_GridManager


