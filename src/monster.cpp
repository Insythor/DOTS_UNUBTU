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

    initMonster();
}

monster::~monster()
{
  //dtor
}

std::ostream& operator << (std::ostream& out, monster& toRender)
{
    int nameSpacer = 20 - toRender.getName().length();
    int raceSpacer = 10 - toRender.getRace().length();
    int hpSpacer = 4 - std::to_string(toRender.getCurrentHealth()).length();

    out <<

        toRender.getName() << std::setw(nameSpacer) << toRender.getRace() << std::setw(raceSpacer)
        << "HP: " << std::setw(hpSpacer) << toRender.getCurrentHealth() << " / " << toRender.getMaxHealth()
        
        << "\n" << std::setfill('.')
        // Print out the players stats
        << "0.Str" << std::setw(5) << toRender.getStats()[0] << "\n"

        << "1.Dex" << std::setw(5) << toRender.getStats()[1] << "\n"

        << "2.Int" << std::setw(5) << toRender.getStats()[2] << "\n"

        << "3.Spd" << std::setw(5) << toRender.getStats()[3]
        // reset the fill back to empty space
        << std::setfill(' ') << "\n"


    << std::endl;


    return out;
}

void monster::initMonster()
{
    int tMainStat = 0;
    int tMainStatIndex;
 
    // Check if str, dex, or int is highest
    for (unsigned int i = 0; i < statBonuses.size(); i++)
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
    // Give the monster +6 to their main stat for level 0
    mainStats[tMainStatIndex] += 6;

    dice lvlDice;


    for (int i = 0; i < level; i++)
    {
        int tIndex = lvlDice.roll();
        std::cout << tIndex << std::endl;
        if (tIndex >= 3)
        {
            std::cout << "adding to main stat" << std::endl;
            mainStats[tMainStatIndex] += 2;
        }
        else if (tIndex == 1)
        {
            if (tMainStatIndex + 1 > 3)
            {
                mainStats[tMainStatIndex + 1] += 2;
            }
            else
            {
                mainStats[tMainStatIndex - 1] += 2;
            }
        }
        else if (tIndex == 2)
        {
            if (tMainStatIndex - 1 < 0)
                mainStats[tMainStatIndex - 1] += 2;
            
        }

    }
    checkStatBonuses();

    std::cout << "monster main stat: " << tMainStatIndex << std::endl;
}