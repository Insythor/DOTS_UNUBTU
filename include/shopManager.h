/**
    @author

    @brief

*/

#ifndef SHOPMANAGER_H
#define SHOPMANAGER_H
// User Defined
#include "inventory.h"

class shopManager
{
  public:
    /**
      @brief
      @param[in]
    */
    shopManager(int level);
    /**
      @brief
    */
    shopManager();
    ~shopManager();
    /**
      @brief
      @param[out]
    */
    inventory* getInventory();
    /**
      @brief
      @param[out]
    */
    int getGold();
    /**
      @brief
    */
    void setGold();
  private:
    int gold;
    inventory* sinventory;
};

#endif // SHOPMANAGER_H
