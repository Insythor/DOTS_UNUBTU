#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"

#include <iostream>
#include <vector>

class weapon : public item
{
  public:
    weapon();
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

    weapon generateWeapon(int level);

  private:
     int diceRolls;
     int diceSize;

    // stat type, stat amount, level
    std::vector<int> statRequirements;



};

#endif // WEAPON_H



