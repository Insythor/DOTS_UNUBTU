#ifndef ABILITY_H
#define ABILITY_H

#include "dice.h"
#include <string>
#include <vector>
#include <iostream>
class ability
{
  public:
     struct abilityData
    {
        int index;
        std::string race;
        int maxHP;
        std::vector<int> mStats;
        std::string description;
    };
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
   //[0] = stattype [1] = amount [2] = level req
   std::vector<int> statRequirement;
   int abilityMultiplier;
   static std::vector<abilityData>* allAbilities;
   std::vector<dice>* abilityDice;
};

#endif // ABILITY_H
