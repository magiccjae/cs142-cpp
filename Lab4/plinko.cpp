#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));

	int selection = 1;

	while(selection == 1 || selection == 2)
	{
		cout << "Select one of three operations" << endl;
		cout << "1. Drop one chip into one slot" << endl;
		cout << "2. Drop multiple chips into one slot" << endl;
		cout << "3. Quit the program" << endl;

		cin >> selection;

		if(selection == 3)
		{
			cout << "ByeBye" << endl;
		}

		if(selection == 1)
		{
			double slot =0;

			cout << "Which slot you'd like to drop a chip(0-8)?";
			cin >> slot;

			if(slot >= 0 && slot <= 8)
			{
				for(int i = 0; i <= 11; i++)
				{
					int r = rand() % 2;

					if(r == 0)
					{
						if(slot == 0)
						{
							slot = slot + 0.5;
							cout << slot << endl;
						}
						else if(slot == 8)
						{
							slot = slot - 0.5;
							cout << slot << endl;
						}
						else
						{
							slot = slot - 0.5;
							cout << slot << endl;
						}
					}
					else
					{
						if(slot == 0)
						{
							slot = slot + 0.5;
							cout << slot << endl;
						}
						else if(slot == 8)
						{
							slot = slot - 0.5;
							cout << slot << endl;
						}
						else
						{
							slot = slot + 0.5;
							cout << slot << endl;
						}
					}

				}
			
				if(slot == 0)
				{
					cout << "You won $100" << endl;
				}
				if(slot == 1)
				{
					cout << "You won $500" << endl;
				}
				if(slot == 2)
				{
					cout << "You won $1000" << endl;
				}
				if(slot == 3)
				{
					cout << "You won $0 haha~" << endl;
				}
				if(slot == 4)
				{
					cout << "You won $10000 wow!" << endl;
				}
				if(slot == 5)
				{
					cout << "You won $0 haha~" << endl;
				}
				if(slot == 6)
				{
					cout << "You won $1000" << endl;
				}
				if(slot == 7)
				{
					cout << "You won $500" << endl;
				}
				if(slot == 8)
				{
					cout << "You won $100" << endl;
				}

			}

		}

		if(selection == 2)
		{
			double slot = 0;
			double slot1 = 0;
			int chips = 0;
			int dummy = 0;
			int money = 0;
			double total = 0;

			cout << "How many chips you'd like to drop?" << endl;
			cin >> chips;
			if(chips >= 0)
			{
				cout << "Which slot you'd like to drop a chip(0-8)?" << endl;
				cin >> slot;


				while(chips > dummy)
				{
					slot1 = slot;

					if(slot >= 0 && slot <= 8)
					{
						for(int i = 0; i <= 11; i++)
						{
							int r = rand() % 2;

							if(r == 0)
							{
								if(slot1 == 0)
								{
									slot1 = slot1 + 0.5;
								}
								else if(slot1 == 8)
								{
									slot1 = slot1 - 0.5;
								}
								else
								{
									slot1 = slot1 - 0.5;
								}
							}
							else
							{
								if(slot1 == 0)
								{
									slot1 = slot1 + 0.5;
								}
								else if(slot1 == 8)
								{
									slot1 = slot1 - 0.5;
								}
								else
								{
									slot1 = slot1 + 0.5;
								}
							}
						}

						if(slot1 == 0)
						{
							money = 100;
						}
						if(slot1 == 1)
						{
							money = 500;
						}
						if(slot1 == 2)
						{
							money = 1000;
						}
						if(slot1 == 3)
						{
							money = 0;
						}
						if(slot1 == 4)
						{
							money = 10000;
						}
						if(slot1 == 5)
						{
							money = 0;
						}
						if(slot1 == 6)
						{
							money = 1000;
						}
						if(slot1 == 7)
						{
							money = 500;
						}
						if(slot1 == 8)
						{
							money = 100;
						}
					}

					total = total + money;

					dummy++;
				}

			}

			cout << "Total $$$ you won is: " << total << endl;
			cout << "Average: " << total/chips << endl;

		}
	}

	system("pause");

}