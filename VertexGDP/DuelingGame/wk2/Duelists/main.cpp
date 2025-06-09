// Dueling Game
#include <iostream>

#include "Player.h"
#include "Enemy.h"
#include "ActionEnums.h"

using std::cout;
using std::endl;
using std::string;

// we use . when working with objects
// we use -> when working with Pointers *  this comes with extra considerations and steps

bool CalculateParry(std::mt19937& rng, std::uniform_real_distribution<float>& dist, int AttackerAtkPower, int ParriersAttackPower);

int main() 
{
	Player MainPlayer(5, 2, 2, "Hero");
	Enemy MainEnemy(1, 1, 0, "Goblin");
	int RoundNumber = 1;
	std::mt19937 ParryRNG(std::random_device{}());
	std::uniform_real_distribution<float> Distribution(0.0f, 1.0f);
	bool ParrySuccess = false;
	int Damage = 0;

	cout << "Round " << RoundNumber << ": " << MainEnemy.GetName() << endl;

	while(MainPlayer.GetIsAlive())
	{
		
		Action PlayerAction = MainPlayer.ChooseAction();
		Action EnemyAction = MainEnemy.ChooseAction();
		
		cout << "Player " << ToString(PlayerAction) << "s" << endl;
		cout << "Enemy " <<ToString(EnemyAction) << "s" << endl;

		// Determine the combined case based on player and enemy actions
		CombinedCase flag = GetCombinedCase(PlayerAction, EnemyAction);

		//Process the round logic based on actions
		switch (flag)
		{
			case AttackVsAttack:
				cout << "Its a clash! The weapons ring as they hit each other!" << endl;
				break;
			case AttackVsParry:
				ParrySuccess = CalculateParry(ParryRNG, Distribution, MainPlayer.GetAtkPower(), MainEnemy.GetAtkPower());
				if (ParrySuccess)
				{
					Damage = MainEnemy.GetAtkPower() * 2;
					cout << MainEnemy.GetName() << " parries the attack! Oh no our hero is struck by double damage!" << endl;
					cout << MainEnemy.GetName() << " does " << Damage << " damage!" << endl;
					MainPlayer.UpdateHealth(-Damage);
				}
				else
				{
					Damage = MainPlayer.GetAtkPower() * 2;
					cout << MainEnemy.GetName() << " fails to parry! Our Hero strikes and does double damage!" << endl;
					cout << "Our Hero does " << Damage << " damage!" << endl;
					MainEnemy.UpdateHealth(-Damage);
				}
				break;
			case AttackVsDefend:
				Damage = MainPlayer.GetAtkPower() / 2;
				cout << MainEnemy.GetName() << " Is defending! The attack is less successful!" << endl;
				cout << "Our Hero does " << Damage << " damage!" << endl;
				MainEnemy.UpdateHealth(-Damage);
				break;
			case DefendVsAttack:
				Damage = MainEnemy.GetAtkPower() / 2;
				cout << "Our Hero Is defending! " << MainEnemy.GetName() << "'s attack is less successful!" << endl;
				cout << MainEnemy.GetName() << " does " << Damage << " damage!" << endl;
				MainPlayer.UpdateHealth(-Damage);
				break;
			case ParryVsAttack:
				ParrySuccess = CalculateParry(ParryRNG, Distribution, MainEnemy.GetAtkPower(), MainPlayer.GetAtkPower());
				if (ParrySuccess)
				{
					Damage = MainPlayer.GetAtkPower() * 2;
					cout << "Our Hero masterfully parries! " << MainEnemy.GetName() << " Takes double damage!" << endl;
					cout << "Our Hero does " << Damage << " damage!" << endl;
					MainEnemy.UpdateHealth(-Damage);
				}
				else
				{
					Damage = MainEnemy.GetAtkPower() * 2;
					cout << "Our Hero fails to parry! " << MainEnemy.GetName() << " strikes and does double damage" << endl;
					cout << MainEnemy.GetName() << " does " << Damage << " damage!" << endl;
					MainPlayer.UpdateHealth(-Damage);
				}
				
				break;
			default:
				cout << "Nothing happens !" << endl;
		}

		if (!MainEnemy.GetIsAlive())
		{
			cout << MainEnemy.GetName() << " has been defeated by our Hero! A new stronger enemy appears" << endl;
			MainPlayer.LevelUp();
			RoundNumber += 1;

			if (RoundNumber > 5)
			{
				cout << "Our Hero has defeated all his opponents and is now champion of the arena !!!" << endl;
				break;
			}

			MainEnemy.IncreaseDifficulty(RoundNumber);
			cout << endl << endl;
			cout << "Round " << RoundNumber << ": " << MainEnemy.GetName() << endl;

		}
		cout << endl;
	}

	if (!MainPlayer.GetIsAlive())
	{
		cout << "Our Hero has perished! You must try again!" << endl;
	
	}

	cout << "Thanks for playing!" << endl;
	return 0;
}

// Ratio-based parry success
// P = Parrier AtkPower
// A = Attacker AtkPower
// P / (P + A) = Parry Success Rate
bool CalculateParry(std::mt19937& rng, std::uniform_real_distribution<float>& dist, int AttackerAtkPower, int ParriersAttackPower)
{
	float sum = AttackerAtkPower + ParriersAttackPower;
	if (sum <= 0.0f) return false;

	float parrySuccessRate = ParriersAttackPower / sum;
	float roll = dist(rng);
	return (roll < parrySuccessRate);
}