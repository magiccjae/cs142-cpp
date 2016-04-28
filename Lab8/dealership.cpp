#include <iostream>
#include <vector>
#include "Car.h"
#include <fstream>
#include <string>

using namespace std;

int main ()
{

	bool again = true;
	double balance = 10000.00;
	vector <Car> inventory;					// Object vector


	while(again == true)
	{
		int choice;
		

		cout << "Select one of the operations" << endl;
		cout << "1. Show Current Inventory" << endl;
		cout << "2. Show Current Balance" << endl;
		cout << "3. Buy a Car" << endl;
		cout << "4. Sell a Car" << endl;
		cout << "5. Paint a Car" << endl;
		cout << "6. Load File" << endl;
		cout << "7. Save File" << endl;
		cout << "8. Quit Program" << endl;

		cin >> choice;

		if(choice < 1 || choice > 8) // check if the use input is valid
		{
			cout << "That's not an option. Please try again." << endl;
		}

		if(choice == 8)
		{
			again = false;
		}


		if(choice == 1)
		{
			for(int i = 0; i < inventory.size(); i++)
			{
				cout << inventory[i].toString() << endl;
			}
		}

		if(choice == 2)
		{
			cout << "Your current balance is $" << balance << endl;
		}

		if(choice == 3)
		{
			string name;
			string color;
			double price;
			bool checkname = false;

			do // check if the car already exists in the inventory
			{
				checkname = false;

				cout << "Enter the name of car: ";
				cin >> name;

				for(int i = 0; i < inventory.size(); i++)
				{
					if(name == inventory[i].getName())
					{
						checkname = true;
						cout << "You already own that car." << endl;
					}
				}


			}while(checkname);

			cout << "Color? ";
			cin >> color;


			do // price checker
			{
				cout << "Price? ";
				cin >> price;

				if(price > balance)
				{
					cout << "You don't have enough money for this car." << endl;
				}
			}
			while(price > balance);

			Car mycar(name, color, price);

			inventory.push_back(mycar);

			cout << "Purchase succeeded" << endl;

			balance = balance - price;

		}

		if(choice == 4)
		{
			string name;
			double sell_price;
			bool checkname = true;


			do				//check if the car is in the inventory
			{
				cout << "Enter the name of car: ";
				cin >> name;

				for(int i = 0; i < inventory.size(); i++)
				{
					if(name == inventory[i].getName())
					{
						checkname = false;

					}
				}
				if(checkname)
				{
					cout << "Invalid input" << endl;
				}

			}while(checkname);

			for(int i = 0; i < inventory.size(); i++)			// removing the car
			{
				if(name == inventory[i].getName())
				{
					sell_price = inventory[i].getPrice();
					balance = balance + sell_price;

					for(i; i < inventory.size()-1; i++)		
					{
						inventory[i] = inventory[i+1];
					}

				}
			}

			inventory.pop_back();
			cout << "Sold successfully" << endl;

		}

		if(choice == 5)
		{
			string name;
			string newcolor;
			bool checkname = true;

			do					// check if we own the car
			{
				cout << "Enter the name of car: ";
				cin >> name;

				for(int i = 0; i < inventory.size(); i++)
				{
					if(name == inventory[i].getName())
					{
						checkname = false;

					}
				}
				if(checkname)
				{
					cout << "Invalid input" << endl;
				}

			}while(checkname);			
			
			for(int i = 0; i < inventory.size(); i++)
			{

				if(name == inventory[i].getName())
				{
					bool checkcolor = true;

					while(checkcolor)
					{
						cout << "New color? ";
						cin >> newcolor;

						if(newcolor != inventory[i].getColor())				// check for same color
						{
							inventory[i].paint(newcolor);
							checkcolor = false;

							cout << "Painting successful" << endl;
						}
						else
						{
							cout << "Same color of the car" << endl;
						}
					}
				}
			}

		}

		if(choice == 6)
		{
			ifstream in_file;
			string filename;
			string newname;
			string newcolor;
			double newprice;
			double newbalance;

			cout << "Please enter the file name: ";
			
			cin >> filename;

			in_file.open(filename.c_str());

			if(in_file.fail())
			{
				cout << "file is not loaded." << endl;
			}
			else
			{
				cout << "file is loaded." << endl;
			}

			in_file >> newbalance;
			balance = balance + newbalance;

			while(in_file >> newname)
			{
				in_file >> newcolor;
				in_file >> newprice;

				Car mycar(newname, newcolor, newprice);

				inventory.push_back(mycar);
			}

		}

		if(choice == 7)
		{
			ofstream out_file;
			string filename;

			cout << "Please enter the file name: ";
			cin >> filename;

			out_file.open(filename.c_str());

			if(out_file.fail())
			{
				cout << "file is not saved." << endl;
			}
			else
			{
				cout << "file is saved." << endl;
			}

			out_file << balance << endl;

			for(int i = 0; i < inventory.size(); i++)
			{
				out_file << inventory[i].getName() << " " << inventory[i].getColor() << " " << inventory[i].getPrice() << endl;
			}

		}

	}

	system("pause");

	return 0;
}