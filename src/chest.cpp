#include "chest.h"

chest::chest(int level)
{
  cinventory = new inventory();
  srand (time(NULL));
  int spawnLevel = level / 5;
  int typeOfConsumable;
  int consumableToSpawn = rand() % 100 + 1;
  int consumableSpawnAmount = rand() % 100 + 1;
  int weaponSpawn = rand() % 100 + 1;
  int goldRange = rand() % 100 + 1;
  std::vector<consumable*> tempCon;
  if(goldRange <= 5)
  {
    gold = rand() % 21 + 30;
  }
  else if(goldRange > 5 && goldRange <= 80)
  {
    gold = rand() % 11 + 1;
  }
  else
  {
    gold = rand() % 21 + 10;
  }
  if(spawnLevel < 1)
    spawnLevel = 1;
  else if(spawnLevel > 5)
    spawnLevel = 5;
  if(weaponSpawn < 20)
  {
      cinventory->addWeapon(new weapon(spawnLevel));
  }
  if(consumableToSpawn < 6)
  {
    typeOfConsumable = rand() % 4 + 5;
  }
  else
  {
    typeOfConsumable = spawnLevel - 1;
  }
  if(consumableSpawnAmount <= 100 && consumableSpawnAmount > 50)
  {
    tempCon.push_back(new consumable(typeOfConsumable));
  }
  else if(consumableSpawnAmount <= 50 && consumableSpawnAmount > 30)
  {
    for(int i = 0; i < 2; i++)
      tempCon.push_back(new consumable(typeOfConsumable));
  }
  else if(consumableSpawnAmount <= 10)
  {
     for(int i = 0; i < 3; i++)
      tempCon.push_back(new consumable(typeOfConsumable));
  }
  cinventory->addConsumables(tempCon);
}

chest::~chest()
{
  //dtor
}

bool chest::getIsOpen()
{
  return isOpen;
}

int chest::lootGold()
{
  return gold;
}

void chest::open()
{
  isOpen = true;
}

inventory* chest::getInventory()
{
  return cinventory;
}
