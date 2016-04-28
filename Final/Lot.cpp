#include "Lot.h"

using namespace std;


Lot::Lot(int LID_in, string surname_in, bool home_in)	// constructor with some initial infos
{
	LID = LID_in;
	surname = surname_in;
	hashome = home_in;
}

int Lot::getLID()
{
	return LID;
}

string Lot::getSurname()
{
	return surname;
}


int Lot::getMonthlyTotal()
{
	return monthly_total;
}

bool Lot::hasHome()
{
	return hashome;
}

bool Lot::addHome()
{
	if(hashome)
	{
		return false;
	}
	else
	{
		hashome = true;
		return true;
	}
}


bool Lot::weeklyFees(int numberOfWeeks)		// implementation are executed in each derived classes
{
	return false;
}


void Lot::endOfMonth()		// implementation are executed in each derived classes
{

}


string Lot::toString()		// toString function with the right format
{
	string home = " ";

	if(hashome)
	{
		home = "yes";
	}
	else
	{
		home = "no";
	}

	stringstream ss;
	ss << "LID: " << LID << ", ";
	ss << "Surname: " << surname << ", ";
	ss << "Home: " << home << ", ";
	ss << "Monthly Fees: $" << getMonthlyTotal() << ".";
	return ss.str();
}