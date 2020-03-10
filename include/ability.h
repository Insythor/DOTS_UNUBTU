#ifndef ABILITY_H
#define ABILITY_H



#include "dice.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <random>
class ability
{
  public:
    ability();
    ability(int level);
    ability(int level, int sType);
    virtual ~ability();
    struct abilityData
    {
        int index;
        std::string name;
        std::vector<int> aStats;
        int cooldown;
        int dSize;
        int dRoll;
        std::string description;
    };
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
    static std::vector<std::vector<abilityData>>* allAbilities;

 private:
    int index;
    int level;
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
   void generateAbility();
   int determineIndex(int lev, int sType);
};

#endif // ABILITY_H
