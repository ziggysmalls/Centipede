#ifndef _HUDManager
#define _HUDManager
#include "GlyphFactory.h"
#include "SpriteSheet.h"
#include "PlayerFont.h"
class Glyph;
class HUDManager
{
private:
	static HUDManager* InstancePtr;

	HUDManager() {};											
	HUDManager(const HUDManager&) = delete;				
	HUDManager& operator=(const HUDManager&) = delete;	
	~HUDManager() 
	{
		p1Score.clear();
		p1Lives.clear();
		p2Score.clear();
		p2Lives.clear();
	};

	static HUDManager& Instance()        // Access reference (all public methods will be static)
	{
		if (!InstancePtr)
			InstancePtr = new HUDManager;
		return *InstancePtr;
	};

	PlayerFont font;
	
	std::list<Glyph*> p1Score;
	std::list<Glyph*> p1Lives;
	std::list<Glyph*> p2Score;
	std::list<Glyph*> p2Lives;
	std::list<Glyph*> HighScore;
	int currHighScore = 16666;
	const int numCharP1Score = 6;
	const int numCharP2Score = 30;
	const int numCharP1Lives = 10;
	const int numCharP2Lives = 20;
	const int numHighScore = 13;
	void privateDraw();
	void privateDisplay();
	void privateTerminate();
	void privateComputePlayer1Score(std::string val, int val2);
	void privateComputePlayer2Score(std::string val, int val2);
	void privateComputePlayer1Lives(std::string val);
	void privateComputePlayer2Lives(std::string val);
	void privateUpdateHighScore(int val);
	float nextpos;
public:
	static void Draw() { Instance().privateDraw(); };
	static void Display() {Instance().privateDisplay();};
	static void Terminate() { Instance().privateTerminate(); };
	static void ComputePlayer1Score(std::string val, int val1) { Instance().privateComputePlayer1Score(val, val1); };
	static void ComputePlayer1Lives(std::string val) { Instance().Instance().privateComputePlayer1Lives(val); };
	static void ComputePlayer2Lives(std::string val) { Instance().Instance().privateComputePlayer2Lives(val); };
	static void ComputePlayer2Score(std::string val, int val1) { Instance().privateComputePlayer2Score(val, val1); };

};
#endif

