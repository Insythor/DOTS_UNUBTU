#ifndef MONSTER_H
#define MONSTER_H

#include <baseCharacter.h>


class monster : public baseCharacter
{
  public:
    monster(std::string tName, std::string tRace, int tMaxHP, std::vector<int> tmMStats, int l);
    ~monster();

    friend std::ostream& operator << (std::ostream& out, monster& toRender);

  private:

    bool isBoss;
    

    void initMonster();

    
};

#endif // MONSTER_H
