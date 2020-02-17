#ifndef ABILITY_H
#define ABILITY_H

#include <string>
#include <vector>
#include "dice.h"
class ability
{
  public:
    ability(int level);
    ability(int level, int stat);
    ~ability();
    std::string getName();
    std::string getDescription();
    std::string viewAbilityCombat();
    std::string viewAbility();
    void reduceCoolddown();
    int use(std::vector<int> playerStats);
 private:
   std::string name;
   std::string description;
   int cooldown;
   int currentCooldown;
   int diceRolls;
   int diceSize;
   std::vector<int> statRequirement;
   int abilityMultiplier;
   std::vector<dice> abilityDice;
};

#endif // ABILITY_H
