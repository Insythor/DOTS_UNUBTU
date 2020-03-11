/**
    @author 

    @brief

*/

#ifndef CHEST_H
#define CHEST_H
// User Defined
#include "inventory.h"

class chest
{
  public:
    /**
      @brief
      @param[in]
    */
    chest(int level);
    ~chest();
    /**
      @brief
      @param[out]
    */
    bool getIsOpen();
    /**
      @brief
      @param[out]
    */
    int lootGold();
    /**
      @brief
    */
    void open();
    /**
      @brief
      @param[out]
    */
    inventory* getInventory();

  private:
    bool isOpen;
    int gold;
    inventory* cinventory;
};

#endif // CHEST_H
