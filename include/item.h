#ifndef ITEM_H
#define ITEM_H

#include <string>

class item
{
  public:
    item();
    virtual ~item();

    std::string getName();
    std::string getDescription();

    int getCost();
    int getSellValue();

  private:
    std::string name;
    std::string description;

    int cost;
    int sellValue;



};

#endif // ITEM_H
