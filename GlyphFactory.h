#ifndef _GlyphFactory
#define _GlyphFactory

#include <stack>
#include "Game Components/TEAL/CommonElements.h"
#include "GlyphObjectPool.h"
#include "SpriteSheet.h"
class Glyph;
class GlyphFactory
{
private:
	GlyphObjectPool myGlyphPool;
	static GlyphFactory* InstancePtr;
	GlyphFactory() {};
	GlyphFactory(const GlyphFactory&) {};
	GlyphFactory& operator= (const GlyphFactory&) {};
	~GlyphFactory() {};

	static GlyphFactory& Instance()
	{
		if (!InstancePtr)
			InstancePtr = new GlyphFactory();
		return *InstancePtr;
	};
	
	Glyph* privateCreateGlyph();
	
	Glyph* privateCreateGlyph(SpriteSheet* sheet, int cellInd, sf::Vector2f pos);
	void privateRecycleGlyph(GameObject* GC);
public:

	static Glyph* CreateGlyph() { return Instance().privateCreateGlyph (); };
	static Glyph* CreatGlyph(SpriteSheet* sheet, int cellInd, sf::Vector2f pos) { return Instance().privateCreateGlyph(sheet, cellInd, pos); };
	static void RecycleGlyph(GameObject* GC) { Instance().privateRecycleGlyph(GC); };
	static void Terminate();

};
#endif

