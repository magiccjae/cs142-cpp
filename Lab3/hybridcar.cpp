#include <iostream>

using namespace std;

int main()
{
	double mile_year;
	double gas_price;
	double hybrid;
	double hybrid_efficiency;
	double hybrid_resale;
	double nonhybrid;
	double nonhybrid_efficiency;
	double nonhybrid_resale;
	int gas_or_total;

	cout << "Enter the estimated miles driven per year: ";
	cin >> mile_year;

	if(mile_year < 0)
	{
		cout << "***ERROR*** Please Enter positive numbers: " << endl;
		cout << "Enter the estimated miles driven per year: ";
		cin >> mile_year;
	}

	cout << "Enter the estimated price of a gallon of gas: ";
	cin >> gas_price;

	if(gas_price < 0)
	{
		cout << "***ERROR*** Please Enter positive numbers: " << endl;
		cout << "Enter the estimated price of a gallon of gas: ";
		cin >> gas_price;
	}

	cout << "Enter the cost of a hybrid car: ";
	cin >> hybrid;

	if(hybrid < 0)
	{
		cout << "***ERROR*** Please Enter positive numbers: " << endl;
		cout << "Enter the cost of a hybrid car: ";
		cin >> hybrid;
	}

	cout << "Enter the efficiency of the hybrid car in miles per gallon: ";
	cin >> hybrid_efficiency;

	if(hybrid_efficiency < 0)
	{
		cout << "***ERROR*** Please Enter positive numbers: " << endl;
		cout << "Enter the efficiency of the hybrid car in miles per gallon: ";
		cin >> hybrid_efficiency;
	}

	cout << "Enter the estimated resale value for a hybrid after 5 years: ";
	cin >> hybrid_resale;

	if(hybrid_resale < 0)
	{
		cout << "***ERROR*** Please Enter positive numbers: " << endl;
		cout << "Enter the estimated resale value for a hybrid after 5 years: ";
		cin >> hybrid_resale;
	}

	cout << "Enter the cost of a non-hybrid car: ";
	cin >> nonhybrid;

	if(nonhybrid < 0)
	{
		cout << "***ERROR*** Please Enter positive numbers: " << endl;
		cout << "Enter the cost of a non-hybrid car: ";
		cin >> nonhybrid;
	}

	cout << "Enter the efficiency of the non-hybrid car in miles per gallon: ";
	cin >> nonhybrid_efficiency;

	if(nonhybrid_efficiency < 0)
	{
		cout << "***ERROR*** Please Enter positive numbers: " << endl;
		cout << "Enter the efficiency of the non-hybrid car in miles per gallon: ";
		cin >> nonhybrid_efficiency;
	}

	cout << "Enter the estimated resale value for a non-hybrid after 5 years: ";
	cin >> nonhybrid_resale;

	if(nonhybrid_resale < 0)
	{
		cout << "***ERROR*** Please Enter positive numbers: " << endl;
		cout << "Enter the estimated resale value for a non-hybrid after 5 years: ";
		cin >> nonhybrid_resale;
	}

	cout << "Which criteria do you care more? Gas consumption? or Total cost?" << endl;
	cout << "If you care more Gas consumption, then enter 1. \nIf you care more Total cost, then enter 2." << endl;
	cin >> gas_or_total;

	cout << "\t\t\t\t\t  Hybrid\tNon-Hybrid" << endl;
	cout << "Total gallons of fuel used for 5years" << "\t  " << mile_year*5/hybrid_efficiency << "\t\t" << mile_year*5/nonhybrid_efficiency << endl;
	cout << "Total cost of owning the car for 5years" << "\t  " << (mile_year*5/hybrid_efficiency * gas_price) + (hybrid - hybrid_resale);
	cout << "\t\t" << (mile_year*5/nonhybrid_efficiency * gas_price) + (nonhybrid - nonhybrid_resale) << endl << endl;
	
	
	if(gas_or_total == 1)
	{
		cout << "Gas consumption" << endl;

		if((mile_year/hybrid_efficiency) <= (mile_year/nonhybrid_efficiency))
		{
			cout << "Hybrid: " << mile_year*5/hybrid_efficiency * gas_price << endl;
			cout << "Non-Hybrid: " << mile_year*5/nonhybrid_efficiency * gas_price << endl;
		}
		else
		{
			cout << "Non-Hybrid: " << mile_year*5/nonhybrid_efficiency * gas_price << endl;
			cout << "Hybrid: " << mile_year*5/hybrid_efficiency * gas_price << endl;
		}
	}

	if(gas_or_total == 2)
	{
		cout << "Total cost" << endl;

		if(((mile_year*5/hybrid_efficiency * gas_price) + (hybrid - hybrid_resale)) <= ((mile_year*5/nonhybrid_efficiency * gas_price) + (nonhybrid - nonhybrid_resale)))
		{
			cout << "Hybrid: " << (mile_year*5/hybrid_efficiency * gas_price) + (hybrid - hybrid_resale) << endl;
			cout << "Non-Hybrid: " << (mile_year*5/nonhybrid_efficiency * gas_price) + (nonhybrid - nonhybrid_resale) << endl;
		}
		else
		{
			cout << "Non-Hybrid: " << (mile_year*5/nonhybrid_efficiency * gas_price) + (nonhybrid - nonhybrid_resale) << endl;
			cout << "Hybrid: " << (mile_year*5/hybrid_efficiency * gas_price) + (hybrid - hybrid_resale) << endl;
		}
	}

	system("pause");

	return (0);

}

// For extra credit, 166.5 miles / gallon will make the same total cost as non-hybrid car.