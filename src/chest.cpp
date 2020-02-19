#include "chest.h"

chest::chest(int level)
{
  level *= -1;
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

}

inventory* chest::getInventory()
{
  return cinventory;
}
