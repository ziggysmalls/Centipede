#include "GridManager.h"
#include "Game Components/TEAL/CommonElements.h"
#include "GridCell.h"

#include "SpawnGrid.h"
#include "PlayerManager.h"
GridManager* GridManager::ptrInstance = nullptr;
GridManager::GridManager()
{
	
}
void GridManager::Instantiate()
{
	Instance();
	
	Instance().Player1Grid = new SpawnGrid();
	Instance().Player2Grid = new SpawnGrid();
	Instance().CurrentGrid = Instance().Player1Grid;


}
SpawnGrid* GridManager::privateGetSpawnGrid()
{
	return CurrentGrid;
}

void GridManager::privateSpawnMushrooms()
{
	CurrentGrid->SpawnMushrooms();
}
void GridManager::privateRegenMushroomGrid()
{
	CurrentGrid->RegenMushroomGrid();
}
int GridManager::privateReturnMushrooms()
{
	return CurrentGrid->ReturnMushrooms();
}

void GridManager::privateClearGridPosition(float xCoord, float yCoord)
{
	CurrentGrid->ClearGridPosition(xCoord, yCoord);
}

float GridManager::privateConvertGridUnitsToFloat(int gridCoord)
{
	return CurrentGrid->ConvertGridUnitsToFloat(gridCoord);
}

int GridManager::privateConvertFloatToGridUnits(float floatCoord)
{
	return CurrentGrid->ConvertFloatToGridUnits(floatCoord);
}

bool GridManager::privateCheckGridPosition(float xCoord, float yCoord)
{
	return CurrentGrid->CheckGridPosition(xCoord, yCoord);
}

sf::Vector2f GridManager::privateGetGridPosition(float xCoord, float yCoord)
{
	return CurrentGrid->GetGridPosition(xCoord, yCoord);
}


void GridManager::privateSpawnMushroomAtPosition(float xCoord, float yCoord)
{
	CurrentGrid->SpawnMushroomAtPosition(xCoord, yCoord);
}
float GridManager::privateConvertGridUnitsToFloatCentipedeOffset(int gridCoord)
{
	return CurrentGrid->ConvertGridUnitsToFloatCentipedeOffset(gridCoord);
}

void GridManager::privateSwapGrids()
{
	if (CurrentGrid == Player1Grid)
	{
		CurrentGrid->SaveMushroomLocations();
		CurrentGrid->ClearGrid();
		CurrentGrid = Player2Grid;
		CurrentGrid->LoadInMushroomsForGrid();
	}
	else if (CurrentGrid == Player2Grid)
	{
		CurrentGrid->SaveMushroomLocations();
		CurrentGrid->ClearGrid();
		CurrentGrid = Player1Grid;
	
		CurrentGrid->LoadInMushroomsForGrid();
	}
}

SpawnGrid::Obstacle GridManager::privateInspect(int row, int col)
{
	return CurrentGrid->Inspect(row, col);
}

void GridManager::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

//void GridManager::privateSpawnGridObjectAtPosition(float xCoord, float yCoord)
//{
//	CurrentGrid->SpawnGridObjectAtPosition(xCoord, yCoord);
//}
void GridManager::privateConvertToPoisonMushroom(float xCoord, float yCoord)
{
	CurrentGrid->ConvertToPoisonMushroom(xCoord, yCoord);
}
bool GridManager::privateCheckIfPoisoned(float xCoord, float yCoord)
{
	return CurrentGrid->CheckIfPoisonMushroom(xCoord, yCoord);
}


