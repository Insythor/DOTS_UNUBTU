#include "player.h"
player::player(std::string tName, std::string tRace, int tMaxHP,
              std::vector<int> tStat)
{
  name = tName;
  race = tRace;

  maxHealth = tMaxHP;
  currentHealth = maxHealth;

  mainStats = tStat;

  equippedWeapon = new weapon;
}

player::~player()
{
  //dtor
}



void player::swapAbilities()
{

}

void player::addExperience(int toAdd)
{
  currentExperience += toAdd;
  checkForLevelUp();
}

void player::checkForLevelUp()
{
 if(currentExperience >= maxExperience)
  {
      int difference = currentExperience - maxExperience;
      leveUp();
      currentExperience = difference;
      checkForLevelUp(); //recursion for if you gain more than one level
  }
}

void player::leveUp()
{
    level++;
    //osrs multiplier;
    maxExperience += ((level + 1) - 1 + (300 * pow(2, ((level + 1) - 1) / 7))) / 4;
}

void player::addToStats(std::vector<int>toAdd)
{
  toAdd.clear();
}

void player::applyStatusEffect(std::vector<int>toApply)
{
  toApply.clear();
}

void player::spawnWeapons(int index)
{
  index *= -1;
}
void player::useConsumable(unsigned int index)
{
    std::vector<consumable*> tempC = cInventory->removeConsumable(index, 1);
    if(tempC.size() > 0)
    {
        int stat = tempC.front()->getStatToAdd();
        int amount = tempC.front()->getStatValue();
        if(tempC.front()->getIsPerminant())
        {
            switch(stat)
            {
            case 1: mainStats[0] += amount;
                    break;
            case 2: mainStats[1] += amount;
                    break;
            case 3: mainStats[2] += amount;
                    break;
            case 4: mainStats[3] += amount;
                    break;
            case 5: maxHealth += amount;
                    currentHealth += amount;
                    break;
            }
        }
        else
        {
            switch(stat)
            {
            case 1: statusEffect[0] += amount;
                    break;
            case 2: statusEffect[1] += amount;
                    break;
            case 3: statusEffect[2] += amount;
                    break;
            case 4: statusEffect[3] += amount;
                    break;
            }
        }
        delete tempC.front();
        tempC.clear();
    }
}
