#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"

#include <vector>

class weapon : public item
{
  public:
    weapon();
    virtual ~weapon();

    int getDiceRolls();
    int getDiceSize();

    std::vector<int> getStatRequirements();


  private:
    int diceRolls;
    int diceSize;

    // stat type, stat amount, level
    std::vector<int> statRequirements;

};

#endif // WEAPON_H
