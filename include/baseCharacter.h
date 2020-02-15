// Superclass of the player/monsters

#ifndef BASECHARACTER_H
#define BASECHARACTER_H

#include "item.h"
#include "ability.h"

#include <string>
#include <vector>

class baseCharacter
{
public:
  baseCharacter();
  ~baseCharacter();

  int takeDamage(int damage);
  int dealDamage();

  std::string getName();
  std::string getRace();

  int getCurrentHealth();
  int getMaxHealth();

  int getLevel();

  int getStrength();
  int getDexterity();
  int getIntellect();
  int getSpeed();
  int getDamagePower();
  int getAbilityPower();

  int getGold();

  std::vector<item> getInventory();
  std::vector<ability> getActiveAbilities();

protected:
  std::string name;
  std::string race;

  int currentHealth;
  int maxHealth;

  int level;

  int strength;
  int dexterity;
  int intellect;
  int speed;
  int damagePower;
  int abilityPower;

  int gold;
  std::vector<item> inventory;
  std::vector<ability> activeAbilities;


};

#endif // BASECHARACTER_H
























