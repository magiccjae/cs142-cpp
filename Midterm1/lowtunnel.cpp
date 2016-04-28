#include <iostream>
#include <string>

using namespace std;


int horizontal(int length) // Function that determines which of three low tunnel widths maximize area horizontally
{
	int three;
	int four;
	int five;
	int result;

	three = length % 3;
	four = length % 4;
	five = length % 5;

	if(three < four)
	{
		result = 3;

		if(three >= five)
		{
			result = 5;
		}
	}
	else
	{
		result = 4;

		if(four >= five)
		{
			result = 5;
		}
	}

	return result;
}

int vertical(int width) // Function that determines which of three low tunnel widths maximize area vertically
{
	int three;
	int four;
	int five;
	int result;

	three = width % 3;
	four = width % 4;
	five = width % 5;

	if(three < four)
	{
		result = 3;

		if(three >= five)
		{
			result = 5;
		}
	}
	else
	{
		result = 4;

		if(four >= five)
		{
			result = 5;
		}
	}

	return result;
}

int main()
{
	bool loop = true;

	while(loop) // program runs as many times as the user desires
	{	
		int length = 0;
		int width = 0;
		int garden_area = 0;

		int horizontal_number = 0;
		int vertical_number = 0;

		int horizontal_area = 0;
		int vertical_area = 0;

		string again;

		do
		{
			cout << "What is the length of the garden plot? ";
			cin >> length;

			if(cin.fail())
			{
				cout << "!!!WARNING: ENTER AN INTEGER NEXT TIME!!!" << endl;
				system("pause");
				return 1;
			}

			if(length <= 0)
			{
				cout << "Invalid Value. Enter a positive number." << endl;
			}
		}while(length <= 0); // a loop for valid input for length

		do
		{
			cout << "What is the width of the garden plot? ";
			cin >> width;

			if(cin.fail())
			{
				cout << "!!!WARNING: ENTER AN INTEGER NEXT TIME!!!" << endl;
				system("pause");
				return 1;
			}

			if(width <= 0)
			{
				cout << "Invalid Value. Enter a positive number." << endl;
			}

		}while(width <= 0); // a loop for valid input for width

		if(length <= 9 && width <= 9)
		{
			cout << "Your garden plot is too small for low tunnels." << endl;
		}

		else
		{
			garden_area = length * width;


			horizontal_area = (length / horizontal(length)) * (width / 10) * (horizontal(length) * 10);
			vertical_area = (width / vertical(width)) * (length / 10) * (vertical(width) * 10);

			horizontal_number = (length / horizontal(length)) * (width / 10);
			vertical_number = (width / vertical(width)) * (length / 10);

			double double_area1 = horizontal_area;
			double double_area2 = vertical_area;

			int horizontal_coverage = double_area1/garden_area*100 + 0.5;
			int vertical_coverage = double_area2/garden_area*100 + 0.5;


			if(horizontal_area > vertical_area) // comparing which of horizontal or vertical area is bigger?
			{
				cout << "You should make " << horizontal_number << " low tunnels, " << horizontal(length) << "'x 10' and place them horizontally. "
					<< "Your coverage will be " << horizontal_coverage << "%(" << horizontal_area << " square feet)." << endl;
			}
			else if(horizontal_area < vertical_area) // comparing which of horizontal or vertical area is bigger?
			{
				cout << "You should make " << vertical_number << " low tunnels, " << vertical(width) << "'x 10' and place them vertically. "
					<< "Your coverage will be " << vertical_coverage << "%(" << vertical_area << " square feet)." << endl;
			}
			else // when horizontal area equals vertical area
			{
				cout << "You should make " << horizontal_number << " low tunnels, " << horizontal(length) << "'x 10' and place them either horizontally or vertically. "
					<< "Your coverage will be " << horizontal_coverage << "%(" << horizontal_area << " square feet)." << endl;
			}
		}

		do
		{
			cout << "Another garden plot(y or n): ";
			cin >> again;

			if(again == "n")
			{
				cout << "Good bye." << endl;
				system("pause");
				loop = false;
			}

		}while(again != "y" && again != "n"); // wanna do it again loop?

	}
	return 0;
}