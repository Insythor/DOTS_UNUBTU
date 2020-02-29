#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "item.h"

#include <vector>

#include <iostream>

class consumable : public item
{
  public:
    consumable();
    consumable(int cid);
    ~consumable();
    friend std::ostream& operator << (std::ostream& out, consumable &toRender);
    int getID();
    /**
        @brief return the stat to add, and how much is to be added
        @param[out] std::vector<int>[0] Stat to add
        @param[out] std::vector<int>[1] Quantity to add
    */
    std::vector<int> statsToAdd();
    bool getIsPerminant();
  private:
    int id;

    std::vector<int> stats;

    bool isPerminant;
};

#endif // CONSUMABLE_H
