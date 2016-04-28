#ifndef ROBOT_H
#define ROBOT_H
#include "Fighter.h"
using namespace std;


class Robot : public Fighter
{

public:

	Robot(string name_in, int maxhp_in, int strength_in, int speed_in, int magic_in);

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
	
	double current_energy;
	double max_energy;
	int add_damage;
	bool ability_on;

};

#endif