#include "CentipedeBody.h"
#include "SpawnGrid.h"
#include "MoveState.h"
#include "MovementCollection.h"
#include "MoveFSM.h"
#include "CentipedeHeadFactory.h"
#include "Blaster.h"
#include "Bullet.h"
#include "CritterManager.h"
#include "CentipedeBodyFactory.h"
CentipedeBody::CentipedeBody()
{
	
	bitmap = ResourceManager::GetTextureBitmap("CentipedeBody");
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("CentipedeBody"), 8, 2, 16.0f, 0, 15, true);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(2, 2);
	Pos = sf::Vector2f(GridManager::ConvertGridUnitsToFloatCentipedeOffset(15), GridManager::ConvertGridUnitsToFloatCentipedeOffset(0));
	startPos = Pos;
}
// splitting method used to split specific points in the body that have collided with the bullet 
void CentipedeBody::Split()
{
	
	if (this->getPrev() == nullptr)
	{
		this->next->setPrev(nullptr);  
		MarkForDestroy();
	}
	 
	else 
	{
		this->next->setPrev(nullptr);  // Fix next pointer
		this->prev->ChangeToHead(index);
		MarkForDestroy();
	}
		
}
void CentipedeBody::ChangeToHead(int ind)
{
	CentipedeHead* tmp = CentipedeHeadFactory::CreateCentipedeHead(this->Pos, this->pCurrentState, ind, this->getPrev());
	CritterManager::HeadCreated(tmp);
	
	if (this->prev != nullptr)
	{
		this->prev->setNext(tmp);
	}
	CritterManager::BodyDestroyed(this);
	MarkForDestroy();

}
void CentipedeBody::Initialize()
{
	RegisterCollision<CentipedeBody>(*this);
	
	index = 0;
	SetCollider(MainSprite, bitmap);
	MainSprite.setPosition(Pos);
	

	
}
void CentipedeBody::Initialize(int r,int c, const MoveState* st, int index)
{
	RegisterCollision<CentipedeBody>(*this);
	MainSprite.setPosition(Pos);
	pCurrentState = st;
	MainSprite.Play();
	MainSprite.SetFrame(13);
	MainSprite.Update();
	row = GridManager::ConvertFloatToGridUnits(Pos.y);
	col = GridManager::ConvertFloatToGridUnits(Pos.x);


}
void CentipedeBody::Initialize(Centipede* next)
{
	RegisterCollision<CentipedeBody>(*this);
	MainSprite.setPosition(Pos);
	MainSprite.Play();
	MainSprite.SetFrame(13);
	MainSprite.Update();
	this->next = next;
	row = GridManager::ConvertFloatToGridUnits(Pos.y);
	col = GridManager::ConvertFloatToGridUnits(Pos.x);
}
void CentipedeBody::Initialize(sf::Vector2f pos, const MoveState* st, int index)
{
	RegisterCollision<CentipedeBody>(*this);
	MainSprite.setPosition(Pos);
	pCurrentState = st;
	Pos = pos;
	MainSprite.Play();
	MainSprite.SetFrame(13);
	MainSprite.Update();
	row = GridManager::ConvertFloatToGridUnits(Pos.y);
	col = GridManager::ConvertFloatToGridUnits(Pos.x);


}

void CentipedeBody::Update()
{
	

	if (pCurrentState != nullptr)
	{
		Pos.x += SPEED * pCurrentState->GetMoveOffsets(index)->coloffset;
		Pos.y += SPEED * pCurrentState->GetMoveOffsets(index)->rowoffset;
		index++;
		
		MainSprite.setPosition(Pos);

		if (index >= pCurrentState->GetFrames())
		{
			

			if (prev != nullptr)
			{
				this->prev->pCurrentState = pCurrentState;
			}
			index = 0;
			SetAnimations();
		}
	}
	MainSprite.Update();
	MainSprite.setPosition(Pos);
}

void CentipedeBody::Collision(Bullet* other)
{
	ExplosionFactory::CreateExplosion(Pos.x, Pos.y);
	GridManager::SpawnMushroomAtPosition(Pos.x, Pos.y);
	other->MarkForDestroy();
	this->Split();
 	
 	CritterManager::BodyDestroyed(this);
	CentipedeBodyFactory::ReportDeath();
	
}

void CentipedeBody::Collision(Blaster* other)
{
	other->MarkForDestroy();

}

void CentipedeBody::SetAnimations()
{
	if (pCurrentState->GetMoveOffsets(index) == &MovementCollection::OffsetsStraightLeft)
	{
		MainSprite.SetAnimation(0, 7, true, true);
		MainSprite.setScale(2.0f, 2.0f);

	}
	else if (pCurrentState->GetMoveOffsets(index) == &MovementCollection::OffsetsStraightRight)
	{
		MainSprite.SetAnimation(0, 7, true, true);
		MainSprite.setScale(-2.0f, 2.0f);
	}
	else if (pCurrentState->GetMoveOffsets(index) == &MovementCollection::OffsetsTurnDownEndLeft)
	{
		MainSprite.SetAnimation(8, 15, true, true);
		MainSprite.setScale(2.0f, 2.0f);
	}
	else if (pCurrentState->GetMoveOffsets(index) == &MovementCollection::OffsetsTurnDownEndRight)
	{
		MainSprite.SetAnimation(8, 15, true, true);
		MainSprite.setScale(-2.0f, 2.0f);
	}
	else if (pCurrentState->GetMoveOffsets(index) == &MovementCollection::OffsetsTurnUpEndLeft)
	{
		MainSprite.SetAnimation(8, 15, true, true);
		MainSprite.setScale(2.0f, -2.0f);
	}
	else if (pCurrentState->GetMoveOffsets(index) == &MovementCollection::OffsetsTurnUpEndRight)
	{
		MainSprite.SetAnimation(8, 15, true, true);
		MainSprite.setScale(-2.0f, -2.0f);
	}
}
void CentipedeBody::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void CentipedeBody::Destroy()
{
	index = 0;
	Pos = startPos;
	DeregisterCollision<CentipedeBody>(*this);

}
