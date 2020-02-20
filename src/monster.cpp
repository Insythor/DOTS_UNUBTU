#include "monster.h"

monster::monster(std::string tName, std::string tRace, int tMaxHP, std::vector<int> tMStats, int l)
{

    level = l;
    if (level % 5 == 0)
        isBoss = true;
    else
        isBoss = false;

    name = tName;
    race = tRace;
    maxHealth = tMaxHP;
    currentHealth = maxHealth;
    mainStats = tMStats;
    level = l;


    generateMonster();
}

monster::~monster()
{
  //dtor
}

void monster::generateMonster()
{
    // 1 = 20

    // 2 = 50

    // 3 = 125

    // 4 = 200

    // 5 = 400

    // 6 = 550
}