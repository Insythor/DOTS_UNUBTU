#include "weapon.h"

weapon::weapon()
{
  srand(time(NULL));
  weaponDice = new std::vector<dice>;
  allNames = new std::vector<std::string>;
  readInNames();

}

weapon::weapon(int l)
{
  srand(time(NULL));

  weaponDice = new std::vector<dice>;
  allNames = new std::vector<std::string>;
  readInNames();
  generateWeapon(l);
}

weapon::~weapon()
{

}

void weapon::readInNames()
{

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
  int statType = rand() % 3;
  int diceSize = level/2 + 4 + (rand() % 5);


  for(int i = 0; i < level; i++)
  {
    weaponDice->push_back(dice(diceSize));
  }
  weaponDice->shrink_to_fit();

  if(allNames != nullptr)
  {
//    std::cout << rand() % allNames->size() << std::endl;
    name = allNames->at(rand() % allNames->size());
    name.append(addType(diceSize, statType));
  }
  else
  {
    name = "invalid";
  }

  statRequirements.push_back(statType);

  statRequirements.push_back(level * 2);
  // If the weapon does max damage, increase the required level by 1
  if(diceSize >= 12)
  {
    statRequirements.push_back(level + 1);
  }
  else
  {
    statRequirements.push_back(level);
  }
//  for(auto i : statRequirements)
   // std::cout << i << std::endl;

  statRequirements.shrink_to_fit();
}

std::string weapon::addType(int dSize, int sType)
{

  switch(sType)
  {
    //  Strength
    case 0:
      if(dSize == 4)
        return " Club";
      else if (dSize == 5)
        return " Spiked-Club";
      else if (dSize == 6)
        return " Sword";
      else if (dSize == 7)
        return " Broad-Sword";
      else if (dSize == 8)
        return " Two-Handed Axe";
      else if (dSize == 9)
        return " Battle-Axe";
      else if (dSize == 10)
        return " Halberd";
      else if (dSize == 11)
        return " Maul";
      else if (dSize >= 12)
        return " Scythe";

    break;
    //  Dexterity
    case 1:
      if(dSize == 4)
        return " Dagger";
      else if (dSize == 5)
        return " Scimitar";
      else if (dSize == 6)
        return " Rapier";
      else if (dSize == 7)
        return " Flail";
      else if (dSize == 8)
        return " Glaive";
      else if (dSize == 9)
        return " Whip";
      else if (dSize == 10)
        return " Falchion";
      else if (dSize == 11)
        return " Morning-Star";
      else if (dSize >= 12)
        return " Bat'leth";

    break;
    // Int
    case 2:
      if(dSize == 4)
        return " Magic-Rock";
      else if (dSize < 7)
        return " Wand";
      else if (dSize < 11)
        return " Staff";
      else if (dSize == 11)
        return " Wizards Staff";
      else if (dSize >= 12)
        return " Grand-Staff";
    break;

    default:
      break;
  }

  return " Invalid Stat Requirement";
}

std::ostream& operator << (std::ostream &out, weapon &toRender)
{
  out <<
        toRender.getName() << ", " << toRender.getDiceRolls()
        << "d" << toRender.getDiceSize() <<
         "  Damage: " << toRender.dealDamage()
  << std::endl;

  return out;
}

int weapon::dealDamage()
{
  int tempDamage = 0;
  for(auto i : (*weaponDice))
  {
    tempDamage += i.roll();
  }

  return tempDamage;
}

/** *****************  Getters *****************  */
int weapon::getDiceRolls()
{
  return weaponDice->size();
}

int weapon::getDiceSize()
{
  return weaponDice->front().getSides();
}

std::vector<int> weapon::getStatRequirements()
{
  return statRequirements;
}





