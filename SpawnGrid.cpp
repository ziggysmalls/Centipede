#include "SpawnGrid.h"
#include "Mushroom.h"
#include "MushroomFactory.h"
#include "PoisonMushroomFactory.h"
#include "GridCellFactory.h"


SpawnGrid::SpawnGrid()
{
	TotalMushrooms = 0;
	cell[rows][columns] = nullptr;
	
	
}

void SpawnGrid::SpawnMushrooms()
{
	int SpawnRoll = 0;
	for (int x= 1; x < rows - 2; x++)
	{	
		for (int y= 0; y < columns; y++)
		{
			
			SpawnRoll = (rand() % 100);
			if (SpawnRoll < SpawnChance)
			{
				
				cell[x][y] = MushroomFactory::CreateMushroom(y* PixelSize, (x * PixelSize) + Offset);
				TotalMushrooms = TotalMushrooms + 1;
			}
			else
			{
				cell[x][y] = nullptr;
			}
		}
	}
	
	ConsoleMsg::WriteLine("TotalMushrooms = " + Tools::ToString(TotalMushrooms));
}

int SpawnGrid::ReturnMushrooms()
{
	return TotalMushrooms;
}



void SpawnGrid::ClearGridPosition(float ycoord, float xcoord)
{
	TotalMushrooms = TotalMushrooms - 1;
  	int arrayY = xcoord / PixelSize;
	int arrayX = ycoord / PixelSize;
	cell[arrayX][arrayY] = nullptr;
	
	ConsoleMsg::WriteLine("TotalMushrooms = " + Tools::ToString(TotalMushrooms));
}

float SpawnGrid::ConvertGridUnitsToFloat(int gridCoord)
{
	float returnFloat;
	if (gridCoord == 0)
	{
		returnFloat = gridCoord * PixelSize;
		return returnFloat;
	}
	else
	{
		returnFloat = gridCoord * PixelSize;
		return returnFloat;
	}
	
}
float SpawnGrid::ConvertGridUnitsToFloatCentipedeOffset(int gridCoord)
{
	float returnFloat;
	if (gridCoord == 0)
	{
		returnFloat = gridCoord * PixelSize + yOffset;
		return returnFloat;
	}
	else
	{
		returnFloat = gridCoord * PixelSize + yOffset;
		return returnFloat;
	}

}
void SpawnGrid::RegenMushroomGrid()
{
	for(int x = 1; x < rows - 2; x++)
	{
		for (int y = 0; y < columns; y++)
		{
			if (cell[x][y] != nullptr && cell[x][y]->GetHealth() < 4)
			{
				cell[x][y]->Repair();
			}
		}
	}
}

int SpawnGrid::ConvertFloatToGridUnits(float floatCoord)
{
	int returnInt;
	int intPixelSize = PixelSize;
	int coordvalue = floatCoord;
	returnInt = (coordvalue - (coordvalue % intPixelSize)) / PixelSize;
	return returnInt;
}

bool SpawnGrid::CheckGridPosition(float xCoord, float yCoord)
{
	int x = ConvertFloatToGridUnits(yCoord);
	int y = ConvertFloatToGridUnits(xCoord);
	if (y >= 0 && y < rows && x < columns)
	{
 		if (this->cell[x][y] != nullptr)
		{
			return true;
		}
		if (cell[x][y] == nullptr)
		{
			return false;
		}
		else
			return false;
	}
	else
		return false;
}
void SpawnGrid::LoadInMushroomsForGrid()
{
		if (storedMushrooms.empty() == true)
		{
			SpawnMushrooms();
		}
		else if (storedMushrooms.empty() == false)
		{
			while (storedMushrooms.empty() == false)
			{
				SpawnMushroomAtPosition(storedMushrooms.front().x, storedMushrooms.front().y);
				storedMushrooms.pop();
			}
		}
}

