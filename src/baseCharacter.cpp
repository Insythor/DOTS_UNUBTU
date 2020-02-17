#include "baseCharacter.h"

baseCharacter::baseCharacter()
{


}

baseCharacter::~baseCharacter()
{


}

int baseCharacter::takeDamage(int damage)
{
    currentHealth -= damage;

    return currentHealth;
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
    return speed;
  }
  int baseCharacter::getDamagePower()
  {
    return 0;
  }
  int baseCharacter::dealDamage()
  {

  }
  void basetakeDamage(int toTake)
  {

  }
  bool baseCharacter::isDead()
  {

  }

  void baseCharacter::setGold(int g)
  {
    gold += g;
  }
  int baseCharacter::getGold()
  {
    return gold;
  }
