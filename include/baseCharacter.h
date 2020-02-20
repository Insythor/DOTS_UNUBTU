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
<<<<<<< HEAD
  int getGold();
  weapon* getWeapon();

  void setGold(int g);
//  inventory getInventory();
//  std::vector<ability> getActiveAbilities();
=======
  int getGold();
  std::vector<int> getStats();
  inventory* getInventory();
  std::vector<ability*> getActiveAbilities();

  void setGold(int g);

  bool isDead();
  void takeDamage(int damage);
  int dealDamage();
>>>>>>> 2273b378aa816a2b7feccc5c0cbc62879c97e27d

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
<<<<<<< HEAD
//  std::vector<ability> activeAbilities;

  void checkStatBonuses();
=======
  std::vector<ability*> activeAbilities;
>>>>>>> 2273b378aa816a2b7feccc5c0cbc62879c97e27d
};

#endif // BASECHARACTER_H
























