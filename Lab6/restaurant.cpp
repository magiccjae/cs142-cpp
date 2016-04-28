#include <iostream>
#include <string>
#include <algorithm>


using namespace std;



void display(string restaurant[], int size)
{
	for(int i = 0; i < size; i++)
	{
		if(restaurant[i] != "")
		{
			if(i > 0)
			{
				cout << ", ";
			}
			cout << restaurant[i];
		}
	}
	cout << endl;

}

int add(string restaurant[], int size)
{
	string addition;

	cout << "Please enter the name of restaurant: ";
	getline(cin, addition);

	for(int i = 0; i < size; i++)
	{
		if(restaurant[i] == addition)
		{
			cout << "That's already on the list." << endl;
			return size;
		}
	}
	restaurant[size] = addition;
	cout << addition << " has been added on the list." << endl;
	size ++;
	return size;
}

int remove(string restaurant[], int size)
{
	string removal;

	cout << "Please enter the name of restaurant: ";
	getline(cin, removal);

	for(int i = 0; i < size; i++)
	{
		if(restaurant[i] == removal)
		{	
			while(i < size)
			{
				restaurant[i] = restaurant[i+1];
				i++;
			}

			restaurant[i+1] = "";
			cout << removal << " has been removed on the list." << endl;
			size --;
			return size;
		}
	}

	cout << "That's not on the list." << endl;
	return size;
}

string fight(string restaurant[], int number)
{	
	string choice;
	do
	{
		cout << restaurant[number] << " or " << restaurant[number + 1] << "? ";
		getline(cin, choice);

		if(choice == restaurant[number])
		{
			choice = restaurant[number];
		}
		else if(choice == restaurant[number + 1])
		{
			choice = restaurant[number + 1];
		}
		else
		{
			cout << "That's not an option!!" << endl;
		}
	}
	while(choice != restaurant[number] && choice != restaurant[number + 1]);
	return choice;
}

void tournament(string restaurant[], int size)
{
	string round1[16];
	string round2[8];
	string round3[4];
	string round4[2];
	string winner;				
	int round;
	int j = 0;

	if(size == 32)
	{
		for(int i = 0; i < size; i = i+2)
		{
			round1[j] = fight(restaurant, i);
			j++;
		}

		j = 0;
		for(int i = 0; i < size/2; i = i+2)
		{
			round2[j] = fight(round1, i);
			j++;
		}

		j = 0;
		for(int i = 0; i < size/4; i = i+2)
		{
			round3[j] = fight(round2, i);
			j++;
		}

		j = 0;
		for(int i = 0; i < size/8; i = i+2)
		{
			round4[j] = fight(round3, i);
			j++;
		}

		winner = fight(round4, 0);
		cout << "The winner is " << winner << "!!" << endl;
	}

	if(size == 16)
	{
		for(int i = 0; i < size; i = i+2)
		{
			round1[j] = fight(restaurant, i);
			j++;
		}

		j = 0;
		for(int i = 0; i < size/2; i = i+2)
		{
			round2[j] = fight(round1, i);
			j++;
		}

		j = 0;
		for(int i = 0; i < size/4; i = i+2)
		{
			round3[j] = fight(round2, i);
			j++;
		}
		winner = fight(round3, 0);
		cout << "The winner is " << winner << "!!" << endl;
	}

	if(size == 8)
	{
		for(int i = 0; i < size; i = i+2)
		{
			round1[j] = fight(restaurant, i);
			j++;
		}

		j = 0;
		for(int i = 0; i < size/2; i = i+2)
		{
			round2[j] = fight(round1, i);
			j++;
		}
		winner = fight(round2, 0);
		cout << "The winner is " << winner << "!!" << endl;
	}

	if(size == 4)
	{
		for(int i = 0; i < size; i = i+2)
		{
			round1[j] = fight(restaurant, i);
			j++;
		}
		winner = fight(round1, 0);
		cout << "The winner is " << winner << "!!" << endl;
	}

	if(size == 2)
	{
		winner = fight(restaurant, 0);
		cout << "The winner is " << winner << "!!" << endl;
	}

}

int main()
{
	const int SIZE = 32;
	string selection;
	string restaurant[SIZE] = {"Texas Road House", "Yamato", "Pho", "Cafe Rio", "Domino Pizza", "Spicy Corea", "Tucanos", "Zupas", "Chuckarama", "Green Panda", "Rancheritos", "Happy Sumo", "Five Guys", "Todai", "Outback", "Cannon Center"};
	int current_size = 16;

	do
	{	
		cout << "*****Select one of options*****" << endl;
		cout << "1. Display all restaurants" << endl;
		cout << "2. Add a restaurant" << endl;
		cout << "3. Remove a restaurant" << endl;
		cout << "4. Shuffle the array" << endl;
		cout << "5. Begin the tournament" << endl;
		cout << "6. Quit program" << endl;

		getline(cin, selection);

		if(selection == "1")
		{
			display(restaurant, current_size);
		}

		if(selection == "2")
		{
			current_size = add(restaurant, current_size);
		}

		if(selection == "3")
		{
			current_size = remove(restaurant, current_size);
		}

		if(selection == "4")
		{
			random_shuffle(restaurant, restaurant + current_size);
			cout << "Shuffling done." << endl;
		}
		
		if(selection == "5")
		{

			if(current_size == 2 || current_size == 4 || current_size == 8 || current_size == 16 || current_size == 32)
			{
				tournament(restaurant, current_size);
			}
			else
			{
				cout << "You must have 2 or 4 or 8 or 16 or 32 restaurants to begin the tournament." << endl;
			}

		}

	}
	while(selection != "6");

}

