#ifndef INVENTORY_H
#define INVENTORY_H
#include "consumable.h"
#include "weapon.h"
#include <stack>
#include <vector>
class inventory
{
  public:
    inventory(std::vector<weapon*> wpnsToAdd, std::vector<std::stack<consumable*>> consToAdd);
   ~inventory();
    void deleteConsumable(int index, int amount);
    void deleteWeapon(int index);
    void addConsumable(std::stack<consumable*> consumableStack);
    std::stack<consumable*> removeConsumable(int index, int amount);
    weapon* removeWeapon(int index);
    void addWeapon(weapon* wpnToAdd);
    int getInventorySize();
    void viewInventory();
    void increaseInventorySize();
    std::vector<std::stack<consumable*>> removeAllConsumables();
    std::vector<weapon*> removeAllWeapons();
    bool checkForRoom(int amountToAdd);
  private:
    std::vector<std::stack<consumable>> consumableStacks;
    std::vector<weapon> weapons;
    int InventorySize;
};

#endif // INVENTORY_H
