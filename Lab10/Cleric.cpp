#include "Cleric.h"
using namespace std;


Cleric::Cleric(string name_in, int maxhp_in, int strength_in, int speed_in, int magic_in):Fighter(name_in, maxhp_in, strength_in, speed_in, magic_in)
{
	max_mana = 5*getMagic();
	mana = max_mana;

}
int Cleric::getDamage()
{
	return getMagic();
}
void Cleric::reset()
{
	Fighter::reset();
	mana = 5*getMagic();
}
void Cleric::regenerate()
{
	Fighter::regenerate();
	if((magic / 5) < 1)
	{
		mana = mana + 1;
		if(mana > max_mana)
		{
			mana = max_mana;
		}
	}
	else
	{
		mana = mana + (magic / 5);
		if(mana > max_mana)
		{
			mana = max_mana;
		}
	}
}
bool Cleric::useAbility()
{


	if(mana >= CLERIC_ABILITY_COST)
	{
		if((magic / 3) < 1)
		{
			current_hp ++;
			if(current_hp > max_hp)
			{
				current_hp = max_hp;
			}
		}
		else
		{
			current_hp = current_hp + (magic / 3);
			if(current_hp > max_hp)
			{
				current_hp = max_hp;
			}

		}

		mana = mana - CLERIC_ABILITY_COST;
		return true;
	}
	return false;
}