/**
    @author Tyler Justinen-Teite

    @brief 

*/

#ifndef MONSTER_H
#define MONSTER_H
// Inherited Class
#include <baseCharacter.h>


class monster : public baseCharacter
{
  public:
    monster(std::string tName, std::string tRace, int tMaxHP, std::vector<int> tmMStats, int l);
    ~monster();

    friend std::ostream& operator << (std::ostream& out, monster& toRender);

  private:
    // ERROR: If the level % 5 == 0 
      // Should Be if the current room % 5 == 0
    bool isBoss;
    
    /**
        @brief level up the monster (if applicable)
               give the monster an ability
               create a weapon for the monster
               update stat bonuses
               give the monster gold
    */
    void initMonster();
};

#endif // MONSTER_H
