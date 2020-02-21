#include "baseCharacter.h"

baseCharacter::baseCharacter()
{
    mainStats.resize(4);
    statBonuses.resize(4);

}

baseCharacter::~baseCharacter()
{
    for(ability* i : activeAbilities)
    {
        delete i;
    }
    activeAbilities.clear();
    delete cInventory;
    delete equippedWeapon;
}

void baseCharacter::takeDamage(int damage)
{
    currentHealth -= damage;
}


void baseCharacter::checkStatBonuses()
{
    statBonuses.clear();
    statBonuses.resize(4);
    for (int i = 0; i < 3; i ++)
    {
        if (mainStats[i] > 10)
            statBonuses[i] += (mainStats[i] / 2) - 5;
        if (i == 1 && statBonuses[1] > 0 && mainStats[3] - statBonuses[1] > 0)
        {
            mainStats[3] += mainStats[3] - statBonuses[1];
        }

    }
    for (auto i : mainStats)
        std::cout << "\n" << i << std::endl;

}



int baseCharacter::useAbility(unsigned int index)
{
    if(activeAbilities.size() > index)
    {
        return activeAbilities[index]->dealDamage(mainStats);
    }
    else
    {
        return 0; //if 0 cout where called ability on cooldown.
    }
}

/** *****************  Getters *****************  */
  std::string baseCharacter::getName()
  {
    return name;
  }

  std::string baseCharacter::getRace()
  {
    return race;
  }

  int baseCharacter::getCurrentHealth()
  {
    return currentHealth;
  }

  int baseCharacter::getMaxHealth()
  {
    return maxHealth;
  }

  int baseCharacter::getLevel()
  {
    return level;
  }

  int baseCharacter::getSpeed()
  {
    return mainStats[3];
  }

  int baseCharacter::getDamagePower()
  {
    return -1;
  }

  int baseCharacter::dealDamage()
  {
    return -1;
  }

  bool baseCharacter::isDead()
  {
    return false;
  }

  inventory* baseCharacter::getInventory()
  {
    return cInventory;
  }

  std::vector<ability*> baseCharacter::getActiveAbilities()
  {
    return activeAbilities;
  }

  void baseCharacter::setGold(int g)
  {
    gold += g;
  }

  weapon* baseCharacter::getWeapon()
  {
      return equippedWeapon;
  }

  std::vector<int> baseCharacter::getStats()
  {
    return mainStats;
  }
  int baseCharacter::getGold()
  {
    return gold;
  }
