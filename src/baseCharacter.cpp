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

std::ostream& operator << (std::ostream& out, baseCharacter& toRender)
{
    return out;
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
        statBonuses[i] = (mainStats[i] - 10) / 2;
        // Every 4 points of dexterity increases the players speed by 1
        // I figure this way dex grants a bonus to speed, but since it also increases
        // damage, it needs to have some balance
        if (i == 1 && statBonuses[1] > 0 && statBonuses[1] - mainStats[3] > 1)
        {
            mainStats[3] += 1;
        }
    }
    updateDamagePower();
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

void baseCharacter::updateDamagePower()
{  
   damagePower = statBonuses[0]; 
}


int baseCharacter::dealDamage()
{
    return equippedWeapon->dealDamage() + damagePower;
}

void baseCharacter::spawnWeapon(int level, std::vector<std::string>* weaponNames)
{
   
    if (equippedWeapon != nullptr)
        delete equippedWeapon;
   
    if (this != nullptr)
    {
        equippedWeapon = new weapon(level, weaponNames);
        checkStatBonuses();
        
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
    return damagePower;
  }

  std::vector<int> baseCharacter::getStatBonuses()
  {
      return statBonuses;
  }

  bool baseCharacter::isDead()
  {
      if (currentHealth <= 0)
          return true;
      else
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
  