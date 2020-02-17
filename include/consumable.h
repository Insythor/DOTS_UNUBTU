#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "item.h"
#include "player.h"
#include "string"
class consumable : public item
{
  public:
    consumable(int level, int type);
    virtual ~consumable();
    void use(player* p);
    int getID();
    std::string viewConsumable();
    std::string getDescription();
  private:
    int id;
    int statToAdd;
    int statValue;
    bool isPerminant;
    std::string description;
};

#endif // CONSUMABLE_H
