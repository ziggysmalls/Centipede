#ifndef _GlyphObjectPool
#define _GlyphObjectPool
#include <stack>
class Glyph;
class GlyphObjectPool
{
private:
	std::stack<Glyph*> recycledItems;
public:
	GlyphObjectPool();
	GlyphObjectPool(const GlyphObjectPool&) = delete;
	GlyphObjectPool& operator= (const GlyphObjectPool&) = delete;
	~GlyphObjectPool();
	Glyph* getGlyph();
	void ReturnGlyph(Glyph* g);



};
#endif _FleaObjectPool

