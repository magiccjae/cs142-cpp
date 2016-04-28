#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 *	WARNING: It is expressly forbidden to modify any part of this document, including its name
 */

/*
 *	This class specifies the required public member functions for a lot.
 *
 *	All lots have the following attributes:
 *		LID - The Lot Identification Number
 *		Surname - The surname of the owner of the lot
 *		Home - Tells whether or not the lot has a home on it
 *		MonthlyTotal - The total monthly cost (with 'extra fees' included if needed) owed by that lot for the current month
 *
 *
 *	The lot types have unique attributes:
 *	  	See the Background/Specifications for specifics
 *
 *	More details can be found in the comments below.
 */

class LotInterface
{
	public:
		LotInterface(){}
		virtual ~LotInterface(){}
		
		/*
		 *	getLID()
		 *
		 *	Returns the LID of this lot.
		 */
		virtual int getLID() = 0;

		/*
		 *	getSurname()
		 *
		 *	Returns the surname of the owner of this lot.
		 */
		virtual string getSurname() = 0;

		/*
		 *	getMonthlyTotal()
		 *
		 *	Returns the total cost for this lot for the month including all fees.
		 */
		virtual int getMonthlyTotal() = 0;

		/*
		 *	hasHome()
		 *
		 *	Returns true if the lot has a home, false otherwise.
		 */
		virtual bool hasHome() = 0;		
		
		/*
		 *	addHome()
		 *	
		 *	Attempts to add a home to the lot; returns true if the home is added, false otherwise.
		 */
		virtual bool addHome() = 0;

		/*
		 *	weeklyFees(int)
		 *
		 *	Increases this lot's total cost based on the type of lot and the number of weeks.
		 *	Inside lots do not have any weekly fees.
		 *	
		 *	A lawn mowing fee of $10 is imposed for each week that the owner 
		 *	of an outside lot with a home or the owner of an adjacent lot fails to mow his lawn.  
		 *  This can be charged up to four times per month.
		 *
		 *	A weed treatment fee of $50 is imposed on occasion on an outside lot
		 *	without a home.  This fee can only be charged once per month.  
		 *	
		 *	This function may be called on a single lot zero or more times in a month,
		 *	but should do nothing if the number of weeks allowed for that lot type
		 *	for the month would be exceeded.
		 *	
		 *	Returns true if the weekly fees were added, false if the fees could not be added.
		 *	Reject all non-positive input.
		 *	
		 *	Example: An outside lot with a home may be fined 3 weeks (returns true), 
		 *	then 2 weeks (returns false), then 1 week (returns true), 
		 *	then 2 weeks (returns false), then the endOfMonth() method is called,
		 *	then fined 2 weeks (returns true).
		 *	
		 */
		virtual bool weeklyFees(int numberOfWeeks) = 0;

		/*
		 *	endOfMonth()
		 *
		 *	Restores a lot's current fees to the standard monthly fees for that lot type before weekly fees.
		 *
		 */
		virtual void endOfMonth() = 0;

		/*
		 *	toString()
		 *
		 *	This string must be in the exact format as found below. After 'Home' must be a yes or a no.
		 *	There must be a $ before the price for the Monthly Fees is listed.
		 *
		 *	Returns the information about a lot in a string with the following format:
		 *	LID: x, Surname: name, Home: yes, Monthly Fees: $456.
		 *
		 *
		 */
		virtual string toString() = 0;
};
