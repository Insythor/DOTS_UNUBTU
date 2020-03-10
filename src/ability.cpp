#include "ability.h"

ability::ability()
{
  abilityDice = new std::vector<dice>;
}

ability::ability(int lev)
{
  srand(time(NULL));
  int rStat = rand() % ability::allAbilities->at(lev - 1).size();
  int rAbility = rand() % ability::allAbilities->at(lev - 1)[rStat].size();
  ability::abilityData ad = ability::allAbilities->at(lev - 1)[rStat][rAbility];

  name = ad.name;

  cooldown = ad.cooldown;
  currentCooldown = 0;

  diceRolls = ad.dRoll;
  diceSize = ad.dSize;

  description = ad.description;

  statRequirements.push_back(ad.aStats[0]);
  statRequirements.push_back(ad.aStats[1]);
  statRequirements.push_back(ad.aStats[2]);

  abilityDice = new std::vector<dice>;

  for(int i = 0; i < diceRolls; i++)
    abilityDice->push_back(dice(diceSize));

  ability::allAbilities->at(lev - 1)[rStat].erase
                (ability::allAbilities->at(lev - 1)[rStat].begin() + rAbility);
}

ability::ability(int lev, int sType)
{
  srand(time(NULL));
  int rAbility = rand() % ability::allAbilities->at(lev - 1)[sType].size();
  ability::abilityData ad = ability::allAbilities->at(lev - 1)[sType][rAbility];
  name = ad.name;
  cooldown = ad.cooldown;
  currentCooldown = 0;
  diceRolls = ad.dRoll;
  diceSize = ad.dSize;
  description = ad.description;
  statRequirements.push_back(ad.aStats[0]);
  statRequirements.push_back(ad.aStats[1]);
  statRequirements.push_back(ad.aStats[2]);
  abilityDice = new std::vector<dice>;
  for(int i = 0; i < diceRolls; i++)
    abilityDice->push_back(dice(diceSize));
  ability::allAbilities->at(lev - 1)[sType].erase
        (ability::allAbilities->at(lev - 1)[sType].begin() + rAbility);
}

ability::ability(int lev, int sType, int abil)
{
  srand(time(NULL));
  ability::abilityData ad = ability::allAbilities->at(lev - 1)[sType][abil];
  name = ad.name;
  cooldown = ad.cooldown;
  currentCooldown = 0;
  diceRolls = ad.dRoll;
  diceSize = ad.dSize;
  description = ad.description;
  statRequirements.push_back(ad.aStats[0]);
  statRequirements.push_back(ad.aStats[1]);
  statRequirements.push_back(ad.aStats[2]);
  abilityDice = new std::vector<dice>;
  for(int i = 0; i < diceRolls; i++)
    abilityDice->push_back(dice(diceSize));
//  ability::allAbilities->at(lev - 1)[sType].erase
//        (ability::allAbilities->at(lev - 1)[sType].begin());

}

ability::~ability()
{
  delete abilityDice;
}

std::ostream& operator << (std::ostream& out, ability& toRender)
{
  std::string tempReqStat;

  switch(toRender.getStatRequirements()[0])
  {
  case 0:
    tempReqStat = "Str: ";
    break;
    case 1:
    tempReqStat = "Dex: ";
    break;
    case 2:
    tempReqStat = "Int: ";
    break;
    case 3:
    tempReqStat = "Spd: ";
    break;
  }

 out
//    << "| Name | CD | " + tempReqStat + " | Level | "
    << toRender.getName() << std::setw(20 - toRender.getName().length())
    << "CD: " << toRender.getCooldown() << std::setw(7)
    << tempReqStat << toRender.getStatRequirements()[1] << std::setw(10)
    << "Level: " << toRender.getStatRequirements()[2] + 1 << std::setw(5)
    << toRender.getDiceRolls() << "d" << toRender.getDiceSize()


 << std::endl;

 return out;
}

/**     GETTERS       */
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

