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
  int baseCharacter::getStrength()
  {
    return strength;
  }
  int baseCharacter::getDexterity()
  {
    return dexterity;
  }
  int baseCharacter::getIntellect()
  {
    return intellect;
  }
  int baseCharacter::getSpeed()
  {
    return speed;
  }
  int baseCharacter::getDamagePower()
  {
    return damagePower;
  }
  int baseCharacter::getAbilityPower()
  {
    return abilityPower;
  }
  int baseCharacter::getGold()
  {
    return gold;
  }
  std::vector<item> baseCharacter::getInventory()
  {
    return inventory;
  }
  std::vector<ability> baseCharacter::getActiveAbilities()
  {
    return activeAbilities;
  }
