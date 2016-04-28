#ifndef FIGHTER_H
#define FIGHTER_H
#include "FighterInterface.h"
using namespace std;


class Fighter : public FighterInterface
{

public:

	Fighter(string name_in, int maxhp_in, int strength_in, int speed_in, int magic_in);

	virtual string getName();
	virtual int getMaximumHP();
	virtual int getCurrentHP();
	virtual int getStrength();
	virtual int getSpeed();
	virtual int getMagic();
	virtual int getDamage() = 0;
	virtual void takeDamage(int damage);
	virtual void reset();
	virtual void regenerate();
	virtual bool useAbility() = 0;

protected:
	
	string name;
	int max_hp;
	int current_hp;
	int strength;
	int speed;
	int magic;
	int damage;

};

#endif