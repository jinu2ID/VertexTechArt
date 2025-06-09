#include "Player.h"
#include <iostream>
#include <limits>

// Passes all arguments to Character Constructor
Player::Player(int Health, int AtkPower, int Armor, std::string Name) : Character(Health, AtkPower, Armor, Name)
{

}

Action Player::ChooseAction()
{
	int Input; 
	while (true) 
	{
	
		std::cout << "Choose an action - (1: Attack, 2: Parry, 3: Defend)" << std::endl;
		std::cin >> Input;

		if (std::cin.fail() || Input < 1 || Input > 3) 
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid Input : You must enter 1 , 2 or 3  (Attack, Parry, Defend)" << std::endl;
		}
		else
		{
			break;
		}
	
	}

	Input -= 1;
	return GetActionFromInput(Input);

}

void Player::LevelUp()
{
	Health += 2;
	AtkPower += 1;
	Armor += 1;
	std::cout << Name << " has leveled up! Health: " << Health << ", Attack Power: " << AtkPower << ", Armor: " << Armor << std::endl;
}


