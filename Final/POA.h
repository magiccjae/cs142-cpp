#ifndef POA_H
#define POA_H
#include "POAInterface.h"
#include "Lot.h"
#include <vector>
#include "Inside.h"
#include "Outside.h"
#include "Adjacent.h"

using namespace std;


class POA : public POAInterface
{

public:

	POA();

	virtual bool addLot(string info);

	virtual LotInterface* getLot(int LID);
		
	virtual int getSize();
		
	virtual vector<LotInterface*> getPOAbySurname();

	virtual vector<LotInterface*> getPOAbyLID();

	virtual bool addHome(int LID);

	virtual int endMonth();


private:

	vector<LotInterface*> lots;


};

#endif