#ifndef ABILITY_H
#define ABILITY_H

#include "dice.h"
#include <string>
#include <vector>
#include <iostream>
class ability
{
  public:
    ability();
    ability(int level);
    ability(int level, int stat);
    ~ability();
    std::string getName();
    std::string getDescription();
    int getDiceRolls();
    int getDiceSize();
    int getCurrentCooldown();
    std::string viewAbilityCombat();
    friend std::ostream& operator << (std::ostream& out, ability& toRender);
    void reduceCoolddown();
    int dealDamage(std::vector<int> playerStats);
 private:
   std::string name;
   std::string description;
   int cooldown;
   int currentCooldown;
   bool onCooldown;
   int diceRolls;
   int diceSize;
   std::vector<int> statRequirement;
   int abilityMultiplier;
   std::vector<std::string>* allNames;
   std::vector<dice>* abilityDice;
};

#endif // ABILITY_H
