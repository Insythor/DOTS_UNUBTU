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
    // [0] = monster : [1] = player
    baseCharacter** fightOrder;
    // Because player is always in fightOrder[1], when it is the players turn, 
    // we get the 1st (true) index
    bool playersTurn;

    std::string selectAction(int type, int subType);
    std::string endFight();
    std::string monsterAction();

    bool checkCombatDone();

    // [0] switch, [1] type, [2] subType
    std::vector<int> formatCommand(std::string command);
};

#endif // COMBATMANAGER_H
