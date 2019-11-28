// Ezequiel Arrieta 2019
#include "PlayerManager.h"
#include "Blaster.h"
#include "BlasterFactory.h"
#include "SpawnGrid.h"
#include "WaveManager.h"
#include "CritterManager.h"
#include "GridManager.h"
#include "HUDManager.h"
#include "AttractorInput.h"

PlayerManager* PlayerManager::InstancePtr = nullptr;
PlayerManager::PlayerManager()
{
	currentPlayer = nullptr;
}


void PlayerManager::privateCreatePlayers(InputController* input, int np)
{
	BlasterPtr = BlasterFactory::CreateBlaster(input);
	currentPlayer = BlasterPtr;
	index++;
	currentMode = (Mode)np;

	if(currentMode == OnePlayer || currentMode == TwoPlayer)
		currPlyrIndex++;
	InitializePlayerProfiles();
}


void  PlayerManager::privSetPlayerScore(int s)
{
	playerProfiles[currPlyrIndex].Score += s;
	if(playerProfiles[currPlyrIndex].playerNumber == 1)
		HUDManager::ComputePlayer1Score(Tools::ToString(playerProfiles[currPlyrIndex].Score), playerProfiles[currPlyrIndex].Score);
	if (playerProfiles[currPlyrIndex].playerNumber == 2)
		HUDManager::ComputePlayer2Score(Tools::ToString(playerProfiles[currPlyrIndex].Score), playerProfiles[currPlyrIndex].Score);
	
}


void PlayerManager::privateCheckPlayerLives()
{
	switch (currentMode)
	{
		// one player case
	case PlayerManager::OnePlayer:
		if (playerProfiles[currPlyrIndex].numLives <= 0)
		{
			GridManager::RegenMushroomGrid(); // Regenerate the Mushrooms
			
			playerProfiles[currPlyrIndex].player->Death();   // Destroy the Player
			HUDManager::ComputePlayer1Lives(Tools::ToString(playerProfiles[currPlyrIndex].numLives));
			CreatePlayers(new AttractorInput, 2);


		}
		else
		{
			GridManager::RegenMushroomGrid();// Regenerate the Mushrooms
			currentPlayer->Respawn();
			CritterManager::ResetWave();
			playerProfiles[currPlyrIndex].numLives--;
			HUDManager::ComputePlayer1Lives(Tools::ToString(playerProfiles[currPlyrIndex].numLives));

			
		}
		break;
		// two player case 
	case PlayerManager::TwoPlayer:
		if (playerProfiles[currPlyrIndex].numLives <= 0)
		{
			playerProfiles[currPlyrIndex].player->Death();
			GridManager::RegenMushroomGrid(); // Regenerate the Mushrooms
			CreatePlayers(new AttractorInput,2);
			
		}
		else
		{
			GridManager::RegenMushroomGrid(); // Regenerate the Mushrooms
			playerProfiles[currPlyrIndex].numLives--; // decrease lives
			if (playerProfiles[currPlyrIndex].playerNumber == 1) // check to compute specific players lives
				HUDManager::ComputePlayer1Lives(Tools::ToString(playerProfiles[currPlyrIndex].numLives));
			if (playerProfiles[currPlyrIndex].playerNumber == 2) // check to compute specific players lives
				HUDManager::ComputePlayer2Lives(Tools::ToString(playerProfiles[currPlyrIndex].numLives));
			
	 		CritterManager::ResetWave(); // Reset Wave 
			GridManager::SwapGrids(); // Swap Grid 

			SwapPlayers(); // swap players 
		}
		break;
		// attractor case
	case PlayerManager::Attractor:
		CritterManager::ResetWave();
		GridManager::RegenMushroomGrid();
		playerProfiles[currPlyrIndex].numLives = 3;
		currentPlayer->Respawn();

		break;
	default:
		break;
	}
}

void PlayerManager::SwapPlayers()
{
	// function to swap players. 	
	if (playerProfiles[currPlyrIndex].playerNumber == 1)
	{
		
		currPlyrIndex++;
		WaveManager::InitializeWave(playerProfiles[currPlyrIndex].currWave);
		playerProfiles[currPlyrIndex].player->Respawn(); 
	}
	else if (playerProfiles[currPlyrIndex].playerNumber == 2)
	{
		currPlyrIndex--;
		WaveManager::InitializeWave(playerProfiles[currPlyrIndex].currWave);
		playerProfiles[currPlyrIndex].player->Respawn();

	}
}

void PlayerManager::PlayerMode(Mode m)
{
	InitializePlayerProfiles();
	switch (m)
	{
	case PlayerManager::OnePlayer:
		currPlyrIndex = 1;
		break;
	case PlayerManager::TwoPlayer:
		currPlyrIndex = 2;
		break;
	case PlayerManager::Attractor:
		currPlyrIndex = 0;
		break;
	default:
		assert(false);
		break;
	}
	this->currentMode = m;
}



Blaster* PlayerManager::privateReturnCurrentPlayer()
{
	return currentPlayer;
}

void PlayerManager::privateUpdateCurrentPlayerWave()
{
	playerProfiles[currPlyrIndex].currWave++;
	WaveManager::InitializeWave(playerProfiles[currPlyrIndex].currWave);
}

void PlayerManager::InitializePlayerProfiles()
{
	for (int i = 0; i < numberPlayers; i++)
	{
		playerProfiles[i].player = BlasterPtr;
		playerProfiles[i].numLives = 3;
		playerProfiles[i].playerNumber = i; 

		playerProfiles[i].currWave = 0;
		playerProfiles[i].Score = 0;
	}
	WaveManager::InitializeWave(playerProfiles[currPlyrIndex].currWave);

}
void PlayerManager::privateSetPlayerGrid()
{
	playerProfiles[currPlyrIndex].playerGrid = GridManager::GetSpawnGrid();
}


void PlayerManager::Terminate()
{
	delete InstancePtr;
	InstancePtr = nullptr;
}