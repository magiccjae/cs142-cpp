#include "POAInterface.h"
using namespace std;

/*
 *	WARNING: It is expressly forbidden to modify any part of this document, including its name
 */
//=======================================================================================
/*
 *	createPOA()
 *
 *	Creates and returns an object whose class extends POAInterface.
 *	This should be an object of a class you have created.
 *
 *	Example: If you made a class called "POA", you might say, "return new POA();".
 */
class Factory
{
	public:
		static POAInterface* createPOA();
};
//=======================================================================================
