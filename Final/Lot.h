#ifndef LOT_H
#define LOT_H
#include <string>
#include <sstream>
#include "LotInterface.h"

using namespace std;


class Lot : public LotInterface
{

public:


	Lot(int LID_in, string surname_in, bool home_in);

	virtual int getLID();
	virtual string getSurname();
	virtual int getMonthlyTotal();
	virtual bool hasHome();		
	virtual bool addHome();
	virtual bool weeklyFees(int numberOfWeeks);
	virtual void endOfMonth();
	virtual string toString();


protected:
	int LID;
	string surname;
	int monthly_total;
	bool hashome;
	bool addhome;
//	bool weekly_fee;

};

#endif