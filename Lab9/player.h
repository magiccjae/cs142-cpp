#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <sstream>

using namespace std;

class player
{
public:

	player(string player_name);	// contructs a player with cleared specs

	int getRPSThrow();

	double getWinRecord();

	string toString();

	int add_win();	// return the number of the win of the player

	int add_loss();	// return the number of the loss of the player

	int add_draw();	// return the number of the draw of the player

private:

	string name;
	int win;
	int loss;
	int draw;

};

#endif