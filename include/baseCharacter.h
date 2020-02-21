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
  std::vector<int> getStatBonuses();
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

  int damagePower;
  weapon* equippedWeapon;


  std::vector<ability*> activeAbilities;

  void checkStatBonuses();
  /**
    @brief Check if the equipped weapon gain a bonus to damage 
           based on the type of weapon it is and the players stats
           so use this weapon
  */
  void updateDamagePower();
  

};

#endif // BASECHARACTER_H
























