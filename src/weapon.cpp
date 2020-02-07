#include "weapon.h"

weapon::weapon()
{
  //ctor
}

weapon::~weapon()
{
  //dtor
}

int weapon::getDiceRolls()
{
  return diceRolls;
}

int weapon::getDiceSize()
{
  return diceSize;
}

std::vector<int> weapon::getStatRequirements()
{
  return statRequirements;
}





