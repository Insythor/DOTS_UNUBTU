#include "ability.h"

ability::ability()
{
  abilityDice = new std::vector<dice>;
}

ability::ability(int lev)
{
  srand(time(NULL));
  level = lev;
  index = determineIndex(level, 6);
  abilityDice = new std::vector<dice>;
}

ability::ability(int lev, int sType)
{
  srand(time(NULL));
  level = lev;
  index = determineIndex(level, sType);
  abilityDice = new std::vector<dice>;
}

ability::~ability()
{
  delete abilityDice;
}

std::ostream& operator << (std::ostream& out, ability& toRender)
{
 out <<
 std::endl;
 return out;
}



std::string ability::getName()
{
  return name;
}

std::string ability::getDescription()
{
  return description;
}

int ability::getDiceRolls()
{
    return abilityDice->size();
}

int ability::getDiceSize()
{
    return abilityDice->front().getSides();
}

int ability::getCurrentCooldown()
{
    return currentCooldown;
}

int ability::getCooldown()
{
    return cooldown;
}

std::vector<int> ability::getStatRequirements()
{
    return statRequirements;
}

std::string ability::viewAbilityCombat()
{
  return "n/a";
}

void ability::reduceCoolddown()
{
    if(onCooldown)
    {
        currentCooldown--;
        if(currentCooldown <= 0)
        {
            onCooldown = false;
        }
    }
}

int ability::dealDamage(std::vector<int>playerStats)
{
    if(!onCooldown)
    {
        onCooldown = true;
        currentCooldown = cooldown;
        int tempDamage = 0;
        for(dice i : *abilityDice)
        {
            tempDamage += i.roll();
        }
        return tempDamage;
    }
    else
    {
        return 0;
    }
}

int ability::determineIndex(int lev, int sType)
{
  switch(sType)
  {
  //Strength
  case 0:
    if (lev == 1)
      return rand() % 3;
    else if (lev == 2)
      return rand() % 3 + 12;
    else if (lev == 3)
      return rand() % 3 + 24;
    else if (lev == 4)
      return rand() % 3 + 36;
    else if (lev == 5)
      return rand() % 3 + 48;
  break;

  //Dexterity
  case 1:
    if (lev == 1)
      return rand() % 3 + 3;
    else if (lev == 2)
      return rand() % 3 + 15;
    else if (lev == 3)
      return rand() % 3 + 27;
    else if (lev == 4)
      return rand() % 3 + 39;
    else if (lev == 5)
      return rand() % 3 + 51;
  break;

  //Intelligence
  case 2:
    if (lev == 1)
      return rand() % 3 + 6;
    else if (lev == 2)
      return rand() % 3 + 18;
    else if (lev == 3)
      return rand() % 3 + 30;
    else if (lev == 4)
      return rand() % 3 + 42;
    else if (lev == 5)
      return rand() % 3 + 54;
  break;

  //Speed
  case 3:
    if (lev == 1)
      return rand() % 3 + 9;
    else if (lev == 2)
      return rand() % 3 + 21;
    else if (lev == 3)
      return rand() % 3 + 33;
    else if (lev == 4)
      return rand() % 3 + 45;
    else if (lev == 5)
      return rand() % 3 + 57;
  break;

  //Random Stat
  case 6:
    if (lev == 1)
      return rand() % 12;
    if (lev == 2)
      return rand() % 12 + 12;
    if (lev == 3)
      return rand() % 12 + 24;
    if (lev == 4)
      return rand() % 12 + 36;
    if (lev == 5)
      return rand() % 12 + 48;
  break;
  }

}
