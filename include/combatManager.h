#ifndef COMBATMANAGER_H
#define COMBATMANAGER_H

#include "monster.h"
#include "player.h"

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>

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

    // [0] switch, [1] type, [2] subType
    std::vector<int> formatCommand(std::string command);
};

#endif // COMBATMANAGER_H
