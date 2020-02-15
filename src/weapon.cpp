#include "weapon.h"

weapon::weapon()
{
  // Initiate the random seed for generating weapons
  srand(time(NULL));
}

weapon::~weapon()
{
  //dtor
}

weapon weapon::generateWeapon(int level)
{
  if(level + 1 < 5)
  {
    diceRolls = level;
  }
  else
  {
    diceRolls = 4;
  }

  diceSize = level/2 + 4 + (rand() % 5);

  name = "N/A";

  return (*this);
}

std::ostream& operator << (std::ostream &out, weapon &toRender)
{
  out <<
        toRender.getName() << ", " << toRender.getDiceRolls()
        << "d" << toRender.getDiceSize()
  << std::endl;

  return out;
}

/** *****************  Getters *****************  */
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





