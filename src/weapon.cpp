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

  // Base + 4, then add + 0->4
  diceSize = level/2 + 4 + (rand() % 5);

  std::ifstream weaponNames;
  weaponNames.open(DIR_WEAPON);
  std::string line;

 // srand(time(NULL));
  int randLineNumber = rand() % 11;
  int lineCounter = 1;

  while(getline(weaponNames, line))
  {
    if(lineCounter % randLineNumber == 0)
    {
      name = line;

      return (*this);
    }
    lineCounter++;
  }

  //name = "N/A";

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





