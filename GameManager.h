#ifndef _GameManager
#define _GameManager
#include "PlayerManager.h"
#include "HUDManager.h"
#include "CritterManager.h"
#include "Game Components/TEAL/ResourceManager.h"
#include "Game Components/TEAL/SceneManager.h"
#include "Game Components/TEAL/CommonElements.h"
class AttractorMode;
class Splash;
class GameManager : public GameObject
{
private:
	static GameManager* InstancePtr;
	static GameManager& Instance()        // Access reference (all public methods will be static)
	{
		if (!InstancePtr)
			InstancePtr = new GameManager;
		return *InstancePtr;
	};
	void privateTerminate();
	void privateInitialize();
	~GameManager();
	

public:
	static void Terminate() { Instance().privateTerminate(); };
	static void Initialize() { Instance().privateInitialize(); };
	virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);
};
#endif // !_GameManager

