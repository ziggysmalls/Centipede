#include "Game Components/TEAL/CommonElements.h"
#include "Splash.h"
#include "Blaster.h"
#include "Mushroom.h"
#include "Bullet.h"
#include "GridCell.h"

#include "KeyBoardInput.h"
#include "AttractorInput.h"
#include "InputController.h"
#include "Flea.h"
#include "Spider.h"
#include "GridManager.h"
#include "GridCellFactory.h"
#include "MushroomFactory.h"
#include "SpiderFactory.h"
#include "ScorpionFactory.h"
#include "FleaFactory.h"
#include "PoisonMushroom.h"
#include "PoisonMushroomFactory.h"
#include "CentipedeHeadFactory.h"
#include "CentipedeBodyFactory.h"
#include "BlasterFactory.h"
#include "PlayerManager.h"
#include "BulletFactory.h"
#include "WaveManager.h"
#include "CritterManager.h"
#include "HUDManager.h"
#include "GameManager.h"
void Splash::Initialize()
{
	CentipedeHeadFactory::Initialize();
	GridManager::Instantiate();
	GridManager::SpawnMushrooms();
	WaveManager::ParseFile();
	PlayerManager::CreatePlayers(new KeyBoardInput, 0);
	BulletFactory::Initialize();
	FleaFactory::Initialize();
	SpiderFactory::Initialize();
	ScorpionFactory::Initialize();
	MushroomFactory::Initialize();
	PoisonMushroomFactory::Initialize();
	CentipedeBodyFactory::Initialize();
	HUDManager::Display();
	HUDManager::Draw();
	CollisionTestPair<Bullet, Mushroom>();
	CollisionTestPair<Blaster, Mushroom>();
	CollisionTestPair<Blaster, Flea>();
	CollisionTestPair<Blaster, Spider>();
	CollisionTestPair<Blaster, Centipede>();
	CollisionTestPair<Bullet, Flea>();
	CollisionTestPair<Spider, Mushroom>();
	CollisionTestPair<Bullet, PoisonMushroom>();
	CollisionTestPair<Bullet, Spider>();
	CollisionTestPair<Bullet, Scorpion>();
	CollisionTestPair<Scorpion, Mushroom>();
	CollisionTestPair<CentipedeHead, Bullet>();
	CollisionTestPair<Bullet, CentipedeBody>();
	CollisionTestPair<Blaster, CentipedeBody>();
	CollisionTestPair<Blaster, CentipedeHead>();
	
	
}
