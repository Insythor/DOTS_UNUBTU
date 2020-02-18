#include "inventory.h"

inventory::inventory()
{
  inventorySize = 10;
}

inventory::~inventory()
{

}

int inventory::getInventorySize()
{
  return inventorySize;
}

void inventory::viewInventory()
{
  std::cout << "Weapon's\n";
  std::cout << "-----------------------------------\n";
  for(weapon* i : weapons)
  {
      std::cout << i << std::endl;
  }
  std::cout << "Consumable's\n";
  std::cout << "-----------------------------------\n";
  for(std::vector<consumable*> j : consumableStacks)
  {
    if(!j.empty())
    {
//      std::cout << j << std::endl;
//      std::cout << " x" + j.size() << std::endl;
    }
  }

}


void inventory::increaseInventorySize(int amount)
{
  inventorySize += amount;
}

std::vector<std::vector<consumable*>> inventory::removeAllConsumables()
{
  std::vector<std::vector <consumable*>> tempvector = consumableStacks;
  for(std::vector<consumable*> i : consumableStacks)
  {
    i.clear();
  }
  return tempvector;
}

std::vector<weapon*> inventory::removeAllWeapons()
{
  std::vector<weapon*> tmpvector = weapons;
  weapons.clear();
  return tmpvector;
}

bool inventory::checkForRoom(int amountToAdd)
{
  int counter = 0;
  for(std::vector<consumable*> i : consumableStacks)
  {
    counter += i.size();
  }
  counter += weapons.size();
  if(counter > inventorySize)
  {
    return false;
  }
  else
  {
    return true;
  }
}

bool inventory::deleteConsumable(int index, int amount)
{
  if(consumableStacks.size() > index)
    {
      if(consumableStacks[index].size() < amount)
      {
       amount = consumableStacks[index].size();
      }
      for(int i = amount; i <= 0; i--)
      {
        delete consumableStacks[index][0];
        consumableStacks[index].erase(consumableStacks[index].begin());
      }
    }
}

bool inventory::deleteWeapon(int index)
{
  if(weapons.size() > index)
  {
    delete weapons[index];
    weapons.erase(weapons.begin() + index);
  }
}

void inventory::addConsumable(std::vector<consumable> conStack)
{
  if(conStack.size() > 0)
  {
    int index = conStack[0]->getID();
    for(consumable* con : conStack)
    {
      if(con != nullptr)
      {
        consumableStacks[index].push_back(con);
      }
    }
  }
}


std::vector<consumable*> inventory::removeConsumable(int index, int amount)
{
  std::vector<consumable*> tempvector;
  if(consumableStacks.size() > index)
  {
    if(consumableStacks[index].size() < amount)
    {
     amount = consumableStacks[index].size();
    }
    for(int i = amount; i <= 0; i--)
    {
      tempvector.push_back(consumableStacks[index][0]);
      consumableStacks[index].erase(consumableStacks[index].begin());
    }
  }
  return tempvector;
}


weapon* inventory::removeWeapon(int index)
{
  weapon* tempweapon;
  if(weapons.size() > index)
  {
    tempweapon = weapons[index];
    weapons.erase(weapons.begin() + index);
  }
  return tempweapon;
}

void inventory::addWeapon(weapon* wpnToAdd)
{
  if(wpnToAdd != nullptr)
  {
    weapons.push_back(wpnToAdd);
  }
}
