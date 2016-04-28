#include "Robot.h"
#include <cmath>
using namespace std;


Robot::Robot(string name_in, int maxhp_in, int strength_in, int speed_in, int magic_in):Fighter(name_in, maxhp_in, strength_in, speed_in, magic_in)
{
	max_energy = 2*getMagic();
	add_damage = 0;
}
int Robot::getDamage()
{
	if(ability_on)
	{
		ability_on = false;
		return getStrength() + add_damage;
	}
	else
	{
		return getStrength();
	}
}
void Robot::reset()
{
	Fighter::reset();
	current_energy = max_energy;
	add_damage = 0;
}
bool Robot::useAbility()
{

	if(ROBOT_ABILITY_COST <= current_energy)
	{
		ability_on = true;
		add_damage = (int)(strength*(pow(current_energy/max_energy,4)));
		
		current_energy = current_energy - ROBOT_ABILITY_COST;
		return true;
	}

	return false;
}