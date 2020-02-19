// Superclass of the player/monsters

#ifndef BASECHARACTER_H
#define BASECHARACTER_H

#include "weapon.h"
//#include "ability.h"
#include "inventory.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

class baseCharacter
{
public:
  baseCharacter();
  virtual ~baseCharacter();

  void takeDamage(int damage);
  int dealDamage();

  std::string getName();
  std::string getRace();

  int getCurrentHealth();
  int getMaxHealth();
  bool isDead();
  int getLevel();
  std::vector<int> getStats();
  int getSpeed();
  int getDamagePower();
  int getGold();
  weapon* getWeapon();

  void setGold(int g);
//  inventory getInventory();
//  std::vector<ability> getActiveAbilities();

protected:

  std::string race;
  std::string name;

  int currentHealth;
  int maxHealth;

  int level;
  // 0 = strength 1 = dex 2 = int 3 = speed
  std::vector<int> mainStats;
  // How much of a benafit do your stats give you
  std::vector<int> statBonuses;
  
  int gold;
//  inventory* cInventory;
  weapon* equippedWeapon;
//  std::vector<ability> activeAbilities;

  void checkStatBonuses();
};

#endif // BASECHARACTER_H
























