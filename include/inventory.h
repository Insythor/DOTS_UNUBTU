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
    bool deleteConsumables(unsigned int index, unsigned int amount);
    bool deleteWeapon(unsigned int index);
    void addConsumables(std::vector<consumable*> conStack);
    void addAbility(ability* abilityToAdd);
    ability* removeAbility(unsigned int index);
    std::vector<consumable*> removeConsumables(unsigned int index, unsigned int amount);
    std::vector<std::vector<consumable*>> removeAllConsumables();
    weapon* removeWeapon(unsigned int index);
    void addWeapon(weapon* wpnToAdd);
    int getInventorySize();
    void viewInventory();
    void increaseInventorySize(int amount);
    std::vector<weapon*> removeAllWeapons();
    bool checkForRoom(unsigned int amountToAdd);

  private:
    std::vector<std::vector<consumable*>> consumableStacks;
    std::vector<weapon*> weapons;
    std::vector<ability*> abilities;
    std::string formatIndex(std::string index);
    int inventorySize;
};

#endif // INVENTORY_H
