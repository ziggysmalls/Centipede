#include "CentipedeHead.h"
#include "MoveState.h"
#include "MoveFSM.h"
#include "GridManager.h"
#include "CritterManager.h"
#include "MovementCollection.h"
#include "CentipedeBody.h"
#include "CentipedeHeadFactory.h"
#include "Bullet.h"
#include "Blaster.h"

CentipedeHead::CentipedeHead()
{
	bitmap = ResourceManager::GetTextureBitmap("CentipedeHead");
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("CentipedeHead"), 8, 2, 10);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(2, 2);
	SPEED = 2.0f;
	
	Pos = sf::Vector2f(GridManager::ConvertGridUnitsToFloatCentipedeOffset(15), GridManager::ConvertGridUnitsToFloatCentipedeOffset(0));
	startPos = Pos;
	SetCollider(MainSprite, bitmap);
	MainSprite.SetAnimation(0, 7);
	pCurrentState = &MoveFSM::StateMoveRightAndDownwards;
	index = 0;
}
void CentipedeHead::Initialize()
{
	
	RegisterCollision<CentipedeHead>(*this);
	MainSprite.setPosition(Pos);
	pCurrentState->Show();  // For Debugging and Tracking purposes
	row = GridManager::ConvertFloatToGridUnits(Pos.y);
	col = GridManager::ConvertFloatToGridUnits(Pos.x);
	CritterManager::HeadCreated();
	if (counter == 0)
	{
		CentipedeHeadFactory::ReportSound();
		counter++;
	}
	
}
void CentipedeHead::Initialize(int r, int c, const MoveState* st)
{
	RegisterCollision<CentipedeHead>(*this);
	MainSprite.setPosition(Pos);
	pCurrentState = st;
	MainSprite.Play();
	MainSprite.SetFrame(13);
	MainSprite.Update();
	row = GridManager::ConvertFloatToGridUnits(Pos.y);
	col = GridManager::ConvertFloatToGridUnits(Pos.x);
	CritterManager::HeadCreated();
	
}
void CentipedeHead::Initialize(sf::Vector2f pos, const MoveState* st, int ind) 
{
	Pos = pos;
	RegisterCollision<CentipedeHead>(*this);
	MainSprite.setPosition(Pos);
	pCurrentState = st;
	MainSprite.Play();
	MainSprite.SetFrame(13);
	MainSprite.Update();
	row = GridManager::ConvertFloatToGridUnits(Pos.y);
	col = GridManager::ConvertFloatToGridUnits(Pos.x);
	index = ind;
	CritterManager::HeadCreated();
}
void CentipedeHead::Initialize(sf::Vector2f pos, const MoveState* st, int ind, Centipede* pPrev)
{
	Pos = pos;
	RegisterCollision<CentipedeHead>(*this);
	MainSprite.setPosition(Pos);
	pCurrentState = st;
	MainSprite.Play();
	
	MainSprite.Update();
	row = GridManager::ConvertFloatToGridUnits(Pos.y);
	col = GridManager::ConvertFloatToGridUnits(Pos.x);
	index = ind;
	this->setPrev(pPrev);
	CritterManager::HeadCreated();
}

void CentipedeHead::Update()
{

	

	Pos.x += SPEED * pCurrentState->GetMoveOffsets(index)->coloffset;
	Pos.y += SPEED * pCurrentState->GetMoveOffsets(index)->rowoffset;

	
	index++;
	
	// fps refer to the number of pixel movements based on the SPEED
	if (index >= pCurrentState->GetFrames())
	{
		pCurrentState->Show();
		index = 0;
		row += pCurrentState->GetMoveOffsets(index)->rowoffset;
		col += pCurrentState->GetMoveOffsets(index)->coloffset;
		
		if (prev != nullptr)
		{
			this->prev->pCurrentState = pCurrentState;
		}
		pCurrentState = pCurrentState->GetNextState(this);

		SetAnimations();
	}
	MainSprite.Update();
	MainSprite.setPosition(Pos);
	counter--;
}
void CentipedeHead::Draw()
{
	WindowManager::Window().draw(MainSprite);
}
void CentipedeHead::SetAnimations()
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
void CentipedeHead::Collision(Bullet* other)
{
	other->MarkForDestroy();
	
	if (prev != nullptr)
	{
		// Create a Head at prev
		this->prev->ChangeToHead(index);
		this->prev = nullptr;
	}
	GridManager::SpawnMushroomAtPosition(Pos.x, Pos.y);
	ExplosionFactory::CreateExplosion(Pos.x, Pos.y);
	CritterManager::HeadDestroyed(this);
	CentipedeHeadFactory::ReportDeath();
	MarkForDestroy();
}

void CentipedeHead::Collision(Blaster* other)
{
	other->MarkForDestroy();

}




void CentipedeHead::Destroy()
{
	index = 0;
	Pos = startPos;
	DeregisterCollision<CentipedeHead>(*this);
}