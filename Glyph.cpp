
#include "Glyph.h"
#include "SpriteSheet.h"
#include "Game Components/TEAL/ResourceManager.h"
#include <assert.h>

Glyph::Glyph()
{
	sprsheet = nullptr;
	cellIndex = 0;
	position = sf::Vector2f(0, 0);
}
void Glyph::Initialize()
{
	sprsheet = nullptr;
	cellIndex = 0;
	position = sf::Vector2f(0, 0);
}

Glyph::Glyph(SpriteSheet* sheet, int cellInd, sf::Vector2f pos)
{
	sprsheet = sheet;
	position = pos;
	cellIndex = cellInd;
}
void Glyph::Initialize(SpriteSheet* sheet, int cellInd, sf::Vector2f pos)
{
	sprsheet = sheet;
	position = pos;
	cellIndex = cellInd;
}

void Glyph::Draw()
{
	assert(sprsheet != nullptr);

	sprsheet->Draw(cellIndex, position);
}
