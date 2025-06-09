#include "Character.h"
#include <iostream>

Character::Character(int Health, int AtkPower, int Armor, std::string Name) :Health(Health), AtkPower(AtkPower), Armor(Armor), Name(Name){}

void Character::UpdateHealth(int Amount)
{
	Health += Amount;
	Health = (Health < 0) ? 0 : Health; // Bug: Ensure health does not go below 0
	std::cout << Name << " has " << Health << " remaining" << std::endl;
}

Action Character::GetActionFromInput(int Input)
{
	switch (Input)
	{
		case 0:
			return Action::Attack;
		case 1:
			return Action::Parry;
		case 2:
			return Action::Defend;
		default:
			return Action::Count; // Bug: Added default case for invalid input
	}
}