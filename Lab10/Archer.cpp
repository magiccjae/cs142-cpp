#include "Archer.h"
using namespace std;


Archer::Archer(string name_in, int maxhp_in, int strength_in, int speed_in, int magic_in):Fighter(name_in, maxhp_in, strength_in, speed_in, magic_in)
{
	original_speed = speed_in;
}
int Archer::getDamage()
{
	return getSpeed();
}
void Archer::reset()
{
	Fighter::reset();
	speed = original_speed;
}
bool Archer::useAbility()
{
	speed++;
	return true;
	
}