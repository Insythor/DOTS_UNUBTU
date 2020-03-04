#ifndef WEAPON_H
#define WEAPON_H

#define DIR_WEAPON "../docs/DATA/weaponNames.txt"

#include "item.h"
#include "dice.h"

#include <iostream>
#include <fstream>

#include <vector>
#include <string>
// Temp for random weapon generation
#include <time.h>
#include <random>
#include <memory>

class weapon : public item
{
  public:
    weapon();
    weapon(int l, std::vector<std::string>* nameDicPtr);
    weapon(std::string name, int dSize, int dRolls, std::vector<int> sReq);
    ~weapon();
    /**
        @brief Return the name of this weapon
        @param[out] std::string name
    */
    std::string getName();
    /**
        @brief Return the number of rolls with weapon has
        @param[out] int diceRolls
    */
    int getDiceRolls();
    /**
        @brief Return the size of this weapons dice
        @param[out] int diceSize
    */
    int getDiceSize();
    /**
        @brief Return the stat type, stat amount, and level required to use this weapon
        @param[out] std::vector<int> statRequirements[0] = Stat Type
        @param[out] std::vector<int> statRequirements[1] = Stat Amount
        @param[out] std::vector<int> statRequirements[2] = Level Requirement
    */
    std::vector<int> getStatRequirements();
    /**
      weapon should be a constant reference, but when it's a constant
      it gets angry that we're accessing non constant members. So just
      don't change any variables of the weapon in the print function...
    */
    friend std::ostream& operator << (std::ostream& out, weapon &toRender);
    friend std::ostream& operator >> (std::ostream& out, weapon& readIn);
    /**
      @brief Spawn a random weapon based, stats and damage increased
    */
    void generateWeapon(int level);
    /**
      @brief Iterate through all of the dice rolls and return the total value
             of all the rolls
      @param[out] int sum of dice rolls
    */
    int dealDamage();

  private:
     std::string name;

     int diceRolls;
     int diceSize;

    // stat type, stat amount, level
    std::vector<int> statRequirements;

    std::vector<dice>* weaponDice;
    std::vector<std::string>* allNames;
    /**
        @brief Based on which stat is required to use this weapon, give it a type
        @param [out] std::string Type of weapon (i.e. Sword, Rapier, Wand)
        @param [in] int How many sides the dice has
        @param [in] int stat required to use this weapon
    */
    std::string formatOutput(int type, std::string value);
    std::string addType(int dSize, int sType);
};

#endif // WEAPON_H



