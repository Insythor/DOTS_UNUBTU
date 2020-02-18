#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include <item.h>
#include "player.h"
#include "inventory.h"
#include "string"
class consumable : public item
{
  public:
    consumable(int tid);
    virtual ~consumable();

    int getID();
    void use(player* p);


  private:
    int id;
    int statToAdd;
    int statValue;
    bool isPerminant;
};

#endif // CONSUMABLE_H
