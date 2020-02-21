// Superclass of the player/monsters
#ifndef BASECHARACTER_H
#define BASECHARACTER_H

#include "ability.h"
#include "inventory.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

class ability;
class inventory;

class baseCharacter
{
public:
  baseCharacter();
  virtual ~baseCharacter();

  std::string getName();
  std::string getRace();
  int getCurrentHealth();
  int getMaxHealth();
  int getLevel();
  int getSpeed();
  int getDamagePower();

  int getGold();
  weapon* getWeapon();


  std::vector<int> getStats();
  inventory* getInventory();
  std::vector<ability*> getActiveAbilities();

  void setGold(int g);

  bool isDead();
  void takeDamage(int damage);
  int dealDamage();
  int useAbility(unsigned int index);

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
  inventory* cInventory;
  weapon* equippedWeapon;


  void checkStatBonuses();

  std::vector<ability*> activeAbilities;

};

#endif // BASECHARACTER_H
























