#ifndef COMSUMABLE_H
#define COMSUMABLE_H

#include <item.h>
#include "player.h"
#include "string"
class consumable : public item
{
  public:
    consumable(int level, int type);
    ~consumable();
    void use(player* p);

  private:
    int id;
    int statToAdd;
    int statValue;
    bool isPerminant;
    std::string description;
};

#endif // COMSUMABLE_H
