#ifndef ABILITY_H
#define ABILITY_H

#define DIR_ABILITY "../docs/DATA/abilitiesData.csv"

#include "dice.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
class ability
{
  public:
 /*    struct abilityData
    {
        int index;
        std::string name;
        int cooldown;
        std::vector<int> sReqs;
        std::string description;
    };
  */
    ability();
    ability(int tid, int dRolls, int dSize);
    ~ability();

    std::string getName();
    std::string getDescription();
    int getDiceRolls();
    int getDiceSize();
    int getCurrentCooldown();
    int getCooldown();
    std::vector<int> getStatRequirements();


    std::string viewAbilityCombat();
    friend std::ostream& operator << (std::ostream& out, ability& toRender);
    void reduceCoolddown();
    int dealDamage(std::vector<int> playerStats);

    //static std::vector<abilityData>* allAbilities;

 private:
    int index;
   std::string name;
   std::string description;
   int cooldown;
   int currentCooldown;
   bool onCooldown;
   int diceRolls;
   int diceSize;
   //[0] = stattype [1] = amount [2] = level req
   std::vector<int> statRequirements;
   std::vector<dice>* abilityDice;

   void readInAbilityData();
};

#endif // ABILITY_H
