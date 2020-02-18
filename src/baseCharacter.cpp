#include "baseCharacter.h"

baseCharacter::baseCharacter()
{


}

baseCharacter::~baseCharacter()
{


}

void baseCharacter::takeDamage(int damage)
{
    currentHealth -= damage;
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

  void baseCharacter::setGold(int g)
  {
    gold += g;
  }

  std::vector<int> baseCharacter::getStats()
  {
    return mainStats;
  }
  int baseCharacter::getGold()
  {
    return gold;
  }
