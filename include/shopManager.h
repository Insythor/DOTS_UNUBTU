/**
    @author

    @brief

*/

#ifndef SHOPMANAGER_H
#define SHOPMANAGER_H
// User Defined
#include "inventory.h"
#include "print.h"
#include "item.h"
#include "ability.h"
#include "player.h"

// I/O
#include <iostream>
#include <iomanip>

class shopManager
{
  public:
    /**
      @brief
      @param[in]
    */
    shopManager(int roomCount, player* customer);
    /**
      @brief
    */
    shopManager();
    ~shopManager();

  private:
    int gold;

    player* customer;
    inventory* sinventory;

    void startTransaction();

    int formatCommand(std::string command);
};

#endif // SHOPMANAGER_H
