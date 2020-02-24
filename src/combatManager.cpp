#include "combatManager.h"

combatManager::combatManager(player* p, monster* m)
{
    fightOrder = new baseCharacter* [2];

    if ((*p).getStats()[3] > (*m).getStats()[3])
    {
        fightOrder[0] = p;
        fightOrder[1] = m;

        playersTurn = true;
    }
    else
    {
        fightOrder[0] = m;
        fightOrder[1] = p;

        playersTurn = false;
    }
}

combatManager::~combatManager()
{

}

void combatManager::startFight()
{
    std::string playerFirst;
    if (playersTurn)
    {
        playerFirst = "Congratulations ";
        playerFirst += (*fightOrder)[0].getName() + "!!! Your speed was higher than the "
                    + (*fightOrder)[1].getName();

    }

    std::cout << "\nCOMBAT HAS BEGUN!!!\n";
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

bool combatManager::checkCombatDone()
{
    if((*fightOrder)[0].isDead() || (*fightOrder)[1].isDead())
        return true;
    else return false;
}