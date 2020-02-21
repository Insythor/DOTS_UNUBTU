#include "monster.h"

monster::monster(std::string tName, std::string tRace, int tMaxHP, std::vector<int> tMStats, int l)
{

    level = l;
    if (level % 6 == 0)
        isBoss = true;
    else
        isBoss = false;

    name = tName;
    race = tRace;
    maxHealth = tMaxHP;
    currentHealth = maxHealth;
    mainStats = tMStats;
    checkStatBonuses();
    level = l;


    initMonster();
}

monster::~monster()
{
  //dtor
}

void monster::initMonster()
{
    int tMainStat = 0;
    int tMainStatIndex;
 

    for (int i = 0; i < level; i++)
    {
        if (mainStats[i] > tMainStat)
        {
            tMainStat = mainStats[i];
            tMainStatIndex = i;
        }
        if (i == 2 && mainStats[i] > tMainStat && mainStats[0] < mainStats[i])
        {
            tMainStat = mainStats[i];
            tMainStatIndex = i;
        }
    }
    std::cout << "monster main stat: " << tMainStatIndex << std::endl;
}