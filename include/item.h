/**
    @author Tyler Justinen-Teite

    @brief Parent class of Weapon and Consumable.



*/

#ifndef ITEM_H
#define ITEM_H

// Containers
#include <string>

class item
{
  public:
    /**
      @brief
      @param[out]
    */
    item();
    virtual ~item();
    /**
      @brief
      @param[out]
    */
    std::string getName();
    /**
      @brief
      @param[out]
    */
    int getCost();
    /**
      @brief
      @param[out]
    */
    int getSellValue();

  protected:
    std::string name;
    int cost;
    int sellValue;
};

#endif // ITEM_H
