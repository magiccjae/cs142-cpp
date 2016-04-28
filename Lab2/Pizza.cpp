#include <iostream>

using namespace std;

int main ()
{
	const double PI = 3.14159;
	double total_area = 0;
	double each_area = 0;
	int large = 0;
	int medium = 0;
	int small = 0;
	double pizza_cost = 0;
	double large_price = 14.68;
	double medium_price = 11.48;
	double small_price = 7.28;
	int total_cost =0;
	
	cout << "Enter the number of guests: ";
	int guests;
	cin >> guests;

	cout << "Enter the percent of the total price to be paid as a tip: ";
	int tip;
	cin >> tip;

	large = guests / 7;
	medium = (guests - large*7)/3;
	small = (guests - large*7 - medium*3);

	cout << "Large\t\tMedium\t\tSmall" << endl;
	cout << "  " << large << "\t\t  " << medium << "\t\t  " << small << endl;
	
	total_area = (PI*100*large) + (PI*64*medium) + (PI*36*small);
	each_area = (total_area/guests);

	cout << "Total Area(in2)\t\tArea/Person(in2)" << endl;
	cout << "  " << total_area << "\t\t  " << each_area << endl;

	pizza_cost = (large_price*large) + (medium_price*medium) + (small_price*small);
	total_cost = pizza_cost + pizza_cost*tip/100 + .5;

	cout << "Total Cost($)" << endl;
	cout << "  " << total_cost << endl;

	system("pause");

}

/* 
	 !!Test Case!!

	People 48
	Tip 17%

	Large 6, Medium 2, Small 0

	Total Area = 2287.08
	Each Area = 47.6474

	Total Cost = 130

*/