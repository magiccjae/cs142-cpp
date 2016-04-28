#include "Fighter.h"
using namespace std;


Fighter::Fighter(string name_in, int maxhp_in, int strength_in, int speed_in, int magic_in)
{
	name = name_in;
	max_hp = maxhp_in;
	current_hp = max_hp;
	strength = strength_in;
	speed = speed_in;
	magic = magic_in;
}

string Fighter::getName()
{
	return name;
}
int Fighter::getMaximumHP()
{
	return max_hp;
}
int Fighter::getCurrentHP()
{
	return current_hp;
}
int Fighter::getStrength()
{
	return strength;
}
int Fighter::getSpeed()
{
	return speed;
}
int Fighter::getMagic()
{
	return magic;
}
/*int Fighter::getDamage()
{

}*/

void Fighter::takeDamage(int damage)
{
	if((damage-speed/4) < 1)
	{
		current_hp = current_hp - 1;
	}
	else
	{
		current_hp = current_hp - (damage - speed/4);
	}
}
void Fighter::reset()
{
	current_hp = max_hp;
}
void Fighter::regenerate()
{		
	if((strength / 6) < 1)
	{
		current_hp = current_hp + 1;
		if(current_hp > max_hp)
		{
			current_hp = max_hp;
		}
	}
	else
	{
		current_hp = current_hp + (strength / 6);
		if(current_hp > max_hp)
		{
			current_hp = max_hp;
		}

	}

}
/*bool Fighter::useAbility()
{
}*/
