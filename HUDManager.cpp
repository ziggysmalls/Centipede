#include "HUDManager.h"
HUDManager* HUDManager::InstancePtr = nullptr;
void HUDManager::privateDisplay()
{
	std::string p1ScoreString = "00  ";
	std::string p1LivesString = "  @@";
	std::string highScoreString = "  " + std::to_string(currHighScore);
	std::string p2LivesString = "      @@";
	std::string p2ScoreString = "   00";
	
	nextpos = 0;
	for (size_t i = 0; i < p1ScoreString.length(); i++)
	{
		p1Score.push_back(font.GetGlyph(p1ScoreString.at(i), sf::Vector2f(nextpos, 0)));
		nextpos += font.CellWidth();
	}
	for (size_t i = 0; i < p1LivesString.length(); i++)
	{
		p1Lives.push_back(font.GetGlyph(p1LivesString.at(i), sf::Vector2f(nextpos, 0)));
		nextpos += font.CellWidth();
	}
	for (size_t i = 0; i < highScoreString.length(); i++)
	{
		p1Lives.push_back(font.GetGlyph(highScoreString.at(i), sf::Vector2f(nextpos, 0)));
		nextpos += font.CellWidth();
	}

	for (size_t i = 0; i < p2LivesString.length(); i++)
	{
		p2Lives.push_back(font.GetGlyph(p2LivesString.at(i), sf::Vector2f(nextpos, 0)));
		nextpos += font.CellWidth();
	}

	for (size_t i = 0; i < p2ScoreString.length(); i++)
	{
		p2Score.push_back(font.GetGlyph(p2ScoreString.at(i), sf::Vector2f(nextpos, 0)));
		nextpos += font.CellWidth();
	}
	

}
void HUDManager::privateComputePlayer1Score(std::string string, int updateHighScore)
{
	while (p1Score.size() != 0)
	{
		p1Score.front()->MarkForDestroy();
		p1Score.pop_front();
	}
	nextpos = (float)(font.CellWidth() * (numCharP1Score - string.length()));
	for (size_t i = 0; i < string.length(); i++)
	{
		p1Score.push_back(font.GetGlyph(string.at(i), sf::Vector2f(nextpos, 0)));
		nextpos += font.CellWidth();
	}
	if (updateHighScore >= currHighScore)
		privateUpdateHighScore(updateHighScore);
}
void HUDManager::privateComputePlayer1Lives(std::string string)
{
	
	if(p1Lives.size() != 0)
	{
		p1Lives.front()->MarkForDestroy();
		p1Lives.pop_front();
	}
	
	
	
}
void HUDManager::privateComputePlayer2Lives(std::string string)
{

	if (p2Lives.size() != 0)
	{
		p2Lives.back()->MarkForDestroy();
		p2Lives.pop_back();
	}
	
}

void HUDManager::privateUpdateHighScore(int val)
{
	while (HighScore.size() != 0)
	{
		HighScore.front()->MarkForDestroy();
		HighScore.pop_front();
	}

	currHighScore = val;

	
	nextpos = static_cast<float>(font.CellWidth() * (numHighScore));

	// Writes the new score
	for (size_t i = 0; i < std::to_string(currHighScore).length(); i++)
	{
		p1Score.push_back(font.GetGlyph(std::to_string(currHighScore).at(i), sf::Vector2f(nextpos, 0)));
		nextpos += font.CellWidth();
	}

}
void HUDManager::privateComputePlayer2Score(std::string string, int updateHighScore)
{
	while (p2Score.size() != 0)
	{
		p2Score.front()->MarkForDestroy();
		p2Score.pop_front();
	}
	nextpos = (float)(font.CellWidth() * (numCharP2Score - string.length()));
	for (size_t i = 0; i < string.length(); i++)
	{
		p2Score.push_back(font.GetGlyph(string.at(i), sf::Vector2f(nextpos, 0)));
		nextpos += font.CellWidth();
	}
	if (updateHighScore >= currHighScore)
		privateUpdateHighScore(updateHighScore);
}
void HUDManager::privateDraw()
{
	std::list<Glyph*>::iterator it_P1Score;
	for (it_P1Score = p1Score.begin(); it_P1Score != p1Score.end(); it_P1Score++)
		(*it_P1Score)->Draw();
	std::list<Glyph*>::iterator it_P1Lives;
	for (it_P1Lives = p1Lives.begin(); it_P1Lives != p1Lives.end(); it_P1Lives++)
		(*it_P1Lives)->Draw();

	std::list<Glyph*>::iterator it_P2Score;
	for (it_P2Score = p2Score.begin(); it_P2Score != p2Score.end(); it_P2Score++)
		(*it_P2Score)->Draw();

	std::list<Glyph*>::iterator it_P2Lives;
	for (it_P2Lives = p2Lives.begin(); it_P2Lives != p2Lives.end(); it_P2Lives++)
		(*it_P2Lives)->Draw();

	std::list<Glyph*>::iterator it_HighScore;
	for (it_HighScore = HighScore.begin(); it_HighScore != HighScore.end(); it_HighScore++)
		(*it_HighScore)->Draw();
}
void HUDManager::privateTerminate()
{
	delete InstancePtr;
	InstancePtr = nullptr;
}