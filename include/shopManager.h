#ifndef SHOPMANAGER_H
#define SHOPMANAGER_H
#include "inventory.h"

class shopManager
{
  public:
    shopManager(int level);
    shopManager();
    ~shopManager();
    inventory* getInventory();
    int getGold();
    void setGold();
  private:
    int gold;
    inventory* sinventory;
};

#endif // SHOPMANAGER_H
