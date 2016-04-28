#ifndef OUTSIDE_H
#define OUTSIDE_H
#include "Lot.h"
using namespace std;


class Outside : public Lot
{

public:

	Outside(int LID_in, string surname_in, bool home_in);

	virtual int getMonthlyTotal();
	virtual bool weeklyFees(int numberOfWeeks);
	virtual bool addHome();
	virtual void endOfMonth();


private:
	int weekly_fee;
	int weeks;

};

#endif