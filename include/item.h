#ifndef ITEM_H
#define ITEM_H

#include <string>

class item
{
  public:
    item();
    virtual ~item();

    std::string getName();
    int getCost();
    int getSellValue();

  protected:
    std::string name;
    int cost;
    int sellValue;
};

#endif // ITEM_H
