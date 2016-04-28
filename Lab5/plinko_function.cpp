#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int slot (double input, bool print)
{
	for(int i = 0; i <= 11; i++)
	{
		int r = rand() % 2;

		if(r == 0)
		{
			if(input == 0)
			{
				input = input + 0.5;
			}
			else if(input == 8)
			{
				input = input - 0.5;
			}
			else
			{
				input = input - 0.5;
			}
		}
		else
		{
			if(input == 0)
			{
				input = input + 0.5;
			}
			else if(input == 8)
			{
				input = input - 0.5;
			}
			else
			{
				input = input + 0.5;
			}
		}
		if(print)
		{
			cout << input << endl;
		}

	}


	return input;
}

int money(int dummy)
{
	int win = 0;

	if(dummy == 0)
	{
		win = 100;
	}
	if(dummy == 1)
	{
		win = 500;
	}
	if(dummy == 2)
	{
		win = 1000;
	}
	if(dummy == 3)
	{
		win = 0;
	}
	if(dummy == 4)
	{
		win = 10000;
	}
	if(dummy == 5)
	{
		win = 0;
	}
	if(dummy == 6)
	{
		win = 1000;
	}
	if(dummy == 7)
	{
		win = 500;
	}
	if(dummy == 8)
	{
		win = 100;
	}
	return win;
}

void multiple(int chips)
{
	int dummy = 0;
	int win = 0;
	int total = 0;
	int dummy1 = 0;
	int input = 0;

	if(chips >= 0)
	{
		cout << "Which slot you'd like to drop a chip(0-8)?" << endl;
		cin >> input;

		if(input >= 0 && input <= 8)
		{

			while(chips > dummy)
			{
				dummy1 = slot(input, false);
				win = money(dummy1);

				total = total + win;
				dummy++;

			}
			cout << "Total $$$ you won is: " << total << endl;
			cout << "Average: " << total/chips << endl;

		}
	}
}

void every(int chips)
{
	int dummy = 0;
	int dummy0, dummy1, dummy2, dummy3, dummy4, dummy5, dummy6, dummy7, dummy8;
	int win0, win1, win2, win3, win4, win5, win6, win7, win8;
	int total0 = 0;
	int total1 = 0;
	int total2 = 0;
	int total3 = 0;
	int total4 = 0;
	int total5 = 0;
	int total6 = 0;
	int total7 = 0;
	int total8 = 0;


	while(chips > dummy)
	{
		dummy0 = slot(0, false);
		win0 = money(dummy0);
		total0 = total0 + win0;

		dummy1 = slot(1, false);
		win1 = money(dummy1);
		total1 = total1 + win1;

		dummy2 = slot(2, false);
		win2 = money(dummy2);
		total2 = total2 + win2;

		dummy3 = slot(3, false);
		win3 = money(dummy3);
		total3 = total3 + win3;

		dummy4 = slot(4, false);
		win4 = money(dummy4);
		total4 = total4 + win4;

		dummy5 = slot(5, false);
		win5 = money(dummy5);
		total5 = total5 + win5;

		dummy6 = slot(6, false);
		win6 = money(dummy6);
		total6 = total6 + win6;

		dummy7 = slot(7, false);
		win7 = money(dummy7);
		total7 = total7 + win7;

		dummy8 = slot(8, false);
		win8 = money(dummy8);
		total8 = total8 + win8;

		dummy++;
	}
	cout << "Total $$$ on slot 0: " << total0 << endl;
	cout << "Average on slot 0: " << total0/chips << endl;

	cout << "Total $$$ on slot 1: " << total1 << endl;
	cout << "Average on slot 1: " << total1/chips << endl;

	cout << "Total $$$ on slot 2: " << total2 << endl;
	cout << "Average on slot 2: " << total2/chips << endl;

	cout << "Total $$$ on slot 3: " << total3 << endl;
	cout << "Average on slot 3: " << total3/chips << endl;

	cout << "Total $$$ on slot 4: " << total4 << endl;
	cout << "Average on slot 4: " << total4/chips << endl;

	cout << "Total $$$ on slot 5: " << total5 << endl;
	cout << "Average on slot 5: " << total5/chips << endl;

	cout << "Total $$$ on slot 6: " << total6 << endl;
	cout << "Average on slot 6: " << total6/chips << endl;

	cout << "Total $$$ on slot 7: " << total7 << endl;
	cout << "Average on slot 7: " << total7/chips << endl;

	cout << "Total $$$ on slot 8: " << total8 << endl;
	cout << "Average on slot 8: " << total8/chips << endl;
}




int main()
{
	srand(time(0));

	int selection = 1;

	while(selection != 3)
	{
		cout << "Select one of three operations" << endl;
		cout << "1. Drop one chip into one slot" << endl;
		cout << "2. Drop multiple chips into one slot" << endl;
		cout << "3. Quit the program" << endl;
		cout << "4. How many chips you want to drop into every slot" << endl;

		cin >> selection;

		if(selection == 3)
		{
			cout << "ByeBye" << endl;
		}

		if(selection == 1)
		{	
			double input = 0;
			int dummy = 0;
			int dummy1 = 0;

			cout << "Which slot you'd like to drop a chip(0-8)?";
			cin >> input;

			if(input >= 0 && input <= 8)
			{
				dummy = slot(input, true);
				dummy1 = money(dummy);
				cout << "You won $" << dummy1 << endl;
			}
		}

		if(selection == 2)
		{
			int chips = 0;

			cout << "How many chips you'd like to drop?" << endl;
			cin >> chips;
			multiple(chips);

		}

		if(selection == 4)
		{
			int chips = 0;

			cout << "How many chips you'd like to drop into every slot?" << endl;
			cin >> chips;
			if(chips >= 0)
			{
				every(chips);
			}
		}
	}

	system("pause");
	return 0;
}