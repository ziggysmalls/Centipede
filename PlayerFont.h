

#ifndef _PlayerFont
#define _PlayerFont

#include "SpriteSheet.h"

class PlayerFont : public SpriteSheet
{
public:
	PlayerFont();

	PlayerFont(const PlayerFont&) = delete;
	PlayerFont& operator=(const PlayerFont&) = delete;
	virtual ~PlayerFont() = default;

private:
	virtual int CharToIndex(char& c);
};


#endif _PlayerFont