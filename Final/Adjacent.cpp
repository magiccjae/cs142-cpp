#include "Adjacent.h"

using namespace std;

Adjacent::Adjacent(int LID_in, string surname_in, bool home_in):Lot(LID_in, surname_in, home_in)
{
	monthly_total = 75;
	weekly_fee = 0;
}
int Adjacent::getMonthlyTotal()
{
	return monthly_total + weekly_fee;
}

bool Adjacent::weeklyFees(int numberOfWeeks)	// calculating a lawn mowing fee
{
	weeks = weeks + numberOfWeeks;
	if(weeks > 4 || weeks < 0)
	{
		return false;
	}
	else
	{	
		weekly_fee = weeks * 10;
		return true;
	}
}
void Adjacent::endOfMonth()		// initializing back to the original monthly fee at the end of month
{
	weeks = 0;
	weekly_fee = 0;
	monthly_total = 75;
}