#ifndef ADJACENT_H
#define ADJACENT_H
#include "Lot.h"
using namespace std;


class Adjacent : public Lot
{

public:

	Adjacent(int LID_in, string surname_in, bool home_in);

	virtual int getMonthlyTotal();
	virtual bool weeklyFees(int numberOfWeeks);
	virtual void endOfMonth();


private:
	int weekly_fee;
	int weeks;

};

#endif