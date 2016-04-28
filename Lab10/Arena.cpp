#include "Arena.h"
#include <sstream>
#include <string>

using namespace std;


Arena::Arena()
{
}

bool Arena::addFighter(string info)
{
	istringstream strm;
	strm.str(info);
	string name;
	string type;
	int max_hp = -1;
	int strength = -1;
	int speed = -1;
	int magic = -1;
	string extra = "NULL";

	strm >> name >> type >> max_hp >> strength >> speed >> magic >> extra;

	if(extra != "NULL")
	{
		return false;
	}

	if(max_hp < 0 || strength < 0 || speed < 0 || magic < 0)
	{
		return false;
	}

	for(int i = 0; i < fighters.size(); i++)
	{
		if(name == fighters[i]->getName())
		{
			return false;
		}
	}

	if(max_hp > 0 && strength > 0 && speed > 0 && magic > 0)
	{
		if(type == "A")
		{
			Archer* archer = new Archer(name, max_hp, strength, speed, magic);
			fighters.push_back(archer);
		}
		else if(type == "R")
		{
			Robot* robot = new Robot(name, max_hp, strength, speed, magic);
			fighters.push_back(robot);
		}
		else if(type == "C")
		{
			Cleric* cleric = new Cleric(name, max_hp, strength, speed, magic);
			fighters.push_back(cleric);
		}
		else
		{
			return false;
		}

	}
	else
	{
		return false;
	}

	return true;

}

bool Arena::removeFighter(string name)
{

	for(int i = 0; i < fighters.size(); i++)
	{
		if(name == fighters[i]->getName())
		{
			for(int j = i; j < fighters.size()-1; j++)
			{
				fighters[j] = fighters[j+1];
			}
			fighters.pop_back();
			return true;
		}
	}
	return false;
}

FighterInterface* Arena::getFighter(string name)
{
	for(int i = 0; i < fighters.size(); i++)
	{
		if(name == fighters[i]->getName())
		{
			return fighters[i];
		}
	}
	return NULL;
	
}

int Arena::getSize()
{
	return fighters.size();
}