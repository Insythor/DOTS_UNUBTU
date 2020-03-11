#include "ability.h"

ability::ability()
{
  abilityDice = new std::vector<dice>;
}

ability::ability(int lev)
{
  srand(time(NULL));
  if(lev > 5 || lev < 1)
    lev = 5;

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
/** Commented out for testing: We need to check if the vector is empty */
//  ability::allAbilities->at(lev - 1)[rStat].erase
//                (ability::allAbilities->at(lev - 1)[rStat].begin() + rAbility);
}

ability::ability(int lev, int sType)
{
    if(lev > 5 || lev < 1)
      lev = ability::allAbilities->size() - 1;
    if(sType > 3 || sType < 0)
      sType = ability::allAbilities->at(lev).size() - 1;

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
// Testing : going to be deleted
ability::ability(int lev, int sType, int abil)
{
  if(lev > 5 || lev < 1)
      lev = ability::allAbilities->size();
  if(sType > 3 || sType < 0)
    sType = ability::allAbilities->at(lev).size() - 1;
  if(abil > 3 || abil < 0)
    abil = ability::allAbilities->at(lev)[sType].size() -1;

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
  ability::allAbilities->at(lev - 1)[sType].erase
        (ability::allAbilities->at(lev - 1)[sType].begin());

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

  int statReqSpacer = 10;
  if(toRender.getStatRequirements()[1] > 9)
    statReqSpacer--;

 out
//    << "| Name | CD | " + tempReqStat + " | Level | "
    << toRender.getName() << std::setw(15 - toRender.getName().length() / 2)
    << "CD: " << toRender.getCooldown() << std::setw(7)
    << tempReqStat << toRender.getStatRequirements()[1]
     << std::setw(statReqSpacer)
    << "Level: " << toRender.getStatRequirements()[2] + 1 << std::setw(3)
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

void ability::reduceCooldown()
{
    // Check if this ability is on cooldown 
    // && if the remaining cooldown is > 0
        // Stops the currentCD from going negative for combat HUD
    if(onCooldown && currentCooldown > 0)
    {
        currentCooldown--;
        // Take this ability off cooldown
        if(currentCooldown <= 0)
        {
            onCooldown = false;
        }
    }
}

int ability::dealDamage()
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

