#ifndef ARCHER_H
#define ARCHER_H
#include "Fighter.h"
using namespace std;


class Archer : public Fighter
{

public:

	Archer(string name_in, int maxhp_in, int strength_in, int speed_in, int magic_in);

//	virtual string getName();
//	virtual int getMaximumHP();
//	virtual int getCurrentHP();
//	virtual int getStrength();
//	virtual int getSpeed();
//	virtual int getMagic();
	virtual int getDamage();
//	virtual void takeDamage(int damage);
	virtual void reset();
//	virtual void regenerate();
	virtual bool useAbility();

private:

	int original_speed;

};

#endif