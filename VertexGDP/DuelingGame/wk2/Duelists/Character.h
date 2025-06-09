#pragma once
#include <string>
#include "ActionEnums.h"

class Character 
{

public:
	Character(int Health, int AtkPower, int Armor, std::string Name);

	int GetHealth() const { return Health; }
	std::string GetName() const { return Name; }
	bool GetIsAlive() const { return Health > 0; }
	int GetAtkPower() const { return AtkPower; }
	void UpdateHealth(int Amount);
	void IncreaseAtkPower(int Amount) { AtkPower += Amount; }
	void IncreaseArmor(int Amount) { Armor += Amount; };

	virtual Action ChooseAction() = 0;
	Action GetActionFromInput(int Input);

protected:
	std::string Name;
	int Health;
	int AtkPower;
	int Armor;

};