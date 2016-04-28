#ifndef INSIDE_H
#define INSIDE_H
#include "Lot.h"
using namespace std;


class Inside : public Lot
{

public:

	Inside(int LID_in, string surname_in, bool home_in);

	virtual int getMonthlyTotal();
	virtual bool addHome();


private:
	

};

#endif