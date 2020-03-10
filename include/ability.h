#ifndef ABILITY_H
#define ABILITY_H
// User Defined
#include "dice.h"
// Containers
#include <string>
#include <vector>
// I/O
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
// Time
#include <random>


class ability
{
  friend std::ostream& operator << (std::ostream& out, ability& toRender);
  public:
    /**
      @brief
    */
    ability();
    /**
      @brief
    */
    ability(int level);
    /**
      @brief
    */
    ability(int level, int sType);
    ability(int level, int sType, int abil);
    /**
      @brief
    */
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
    /**
      @brief
    */
    std::string getName();
    /**
      @brief
    */
    std::string getDescription();
    /**
      @brief
    */
    int getDiceRolls();
    /**
      @brief
    */
    int getDiceSize();
    /**
      @brief
    */
    int getCurrentCooldown();
    /**
      @brief
    */
    int getCooldown();
    /**
      @brief
    */
    std::vector<int> getStatRequirements();
    /**
      @brief
    */
    std::string viewAbilityCombat();
    /**
      @brief
    */
    void reduceCoolddown();
    /**
      @brief
    */
    int dealDamage(std::vector<int> playerStats);
    /**
      @brief
    */
    static std::vector<std::vector<std::vector<abilityData>>>* allAbilities;

 private:
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
};

#endif // ABILITY_H
