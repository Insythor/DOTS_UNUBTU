#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include <item.h>
#include "player.h"
#include "string"
class consumable : public item
{
  public:
    consumable(int level, int type);
    virtual ~consumable();

    int getID();
    void use(player &p);
    std::string viewConsumable();


  private:
    int id;
    int statToAdd;
    int statValue;
    bool isPerminant;
};

#endif // CONSUMABLE_H
