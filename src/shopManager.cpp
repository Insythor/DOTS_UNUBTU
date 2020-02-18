#include "shopManager.h"

shopManager::shopManager()
{
  //ctor
}

shopManager::~shopManager()
{
  //dtor
}
shopManager::shopManager(int level)
{
  level *= -1;
}



int shopManager::getGold()
{
  return gold;
}

void shopManager::setGold()
{

}
