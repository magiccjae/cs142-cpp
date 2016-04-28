#include "Outside.h"

using namespace std;

Outside::Outside(int LID_in, string surname_in, bool home_in):Lot(LID_in, surname_in, home_in)
{
	if(home_in)
	{
		monthly_total = 100 + 30;
	}
	else
	{
		monthly_total = 100;
	}

	weekly_fee = 0;
	weeks = 0;
}
int Outside::getMonthlyTotal()
{
	return monthly_total + weekly_fee;
}

bool Outside::weeklyFees(int numberOfWeeks)
{
	if(weeks + numberOfWeeks > 4 || weeks + numberOfWeeks < 0)	// check for the valid range for the number of weeks
	{
		return false;
	}
	else
	{	
		weeks = weeks + numberOfWeeks;
		if(hashome)								// with home, a lawn mowing fee
		{
			weekly_fee = weeks * 10;
			return true;
		}
		else									// without home, weed treatment
		{
			if(weeks > 0)
			{
				weekly_fee = 50;
				return true;
			}
			else
			{
				return false;
			}
		}

	}

}

bool Outside::addHome()
{
	if(hashome)
	{
		return false;
	}
	else
	{
		hashome = true;
		monthly_total = 130;
		return true;
	}
}

void Outside::endOfMonth()		// initializing back to the original monthly fee at the end of month
{
	weeks = 0;
	weekly_fee = 0;
	if(hashome)
	{
		monthly_total = 100 + 30;
	}
	else
	{
		monthly_total = 100;
	}

}