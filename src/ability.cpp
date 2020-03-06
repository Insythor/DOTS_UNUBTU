#include "ability.h"

ability::ability()
{
  abilityDice = new std::vector<dice>;
}

ability::ability(int lev)
{
  srand(time(NULL));
  level = lev;
  statType = 6;
  index = determineIndex(level, statType);
  readInAbilityData();
  abilityDice = new std::vector<dice>;
}

ability::ability(int lev, int sType)
{
  srand(time(NULL));
  level = lev;
  statType = sType;
  index = determineIndex(level, statType);
  readInAbilityData();
  abilityDice = new std::vector<dice>;
}

ability::ability(int tid, int dRolls, int dSize)
{
  index = tid;
  //readInAbilityData();

  diceRolls = dRolls;
  diceSize = dSize;
  abilityDice = new std::vector<dice>;

  for (int i = 0; i < diceRolls; i++)
  {
    abilityDice->push_back(diceSize);
  }
  abilityDice->shrink_to_fit();

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

void ability::readInAbilityData()
{
  std::ifstream toRead;
  toRead.open(DIR_ABILITY);

  std::vector<std::string> tempData;
  std::string line;
  int lineCount = 0;

  if (toRead.is_open())
    {
        while (getline(toRead, line))
        {
            if (lineCount == index)
            {
                std::stringstream parsedText(line);
                while (getline(parsedText, line, ','))
                {
                    tempData.push_back(line);
                }
                break;
            }
            lineCount++;
        }
        toRead.close();
    }

  name = tempData[1];
  cooldown = std::stoi(tempData[2]);
  statRequirements.push_back(std::stoi(tempData[3]));
  statRequirements.push_back(std::stoi(tempData[4]));
  statRequirements.push_back(std::stoi(tempData[5]));
  description = tempData[6];

  tempData.erase(tempData.begin(), tempData.begin() + 7);

//transferred from gameManager
/*
  for (int i = 0; 1 < 60; i++)
  {
    index.push->push_back(ability::abilityData());
    ability::allAbilities->at(i).sReqs.resize(3);
    ability::allAbilities->at(i).index = std::stoi(tempData.at(0));
    ability::allAbilities->at(i).name = tempData.at(1);
    ability::allAbilities->at(i).cooldown = std::stoi(tempData.at(2));
    ability::allAbilities->at(i).sReqs[0] = std::stoi(tempData.at(3));
    ability::allAbilities->at(i).sReqs[1] = std::stoi(tempData.at(4));
    ability::allAbilities->at(i).sReqs[2] = std::stoi(tempData.at(5));
    ability::allAbilities->at(i).description = tempData.at(6);

    tempData.erase(tempData.begin(), tempData.begin() + 7);
  }
  /ability::allAbilities->shrink_to_fit();
*/
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
