#ifndef COMBATMANAGER_H
#define COMBATMANAGER_H

#include "monster.h"

#include "baseCharacter.h"


#include <string>

class combatManager
{
  public:
    combatManager(monster* m);
    ~combatManager();

  void startFight();


  private:
    baseCharacter* fightOrder;

    std::string selectAction(int type, int subType);
    std::string endFight();
    std::string monsterAction();

};

#endif // COMBATMANAGER_H
