#include "Factory.h"
#include "POA.h"
//You may add #include statments here
using namespace std;

/*
 *	Unlike all other documents provided, you may modify this document slightly (but do not change its name)
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
POAInterface* Factory::createPOA()
{
	return new POA();//Modify this line
}
//=======================================================================================