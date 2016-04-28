#include <iostream>
#include "player.h"
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<player*> all;
	vector<player*> fight;

	string select = " ";
	bool valid = true;

	while(valid)
	{

		cout << "Select one of the operations" << endl;
		cout << "1. Show players" << endl;
		cout << "2. Add player" << endl;
		cout << "3. Add to Line-UP" << endl;
		cout << "4. Show Line-UP" << endl;
		cout << "5. Fight" << endl;

		getline(cin, select);

		if(select == "1")
		{

		}
		if(select == "2")
		{
			string player_name = " ";
			getline(cin, player_name);

			

		}
		if(select == "3")
		{
			string player_lineup = " ";
			getline(cin, player_lineup);



		}
		if(select == "4")
		{

		}
		if(select == "5")
		{

		}

	}


	return 0;
}