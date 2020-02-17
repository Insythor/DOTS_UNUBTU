#include "inventory.h"

inventory::inventory(std::vector<weapon*> wpnsToAdd, std::vector<std::stack<consumable*>> consToAdd)
{
  //ctor
}

inventory::~inventory()
{
  //dtor
}

int inventory::getInventorySize()
{

}

void inventory::viewInventory()
{

}

void inventory::increaseInventorySize()
{

}

std::vector<std::stack<consumable*>> inventory::removeAllConsumables()
{

}

std::vector<weapon*> inventory::removeAllWeapons()
{

}

bool inventory::checkForRoom(int amountToAdd)
{

}

void inventory::deleteConsumable(int index, int amount)
{

}

void inventory::deleteWeapon(int index)
{

}

void inventory::addConsumable(std::stack<consumable*>consumableStack)
{

}

std::stack<consumable*> inventory::removeConsumable(int index, int amount)
{

}

weapon* inventory::removeWeapon(int index)
{

}

void inventory::addWeapon(weapon* wpnToAdd)
{

}
