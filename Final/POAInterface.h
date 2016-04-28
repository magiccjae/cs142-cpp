#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "LotInterface.h"
using namespace std;

/*
 *	WARNING: It is expressly forbidden to modify any part of this document, including its name
 */
class POAInterface
{
	public:
		POAInterface(){}
		virtual ~POAInterface(){}
		
		/*
		 *	addLot(string)
		 *
		 *	Adds a new Lot to the collection of Lots in the POA. 
		 *  Do not allow Lots with duplicate LIDs (Lot Identification Numbers).
		 *  Do not allow Lots with duplicate surnames, unless the lot is being purchased as 
		 *	an adjacent lot for someone who already owns one main lot, but does not already own an adjacent lot.
		 *
		 *	Reject any string that does not adhere to the following format:
		 *	(Surname) - The name of the Owner of the Lot (single word names only)
		 *  (LID) - An integer containing the unique Lot Identification Number
		 *  (Type) - Can be I, O, or A, meaning Inside, Outside, or Adjacent, respectively
		 *  (Home or Vacant) - Whether the lot has a home on it to begin with or not (case sensitive)
		 *	In Total - (Surname) (LID) (Type) (Home or Vacant)
		 *  Example: Johnson 111 O Home
		 *  Example: Louis 1234 I Vacant
		 *	Example: Jimersoninafitzpatrickbarrelheart 3 A Vacant
		 *
		 *	Return true if a new lot was added; false otherwise.
		 */
		virtual bool addLot(string info) = 0;
		
		/*
		 *	getLot(int)
		 *
		 *	Returns the memory address of a lot whose LID is equal to the given 
		 *	int.  Returns NULL if no lot is found with the given LID.
		 *
		 *	Return a memory address if a lot is found; NULL otherwise.
		 */
		virtual LotInterface* getLot(int LID) = 0;
		
		/*
		 *	getSize()
		 *
		 *	Returns the number of lots in the POA.
		 *
		 *	Return a non-negative integer.
		 */
		virtual int getSize() = 0;
		
		/*
		 *	getPOAbySurname()
		 *
		 *	Returns a vector of LotInterface* sorted by the owners' surnames.
		 *		-If there is an owner with more than 1 lot (aka, one surname on many lots),
		 *		 then you may put his lots in the vector in any order, keeping his surname sorted
		 *		 compared to the other surnames.
		 *
		 *	Return a sorted vector.
		 */
		virtual vector<LotInterface*> getPOAbySurname() = 0;
		
		/*
		 *	getPOAbyLID()
		 *
		 *	Returns a vector of LotInterface* sorted by the LID.
		 *
		 *	Return a sorted vector.
		 */
		virtual vector<LotInterface*> getPOAbyLID() = 0;
		
		/*
		 *	addHome(int)
		 *
		 *	Adds a home to an existing lot if there was not
		 *	already a home on that lot.  The home is added to
		 *	the lot identified by the LID paramater passed in.
		 *
		 *	Return true if a home was added, false if the lot doesn't exist or a home already exists there.
		 */
		virtual bool addHome(int LID) = 0;
		
		/*
		 *	endMonth()
		 *
		 *	"Charges" each lot its standard monthly fees and ends the month for each lot.
		 *
		 *	Returns the total collected by the POA from every lot combined.
		 */
		virtual int endMonth() = 0;
};