SpawnGrid::Obstacle SpawnGrid::Inspect(int row, int col)
{
	
	if (row < 0 || row >= rows) return (Obstacle)1;
	if (col < 0 || col >= columns) return (Obstacle)1;
	

	if(row < rows&& col < columns&& cell[row][col] == nullptr) 
		return (Obstacle)0;
	else return (Obstacle)1;
}

void SpawnGrid::SpawnMushroomAtPosition(float xCoord, float yCoord)
{
	int arrayX = ConvertFloatToGridUnits(yCoord);
	int arrayY = ConvertFloatToGridUnits(xCoord);
	float convertedX = ConvertGridUnitsToFloat(arrayY);
 	float convertedY = ConvertGridUnitsToFloat(arrayX);

	if (arrayY > 0 && arrayY < rows && arrayX < columns && CheckGridPosition(xCoord, yCoord) == false)
	{
		cell[arrayX][arrayY] = MushroomFactory::CreateMushroom(convertedX, convertedY);
	}
	TotalMushrooms = TotalMushrooms + 1;
}

sf::Vector2f SpawnGrid::GetGridPosition(float xCoord, float yCoord)
{
	int x = ConvertFloatToGridUnits(xCoord);
	int y = ConvertFloatToGridUnits(yCoord);
	return sf::Vector2f(x, y);
}

//void SpawnGrid::SpawnGridObjectAtPosition(float xCoord, float yCoord)
//{
//	int arrayX = xCoord / PixelSize;
//	int arrayY = (yCoord - Offset) / PixelSize;
//	if (cell[arrayX][arrayY] != nullptr)
//	{
//		cell[arrayX][arrayY]->MarkForDestroy();
//	}
//	cell[arrayX][arrayY] = nullptr;
//	cell[arrayX][arrayY] = GridCellFactory::CreateGridCell();
//}

bool SpawnGrid::CheckIfPoisonMushroom(float xCoord, float yCoord)
{
	int x = ConvertFloatToGridUnits(yCoord);
	int y = ConvertFloatToGridUnits(xCoord);
	if (y >= 0 && y < rows && x >= 0 && x < columns)
	{
		if (cell[x][y] != nullptr && cell[x][y]->isPoisoned() == true)
		{
			return true;
		}
		else if (cell[x][y] != nullptr && cell[x][y]->isPoisoned() == false)
		{
			return false;
		}
	}
	else
		return false;
}

void SpawnGrid::ConvertToPoisonMushroom(float xCoord, float yCoord)
{
	int GridCellX = ConvertFloatToGridUnits(yCoord);
	int GridCellY = ConvertFloatToGridUnits(xCoord);

	int yPos = ConvertGridUnitsToFloat(GridCellX);
	int xPos = ConvertGridUnitsToFloat(GridCellY);
	if (CheckIfPoisonMushroom(xCoord, yCoord) == false && CheckGridPosition(xCoord, yCoord) == true)
	{
		int previousHealth = cell[GridCellX][GridCellY]->GetHealth();
		cell[GridCellX][GridCellY]->MarkForDestroy();
		cell[GridCellX][GridCellY] = nullptr;
		cell[GridCellX][GridCellY] = PoisonMushroomFactory::CreatePoisonMushroom(xPos, yPos, previousHealth);
	}

}

void SpawnGrid::ClearGrid()
{
	for (int x = 1; x < rows - 2; x++)
	{
		for (int y = 0; y < columns; y++)
		{
			if (cell[x][y] != nullptr)
			{
				cell[x][y]->MarkForDestroy();
				cell[x][y] = nullptr;
			}
		}
	}
	
}
void SpawnGrid::SaveMushroomLocations()
{
	for (int i = 1; i < rows - 2; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (cell[i][j] != nullptr)
			{
				storedMushrooms.push(cell[i][j]->GetPosition());
			}
		}
	}
}

void SpawnGrid::Destroy()
{
	//ClearGrid();
}


