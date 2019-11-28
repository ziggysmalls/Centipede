#include "GlyphFactory.h"
#include "Glyph.h"
#include "GlyphObjectPool.h"

GlyphFactory* GlyphFactory::InstancePtr = nullptr;

Glyph* GlyphFactory::privateCreateGlyph()
{
	Glyph* GPtr = myGlyphPool.getGlyph();

	GPtr->SetExternalManagement(RecycleGlyph);

	GPtr->Initialize();

	return GPtr;
}
Glyph* GlyphFactory::privateCreateGlyph(SpriteSheet* sheet, int cellInd, sf::Vector2f pos)

{
	Glyph* GPtr = myGlyphPool.getGlyph();

	GPtr->SetExternalManagement(RecycleGlyph);

	GPtr->Initialize(sheet,cellInd,pos);

	return GPtr;
}
void GlyphFactory::privateRecycleGlyph(GameObject* GC)
{
	myGlyphPool.ReturnGlyph(static_cast<Glyph*>(GC));
}
void GlyphFactory::Terminate()
{
	delete InstancePtr;
	InstancePtr = nullptr;
}

