#include "weapon.h"

weapon::weapon()
{
  srand(time(NULL));

  readInNames();

}

weapon::~weapon()
{
  delete allNames;
}

void weapon::readInNames()
{
  allNames = new std::vector<std::string>;

  std::ifstream weaponNames;
  weaponNames.open(DIR_WEAPON);
  std::string line;

  while(getline(weaponNames, line))
  {
    allNames->push_back(line);
  }

  weaponNames.close();

  allNames->shrink_to_fit();
/**
  for(auto i : (*allNames))
  {
    std::cout << i << std::endl;
  }
  */
}

void weapon::generateWeapon(int level)
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

  if(allNames != nullptr)
  {
    name = allNames->at(rand() % allNames->size());
    name.append(addType(diceSize));
  }

  else
  {
    name = "invalid";
  }
}

std::string weapon::addType(int dSize)
{
  if(dSize == 4)
    return " Dagger";
  else if (dSize == 5)
    return " Short-Sword";
  else if (dSize == 6)
    return " Sword";
  else if (dSize == 7)
    return " Flail";
  else if (dSize == 8)
    return " Two-Handed Axe";
  else if (dSize == 9)
    return " Whip";
  else if (dSize == 10)
    return " Halberd";
  else if (dSize == 11)
    return " Morning-Star";
  else if (dSize == 12)
    return " Scythe";
  else
    return " Invalid";
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





