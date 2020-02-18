// Superclass of the player/monsters

#ifndef BASECHARACTER_H
#define BASECHARACTER_H
#include "weapon.h"
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
  std::vector<int> getStats();
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
  std::vector<int> mainStats;
  int speed;
  int gold;
  inventory* cInventory;
  weapon* equippedWeapon;
  std::vector<ability> activeAbilities;
};

#endif // BASECHARACTER_H
























