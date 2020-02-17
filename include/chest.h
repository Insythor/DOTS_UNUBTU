#ifndef CHEST_H
#define CHEST_H
#include "inventory.h"

class chest
{
  public:
    chest(int level);
    ~chest();
    bool getIsOpen();
    int lootGold();
    void open();
    inventory* getInventory();
  private:
    bool isOpen;
    int gold;
    inventory cinventory;
};

#endif // CHEST_H
