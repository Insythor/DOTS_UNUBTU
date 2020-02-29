// Superclass of the player/monsters
#ifndef BASECHARACTER_H
#define BASECHARACTER_H

#include "ability.h"
#include "inventory.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

//class ability;
//class inventory;

class baseCharacter
{
    /**
        @brief Default output operator overload for baseCharacter. This is essentially 
               a reduced version of the overloads in the player and monster class.
        @param[out] Name, HealthPoints, Level, Weapon
    */
    friend std::ostream& operator << (std::ostream& out, baseCharacter& toRender);
  //  friend std::ostream& operator << (std::ostream& out, baseCharacter& toRender);
public:
  baseCharacter();
  virtual ~baseCharacter();
  /**
    @brief  return the name of the character
    @param[out] std::string name
  */
  std::string getName();
  /**
    @brief return the race of the character
    @param[out] std::string race
  */
  std::string getRace();
  /**
    @brief  return the remaining health that the character has
    @param[out] int currentHP
  */
  int getCurrentHealth();
  /**
    @brief  return the maximum health points that the character has
    @param[out] int maxHP
  */
  int getMaxHealth();
  /**
    @brief
    @param[out]
  */
  int getLevel();
  /**
    @brief
    @param[out]
  */
  int getSpeed();
  /**
    @brief
    @param[out]
  */
  std::vector<int> getStatBonuses();
  /**
    @brief
    @param[out]
  */
  int getDamagePower();
  /**
    @brief
    @param[out]
  */
  int getGold();
  /**
    @brief
    @param[out]
  */
  weapon* getWeapon();
  /**
      @brief
      @param[out]
    */
  std::vector<int> getStats();
  /**
    @brief
    @param[out]
  */
  inventory* getInventory();
  /**
    @brief
    @param[out]
  */
  std::vector<ability*> getActiveAbilities();
  /**
    @brief
    @param[out]
  */
  void setGold(int g);
  /**
    @brief
    @param[out]
  */
  bool isDead();
  /**
    @brief
    @param[out]
  */
  void takeDamage(int damage);
  /**
    @brief
    @param[out]
  */
  int dealDamage();
  int useAbility(unsigned int index);

  void spawnWeapon(int level, std::vector<std::string>* weaponNames);

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
























