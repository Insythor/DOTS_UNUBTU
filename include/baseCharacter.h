// Superclass of the player/monsters

#ifndef BASECHARACTER_H
#define BASECHARACTER_H

#include "item.h"
#include "ability.h"
#include "inventory.h"

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
  bool isDead();
  int getLevel();
  int[3] getStats();
  int getSpeed();
  int getDamagePower();
  int getGold();
  void setGold(int g);
  inventory* getInventory();
  std::vector<ability> getActiveAbilities();

protected:
  std::string name;
  std::string race;
  int currentHealth;
  int maxHealth;
  int level;
  int mainStats[3];
  int speed;
  int gold;
  inventory cInventory;
  std::vector<ability> activeAbilities;


};

#endif // BASECHARACTER_H
























