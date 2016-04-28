#include "Inside.h"

using namespace std;

Inside::Inside(int LID_in, string surname_in, bool home_in):Lot(LID_in, surname_in, home_in)
{
	if(home_in)
	{
		monthly_total = 100 + 70;
	}
	else
	{
		monthly_total = 100 + 20;
	}

}
int Inside::getMonthlyTotal()
{
	return monthly_total;
}
bool Inside::addHome()
{
	if(hashome)
	{
		return false;
	}
	else
	{
		hashome = true;
		monthly_total = 170;
		return true;
	}
}
