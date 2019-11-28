#include "WaveManager.h"
#include "Game Components/TEAL/CommonElements.h"
#include "CritterManager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<assert.h>

using namespace std;
WaveManager* WaveManager::InstancePtr = nullptr;
void WaveManager::privateInitializeWave()
{
	CritterManager::LoadWaveData(&waveArray[ind]);
}

void WaveManager::privateInitializeWave(int w)
{
	CritterManager::LoadWaveData(&waveArray[w]);
	ConsoleMsg::WriteLine("Launching Wave # " + Tools::ToString(w));
	ind += w;
}

void WaveManager::privateUpdateWave()
{
	CritterManager::LoadWaveData(&waveArray[ind]);
}

void WaveManager::privateParseFile()
{
	std::ifstream file;
	std::string buffer;
	int index = 0;

	file.open("resources\\WaveData.txt");

	while (file >> buffer) 
	{
		switch (hash(buffer))
		{
		case Wave:
			file >> buffer;
			index = std::stoi(buffer);
			assert(index >= 0 && index <= 1000);   
			break;
			//Centipede Settings
		case CentipedeLength:    
			file >> buffer;
			waveArray[index].CentipedeLength = std::stoi(buffer);
			assert(waveArray[index].CentipedeLength > 0 && waveArray[index].CentipedeLength <= 20);   
			break;
		case CentipedeSpeed:
			file >> buffer;
			waveArray[index].CentipedeSpeed = std::stoi(buffer);
			assert(waveArray[index].CentipedeSpeed > 0 && waveArray[index].CentipedeSpeed <= 4);   
			break;
		case HeadCount:
			file >> buffer;
			waveArray[index].headCount = std::stoi(buffer);
			assert(waveArray[index].headCount >= 0 && waveArray[index].headCount <= 20); 
			break;
		case HeadSpeed:
			file >> buffer;
			waveArray[index].headSpeed = std::stoi(buffer);
			assert(waveArray[index].headSpeed > 0 && waveArray[index].headSpeed <= 4); 
			break;
			// Flea Settings
		case FleaOn:   
			file >> buffer;
			assert(buffer == ("YES") || buffer == ("NO"));
			waveArray[index].fleaIsOn = (buffer == ("YES"));
			break;
		case TriggerValue:
			file >> buffer;
			waveArray[index].TriggerValue = std::stoi(buffer);
			assert(waveArray[index].TriggerValue >= 0 && waveArray[index].TriggerValue <= 100); 
			break;
			// Scorpion Settings
		case ScorpionOn:  
			file >> buffer;
			assert(buffer == ("YES") || buffer == ("NO"));
			waveArray[index].scorpionIsOn = (buffer == ("YES"));
			break;
		case ScorpionFrequency:
			file >> buffer;
			waveArray[index].scorpionFrequency = std::stof(buffer);
			assert(waveArray[index].scorpionFrequency >= 0.0f && waveArray[index].scorpionFrequency <= 100.0f); 
			break;
			// Spider Settings
		case SpiderOn: 
			file >> buffer;
			assert(buffer == ("YES") || buffer == ("NO"));
			waveArray[index].spiderIsOn = (buffer == ("YES"));
			break;
		case SpiderFrequency:
			file >> buffer;
			waveArray[index].spiderFrequency = std::stof(buffer);
			assert(waveArray[index].spiderFrequency >= 0.0f && waveArray[index].spiderFrequency <= 100.0f); 
			break;
		case SpiderSpeed:
			file >> buffer;
			waveArray[index].spiderSpeed = std::stof(buffer);
			assert(waveArray[index].spiderSpeed > 0.0f && waveArray[index].spiderSpeed <= 20.0f); 
			break;
		default:
			break;
		}
	}
	wavesParsed = index;
	file.close();
}

WaveManager::stringCode WaveManager::hash(std::string const& inString)
{
	if (inString == "Wave:") 
		return Wave;
	if (inString == "CentipedeLength:") 
		return CentipedeLength;
	if (inString == "CentipedeSpeed:") 
		return CentipedeSpeed;
	if (inString == "HeadCount:") 
		return HeadCount;
	if (inString == "HeadSpeed:") 
		return HeadSpeed;
	if (inString == "FleaOn:") 
		return FleaOn;
	if (inString == "TriggerValue:") 
		return TriggerValue;
	if (inString == "ScorpionOn:") 
		return ScorpionOn;
	if (inString == "ScrFrq:") 
		return ScorpionFrequency;
	if (inString == "SpiderOn:") 
		return SpiderOn;
	if (inString == "SpiderFrq:") 
		return SpiderFrequency;
	if (inString == "SpiderSpeed:") 
		return SpiderSpeed;
	return empty;
}

void WaveManager::Terminate()
{
	delete InstancePtr;
	InstancePtr = nullptr;
}

