#include "GameManager.h"
#include "Splash.h"
#include "AttractorMode.h"
#include "TwoPlayerMode.h"
GameManager* GameManager::InstancePtr = nullptr;
void GameManager::privateTerminate()
{
	
}
void GameManager::privateInitialize()
{
	RegisterInput(InputFlags::KeyPressed);
}
GameManager::~GameManager()
{
	DeregisterInput();
}
void GameManager::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	
	if (k == sf::Keyboard::Num1)
	{
		SceneManager::ChangeScene(new Splash);
		
	}
	if (k == sf::Keyboard::Num2)
	{
		SceneManager::ChangeScene(new TwoPlayerMode);

	}
		
}