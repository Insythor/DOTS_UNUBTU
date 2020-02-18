#include "ability.h"

ability::ability(int l)
{

}

ability::ability(int level, int stat)
{

}

ability::~ability()
{
  //dtor
}

std::string ability::getName()
{
  return "n/a";
}

std::string ability::getDescription()
{
  return "n/a";
}

std::string ability::viewAbilityCombat()
{
  return "n/a";
}

std::string ability::viewAbility()
{
  return "n/a";
}

void ability::reduceCoolddown()
{

}

int ability::use(std::vector<int>playerStats)
{
  return 0;
}
