#ifndef ARENA_H
#define ARENA_H
#include "ArenaInterface.h"
#include "Fighter.h"
#include <vector>
#include "Cleric.h"
#include "Robot.h"
#include "Archer.h"
using namespace std;


class Arena : public ArenaInterface
{

public:

	Arena();

	virtual bool addFighter(string info);

	virtual bool removeFighter(string name);
		
	virtual FighterInterface* getFighter(string name);
		
	virtual int getSize();

private:
	
	vector<Fighter*> fighters;

};

#endif