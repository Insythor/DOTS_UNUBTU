#include "weapon.h"

weapon::weapon()
{
  weaponDice = new std::vector<dice>;
  allNames = nullptr;
}

weapon::weapon(int l, std::vector<std::string>* nameDicPtr)
{
  srand(time(NULL));
//  std::cout << "constructed" << std::endl;
  weaponDice = new std::vector<dice>;
  allNames = nameDicPtr;

  generateWeapon(l);
}

weapon::weapon(std::string nam, int dSize, int dRolls, std::vector<int> sReq)
{
    allNames = nullptr;
    
    name = nam;
    diceSize = dSize;
    diceRolls = dRolls;
    statRequirements = sReq;
    weaponDice = new std::vector<dice>;

    for (int i = 0; i < diceRolls; i++)
    {
        weaponDice->push_back(diceSize);
    }
    
    weaponDice->shrink_to_fit();
}

weapon::~weapon()
{
    delete weaponDice;
}

void weapon::generateWeapon(int level)
{
  // Choose a random stat: [0] str, [1] dex, [2] int
  int statType = rand() % 3;
  int diceSize = level/2 + 4 + (rand() % 5);

  // Add one dice of the randomly chosen size to the weaponDice vector
  for(int i = 0; i < level; i++)
  {
    weaponDice->push_back(dice(diceSize));
  }
  // Optimize!
  weaponDice->shrink_to_fit();
  // If the weapon names dictionary was read in, select a random name
  // Then delete that name from the dictionary
  if(allNames != nullptr)
  {
    int tempIndex = rand() % allNames->size();
    name = allNames->at(tempIndex);
    allNames->erase(allNames->begin() + tempIndex);
    name.append(addType(diceSize, statType));
  }
  else
  {
    name = "invalid";
  }
  // Add the stat requirement chosen above to the statRequirements
  statRequirements.push_back(statType);
  // Required amount of stats to use this weapon
  // NEEDS TO BE BALANCED
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
  // Optimize
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
  for(auto i : *weaponDice)
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

std::string weapon::getName()
{
    return name;
}



