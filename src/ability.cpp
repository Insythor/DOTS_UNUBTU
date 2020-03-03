#include "ability.h"

ability::ability()
{

}

ability::ability()
{

}

ability::ability(int level)
{

}

ability::ability(int level, int stat)
{

}

ability::~ability()
{
  //dtor
}

std::ostream& operator << (std::ostream& out, ability& toRender)
{
 out <<
 std::endl;
 return out;
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
