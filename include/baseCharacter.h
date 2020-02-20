// Superclass of the player/monsters
#ifndef BASECHARACTER_H
#define BASECHARACTER_H

#include "ability.h"
#include "inventory.h"


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
  std::vector<int> getStats();
  inventory* getInventory();
  std::vector<ability*> getActiveAbilities();

  void setGold(int g);

  bool isDead();
  void takeDamage(int damage);
  int dealDamage();

protected:

  std::string race;
  std::string name;

  int currentHealth;
  int maxHealth;
  // 0 = strength 1 = dex 2 = int 3 = speed
  std::vector<int> mainStats;

  int level;
  int gold;
  inventory* cInventory;
  weapon* equippedWeapon;
  std::vector<ability*> activeAbilities;
};

#endif // BASECHARACTER_H
























