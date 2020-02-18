#include "combatManager.h"

combatManager::combatManager(player* p, monster* m)
{
  fightOrder[0] = p;
  fightOrder [1] = m;
}

combatManager::~combatManager()
{

}

void combatManager::startFight()
{

}

std::string combatManager::selectAction(int type, int subType)
{
  type *= -1;
  subType *= -1;
  return "n\a";
}

std::string combatManager::endFight()
{
  return "n\a";
}

std::string combatManager::monsterAction()
{
  return "n\a";
}
