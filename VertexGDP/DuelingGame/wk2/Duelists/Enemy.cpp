#include "Enemy.h"


// Passes all arguments to Character Constructor
Enemy::Enemy(int Health, int AtkPower, int Armor, std::string Name) : Character(Health, AtkPower, Armor, Name), Generator(std::random_device{}()), Distribution(0, 2), 
	BaseHealth(Health) // Store the base health for difficulty scaling
{

}

Action Enemy::ChooseAction()
{
	int Action = Distribution(Generator);

	return GetActionFromInput(Action);
}

void Enemy::IncreaseDifficulty(int RoundNumber)
{
	switch (RoundNumber)
	{
		case 1:
			return;
		case 2:
			Health = BaseHealth + RoundNumber; // Bug: enemy health upgrade was being added to 0 after being defeated
			BaseHealth = Health; // Update base health for future rounds
			AtkPower *= 2;
			Name = "Goblin Warrior";
			break; // Bug: Added break statement to prevent fall-through
		case 3:
			Health = BaseHealth + RoundNumber;
			BaseHealth = Health;
			AtkPower += RoundNumber;
			Name = "Gladiator";
			break;
		case 4:
			Health = BaseHealth + RoundNumber;
			BaseHealth = Health;
			AtkPower += RoundNumber;
			Name = "Berserker";
			break;
		case 5:
			Health = BaseHealth + RoundNumber;
			BaseHealth = Health;
			AtkPower += RoundNumber;
			Armor += RoundNumber / 2; 
			Name = "Knight Champion";
			break;
		default:
			return; // Bug: Added default case to handle unexpected RoundNumbers
	}

}
