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

//inventory* baseCharacter::getInventory()
//{

//}

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
    return speed;
  }
  int baseCharacter::getDamagePower()
  {
    return 0;
  }
  int baseCharacter::dealDamage()
  {

  }

  bool baseCharacter::isDead()
  {

  }

  void baseCharacter::setGold(int g)
  {
    gold += g;
  }

  std::vector<int> baseCharacter::getStats()
  {

  }
  int baseCharacter::getGold()
  {
    return gold;
  }
