#include "Spider.h"
#include "Bullet.h"
#include "Blaster.h"
#include "Mushroom.h"
#include "GridManager.h"
#include "CritterManager.h"
#include "WaveManager.h"
#include "ExplosionFactory.h"
#include "SpiderFactory.h"
Spider::Spider()
{
	//set sprite, animation, and collider
	bitmap = ResourceManager::GetTextureBitmap("Spider");
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Spider"), 4, 2, 15);
	MainSprite.setScale(2, 2);
	
	SetCollider(MainSprite, bitmap, true);
	

}
void Spider::Initialize()
{
	speed = SpiderSpeed;
	MainSprite.SetAnimation(0, 7, true, true);
	MainSprite.Play();
	int InitialDirection;
	// randomizing the start side of the spider 
	InitialDirection = rand() % 2;
	if (InitialDirection == 0)
	{
		direction = false;
		DirectionMultiplier = -1;
		Pos.x = SpiderRightPos;
		Pos.y = SpiderSpawnHeight;
	}
	if (InitialDirection == 1)
	{
		direction = true;
		DirectionMultiplier = 1;
		Pos.x = SpiderLeftPos;
		Pos.y = SpiderSpawnHeight;
	}

	RegisterCollision<Spider>(*this);
	MainSprite.setPosition(Pos);
	MoveDiagonalDown();
	SpiderFactory::ReportSound();
}
void Spider::Update()
{
	if (Pos.x <= (0 - (MainSprite.getTextureRect().width / 2.0f)) && direction == false)
	{
		DeregisterCollision<Spider>(*this);
		MarkForDestroy();
		CritterManager::ResetSpider();
		CritterManager::CritterDestroyed(this);
	}
	if (Pos.x >= (windowWidth + (MainSprite.getTextureRect().width / 2.0f)) && direction == true)
	{
		DeregisterCollision<Spider>(*this);
		MarkForDestroy();
		CritterManager::ResetSpider();
		CritterManager::CritterDestroyed(this);
	}

	// randomizing direction 
	if (OrdersQueue.empty() == true)
	{
		int MoveChance;
		MoveChance = rand() % 4;
		if (MoveChance == 0)
			MoveUp();
		if (MoveChance == 1)
			MoveDown();
		if (MoveChance == 2)
			MoveDiagonalUp();
		if (MoveChance == 3)
			MoveDiagonalDown();
	}

	if (OrdersQueue.empty() == false)
	{
		// once the orders are created the position of the spider is updated based on those orders
		// temporders is set to the front of the Queue
		TempOrders = OrdersQueue.front();
		// setting the barriers for the spider
		// if the yPosition of the spider is less than the upperbound
		if (Pos.y + TempOrders.YPosition < SpiderUpperBound)
		{
			// empties the queue 
			EmptyQueue();
			// then randomizes between the two movements it could make down or diagonal
			int MoveDownChance;
			MoveDownChance = rand() % 2;
			if (MoveDownChance == 0)
				MoveDown();
			if (MoveDownChance == 1)
				MoveDiagonalDown();
			TempOrders = OrdersQueue.front();
		}
		// same as  before just if its at the bottom of the bounded area
		if (Pos.y + TempOrders.YPosition > SpiderLowerBound)
		{
			EmptyQueue();
			int MoveUpChance;
			MoveUpChance = rand() % 2;
			if (MoveUpChance == 0)
				MoveUp();
			if (MoveUpChance == 1)
				MoveDiagonalUp();
		}
		Pos.x += TempOrders.XPosition;
		Pos.y += TempOrders.YPosition;
		OrdersQueue.pop();
	}

	MainSprite.Update();
	MainSprite.setPosition(Pos);


}
void Spider::EmptyQueue()
{
	// method to empty queue orders
	while (OrdersQueue.empty() == false)
	{
		OrdersQueue.pop();
	}
}

void Spider::MoveUp()
{

	int QueueSize;
	QueueSize = (rand() % SpiderMaxLength) + SpiderMinLength;
	// generating queue orders for up movements
	for (int i = 0; i < QueueSize; i++)
	{
		TempOrders.XPosition = 0;
		TempOrders.YPosition = -speed;
		OrdersQueue.push(TempOrders);
	}
}

void Spider::MoveDown()
{
	int QueueSize;
	QueueSize = (rand() % SpiderMaxLength) + SpiderMinLength;
	// generating queue orders for down movements
	for (int i = 0; i < QueueSize; i++)
	{
		TempOrders.XPosition = 0.0f;
		TempOrders.YPosition = speed;
		OrdersQueue.push(TempOrders);
	}
}

void Spider::MoveDiagonalUp()
{
	int QueueSize;
	QueueSize = (rand() % SpiderMaxLength) + SpiderMinLength;
	// generating queue orders for up diagonal movements
	for (int i = 0; i < QueueSize; i++)
	{
		TempOrders.XPosition = speed * DirectionMultiplier;
		TempOrders.YPosition = -speed;
		OrdersQueue.push(TempOrders);
	}
}

void Spider::MoveDiagonalDown()
{
	int QueueSize;
	QueueSize = (rand() % SpiderMaxLength) + SpiderMinLength;
	// generating queue orders for down diagonal movements
	for (int i = 0; i < QueueSize; i++)
	{
		TempOrders.XPosition = speed * DirectionMultiplier;
		TempOrders.YPosition = speed;
		OrdersQueue.push(TempOrders);
	}
}


void Spider::Alarm0()
{
	
}
void Spider::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Spider::Destroy()
{
	SpiderFactory::PauseSound();
	DeregisterCollision<Spider>(*this);
	EmptyQueue();
}



void Spider::Collision(Bullet* other)
{
	other->MarkForDestroy();
	CritterManager::ResetSpider();
	CritterManager::CritterDestroyed(this);
	MarkForDestroy();  
	ExplosionFactory::CreateExplosion(Pos.x, Pos.y);
	SpiderFactory::ReportDeath();
}

void Spider::Collision(Mushroom* other)
{
	other->MarkForDestroy();
}

