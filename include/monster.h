#ifndef MONSTER_H
#define MONSTER_H

#include <baseCharacter.h>


class monster : public baseCharacter
{
  public:
    monster(std::string tName, std::string tRace, int tMaxHP, std::vector<int> tmMStats, int l);
    ~monster();

  private:

    bool isBoss;
    int level;

    void generateMonster();

    
};

#endif // MONSTER_H
