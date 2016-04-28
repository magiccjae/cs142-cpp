/*
	Jaehun Lee
	jhl48(95-225-6535)
	CS 142 Winter 2013 Final Exam

*/


#include <iostream>
#include <string>
#include <vector>
#include "Factory.h"
#include "POAInterface.h"
using namespace std;
/*

This Main is provided to help you test your code, although it is not required to create a main() for passoff.

*/
int main()
{

	POAInterface* p = Factory::createPOA();

	system("pause");
	return 0;
}


