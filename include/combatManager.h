#ifndef COMBATMANAGER_H
#define COMBATMANAGER_H

#include "monster.h"
#include "player.h"

#include <string>

class combatManager
{
  public:
    combatManager(player* p, monster* m);
    ~combatManager();

  void startFight();


  private:
    // Currently player is 0 and monster is 1
    baseCharacter** fightOrder;
    bool playersTurn;

    std::string selectAction(int type, int subType);
    std::string endFight();
    std::string monsterAction();

    bool checkCombatDone();
};

#endif // COMBATMANAGER_H
