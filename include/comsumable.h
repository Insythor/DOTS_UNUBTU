#ifndef COMSUMABLE_H
#define COMSUMABLE_H

#include <item.h>
#include "player.h"

class comsumable : public item
{
  public:
    comsumable();
    virtual ~comsumable();

    void use(player &p);

  private:
    int statToAdd;
    int statValue;

    bool isPerminant;

};

#endif // COMSUMABLE_H
