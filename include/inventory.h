#ifndef INVENTORY_H
#define INVENTORY_H

#include "consumable.h"
#include "weapon.h"
#include "ability.h"
#include <vector>
#include <iostream>

class inventory
{
  public:
    inventory();
   ~inventory();
    /**
      @brief
    */
    bool deleteConsumables(unsigned int index, unsigned int amount);
    /**
      @brief
    */
    bool deleteWeapon(unsigned int index);
    /**
      @brief
    */
    void addConsumables(std::vector<consumable*> conStack);
    /**
      @brief
    */
    void addAbility(ability* abilityToAdd);
    /**
      @brief
    */
    ability* removeAbility(unsigned int index);
    /**
      @brief
    */
    std::vector<consumable*> removeConsumables(unsigned int index,
                                               unsigned int amount);
    /**
      @brief
    */
    std::vector<std::vector<consumable*>> removeAllConsumables();
    /**
      @brief
    */
    weapon* removeWeapon(unsigned int index);
    /**
      @brief
    */
    void addWeapon(weapon* wpnToAdd);
    /**
      @brief
    */
    int getInventorySize();
    /**
      @brief
    */
    void viewInventory();
    /**
      @brief
    */
    void increaseInventorySize(int amount);
    /**
      @brief
    */
    std::vector<weapon*> removeAllWeapons();
    /**
      @brief
    */
    bool checkForRoom(unsigned int amountToAdd);

    std::vector<ability*> getAbilities();

  private:
    std::vector<std::vector<consumable*>> consumableStacks;
    std::vector<weapon*> weapons;
    std::vector<ability*> abilities;
    std::string formatIndex(std::string index);
    int inventorySize;
};

#endif // INVENTORY_H
