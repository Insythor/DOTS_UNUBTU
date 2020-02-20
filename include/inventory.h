#ifndef INVENTORY_H
#define INVENTORY_H

#include "consumable.h"
#include "weapon.h"

#include <vector>
#include <iostream>

class inventory
{
  public:
    inventory();
   ~inventory();
    bool deleteConsumable(unsigned int index, unsigned int amount);
    bool deleteWeapon(unsigned int index);
    void addConsumable(std::vector<consumable*> conStack);
    std::vector<consumable*> removeConsumable(unsigned int index, unsigned int amount);
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
    int inventorySize;
};

#endif // INVENTORY_H
