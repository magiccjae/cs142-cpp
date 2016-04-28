#include "POA.h"
#include <sstream>

using namespace std;


POA::POA()
{
}
bool POA::addLot(string info)
{
	istringstream strm;
	strm.str(info);
	string surname = "";
	int LID = 0;
	string type = "";
	string home = "";
	string extra = "";
	bool check_home = false;
	int counter = 0;


	strm >> surname >> LID >> type >> home >> extra;

	if(extra != "")			// check if there is any unnecessary information and filter them out
	{
		return false;
	}

	if(home != "Home" && home != "Vacant")
	{
		return false;
	}else if(home == "Home")
	{
		check_home = true;
	}else
	{
		check_home = false;
	}

	for(int i = 0; i < lots.size(); i++)	// check for the duplicate LID
	{
		if(LID == lots[i]->getLID())
		{
			return false;
		}
	}

	for(int i =0; i < lots.size(); i++)
	{
		if(surname == lots[i]->getSurname())
		{
			counter ++;
		}
	}

	for(int i = 0; i < lots.size(); i++)	// check for the duplicate Surname
	{

		if(surname == lots[i]->getSurname())
		{
			if(type == "I" || type == "O")	// check if the owner has Inside, Outside or Adjacent lot
			{
				return false;
			}
			else if(type == "A")
			{
				if(counter >= 2)	// check if the owner already has an Adjacent lot
				{
					return false;
				}
				else
				{
					if(home == "Home")
					{
						return false;
					}else
					{
						Adjacent* adjacent = new Adjacent(LID, surname, false);
						lots.push_back(adjacent);
						return true;
					}
				}
			}
		}
	}

	if(type == "I")
	{
		Inside* inside = new Inside(LID, surname, check_home);
		lots.push_back(inside);
		return true;
	}else if(type == "O")
	{
		Outside* outside = new Outside(LID, surname, check_home);
		lots.push_back(outside);
		return true;
	}
	else
	{
		return false;
	}

	return false;
}

LotInterface* POA::getLot(int LID)
{
	for(int i = 0; i < lots.size(); i++)	
	{
		if(LID == lots[i]->getLID())
		{
			return lots[i];
		}
	}
	return NULL;

}

int POA::getSize()
{
	return lots.size();
}

vector<LotInterface*> POA::getPOAbySurname()
{
	vector<LotInterface*> sorted_vector;
	int size = lots.size();
	while(sorted_vector.size() != size)
	{
		int min = 0;

		for(int i = 0; i < lots.size(); i++)
		{
			if(lots[i]->getSurname() < lots[min]->getSurname())
			{
				min = i;
			}
		}
		sorted_vector.push_back(lots[min]);
		lots.erase(lots.begin() + min);
	}
	lots = sorted_vector;
	return lots;
}

vector<LotInterface*> POA::getPOAbyLID()
{
	vector<LotInterface*> sorted_vector;
	int size = lots.size();
	while(sorted_vector.size() != size)
	{
		int min = 0;

		for(int i = 0; i < lots.size(); i++)
		{
			if(lots[i]->getLID() < lots[min]->getLID())
			{
				min = i;
			}
		}
		sorted_vector.push_back(lots[min]);
		lots.erase(lots.begin() + min);
	}
	lots = sorted_vector;
	return lots;

}


bool POA::addHome(int LID)
{
	for(int i = 0; i < lots.size(); i++)
	{
		if(LID == lots[i]->getLID())
		{
			return lots[i]->addHome();
		}
	}
}

int POA::endMonth()
{
	int total_collected = 0;

	for(int i = 0; i < lots.size(); i++)
	{
		total_collected = total_collected + lots[i]->getMonthlyTotal();
		lots[i]->endOfMonth();
	}

	return total_collected;

}