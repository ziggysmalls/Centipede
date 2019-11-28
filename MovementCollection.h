#ifndef _MovementCollection
#define _MovementCollection
struct OffsetArray
{
	int rowoffset;
	int coloffset;
	
	
	
	OffsetArray(int c, int r) : rowoffset(r), coloffset(c) {};
};

class MovementCollection
{
public:
	static const OffsetArray OffsetsStraightRight;
	static const OffsetArray OffsetsTurnUpEndRight;
	static const OffsetArray OffsetsTurnDownEndRight;
	static const OffsetArray OffsetsStraightLeft;
	static const OffsetArray OffsetsTurnUpEndLeft;
	static const OffsetArray OffsetsTurnDownEndLeft;
};
#endif