#ifndef _PlayerManager
#define _PlayerManager

#include "Game Components/TEAL/CommonElements.h"
#include "InputController.h"
class Blaster;
class SpawnGrid;

struct PlayerData
{
	int numLives;
	int playerNumber;
	int currWave;
	int Score;
	Blaster* player;
	SpawnGrid* playerGrid;
};

class PlayerManager
{
private:
	static PlayerManager* InstancePtr;

	PlayerManager();											
	PlayerManager(const PlayerManager&) = delete;				
	PlayerManager& operator=(const PlayerManager&) = delete;	
	~PlayerManager() {};

	static PlayerManager& Instance()        // Access reference (all public methods will be static)
	{
		if (!InstancePtr)
			InstancePtr = new PlayerManager;
		return *InstancePtr;
	};


	
	void privateCheckPlayerLives();
	void privateSetPlayerGrid();
	void privateUpdateCurrentPlayerWave();
	void SwapPlayers();
	void InitializePlayerProfiles();
	void privSetPlayerScore(int s);
	Blaster* privateReturnCurrentPlayer();

	void privateCreatePlayers(InputController* input, int np);
	static int const size = 3; // Number of Players
	Blaster* BlasterPtr;
	Blaster* currentPlayer;
	int currPlyrIndex = 0;
	int index = 0;

	static int const numberPlayers = 3;
	PlayerData playerProfiles[numberPlayers]{};

	enum Mode { OnePlayer, TwoPlayer, Attractor };
	Mode currentMode;

	void PlayerMode(PlayerManager::Mode m);
	
	

public:
	static void CreatePlayers(InputController* input, int np) { Instance().privateCreatePlayers(input, np); };
	static void SetPlayerGrid() { Instance().privateSetPlayerGrid(); }
	static void Terminate();
	static Blaster* ReturnCurrentPlayer() { return Instance().privateReturnCurrentPlayer(); };
	static void CheckPlayerLives() { Instance().privateCheckPlayerLives(); };
	static void UpdateCurrentPlayerWave() { Instance().privateUpdateCurrentPlayerWave(); };
	static void SetPlayerScore(int s) { Instance().privSetPlayerScore(s); };

};

#endif _PlayerManager
