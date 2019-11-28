#include "GlyphObjectPool.h"

#include "Game Components/TEAL/CommonElements.h"
#include "Glyph.h"


GlyphObjectPool::GlyphObjectPool()
{

}

GlyphObjectPool::~GlyphObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Glyph* GlyphObjectPool::getGlyph()
{
	Glyph* m;

	if (recycledItems.empty())
	{
		ConsoleMsg::WriteLine("New Glyph"); // For illustration purposes

		m = new Glyph();
	}
	else
	{
		ConsoleMsg::WriteLine("Recycled Glyph"); // For illustration purposes

		m = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

		// Tell the object to register itself to the scene
		m->RegisterToCurrentScene();
	}

	return m;
}
void GlyphObjectPool::ReturnGlyph(Glyph* m)
{
	recycledItems.push(static_cast<Glyph*>(m));
}