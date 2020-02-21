#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "item.h"

#include <string>
#include <iostream>

class consumable : public item
{
  public:
    consumable();
    consumable(int cid);
    ~consumable();
    friend std::ostream& operator << (std::ostream& out, consumable &toRender);
    int getID();
    int getStatToAdd();
    int getStatValue();
    bool getIsPerminant();
  private:
    int id;
    int statToAdd;
    int statValue;
    bool isPerminant;
};

#endif // CONSUMABLE_H
