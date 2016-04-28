#include "player.h"
#include <cstdlib>
#include <ctime>


player::player(string player_name)
{
	this->name = player_name;
	win = 0;
	loss = 0;
	draw = 0;
}

int player::getRPSThrow()
{	
	srand(time(0));

	int r = rand()%(3)+1;

	return r;
}

double player::getWinRecord()
{
	return ((win)/(win+loss+draw));
}

string player::toString()
{
	stringstream ss;
	ss << "Name: " << name << " ";
	ss << "Win: " << win << " ";
	ss << "Loss: " << loss << " ";
	ss << "Draw: " << draw << " ";
	return ss.str();
}