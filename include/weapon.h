#ifndef WEAPON_H
#define WEAPON_H

#define DIR_WEAPON "docs/DATA/weaponNames.txt"

#include "item.h"
#include "dice.h"

#include <iostream>
#include <fstream>
#include <time.h>
#include <random>
#include <vector>
#include <string>

class weapon : public item
{
  public:
    weapon();
    weapon(int l);
    virtual ~weapon();

     int getDiceRolls();
     int getDiceSize();

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
      @param[out]
    */
    int dealDamage();

  private:
     int diceRolls;
     int diceSize;

    // stat type, stat amount, level
    std::vector<int> statRequirements;


    std::vector<dice>* weaponDice;
    std::vector<std::string>* allNames;

    std::string addType(int dSize, int sType);

    void readInNames();


};

#endif // WEAPON_H



