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

    bool deleteConsumable(int index, int amount);
    bool deleteWeapon(int index);

//    void addConsumable(std::vector<consumable> conStack);

//    std::vector<consumable*> removeConsumable(int index, int amount);

    weapon* removeWeapon(int index);

    void addWeapon(weapon* wpnToAdd);
    int getInventorySize();
    void viewInventory();
    void increaseInventorySize(int amount);
//    std::vector<std::vector<consumable*>> removeAllConsumables();
    std::vector<weapon*> removeAllWeapons();
    bool checkForRoom(int amountToAdd);
  private:
//    std::vector<std::vector<consumable*>> consumableStacks;
    std::vector<weapon*> weapons;
    int inventorySize;
};

#endif // INVENTORY_H
