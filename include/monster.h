#ifndef MONSTER_H
#define MONSTER_H

#include <baseCharacter.h>


class monster : public baseCharacter
{
  public:
    monster();
    virtual ~monster();

  private:
    bool isBoss;

};

#endif // MONSTER_H