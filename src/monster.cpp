#include "monster.h"

monster::monster(std::string tName, std::string tRace, int tMaxHP, 
                                        std::vector<int> tMStats, int l)
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
    
    equippedWeapon = nullptr;

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
    int raceSpacer = 15 - toRender.getRace().length();
    int levelSpacer = 5;
    int hpSpacer = 4 - std::to_string(toRender.getCurrentHealth()).length();
    std::string strBonus;
    std::string dexBonus;
    std::string intBonus;
    // Formatting variables for the damage bonus the player recieves
    // from using their current weapon based on their stats
    int dmgBonus = abs(toRender.getDamagePower());
    std::string dmgBonusSign;
    // Change the operation after the weapon damage to +/- based on the players stats
    if (toRender.getDamagePower() >= 0)
        dmgBonusSign = " + ";
    else
        dmgBonusSign = " - ";

    if (toRender.getStatBonuses()[0] >= 0)
        strBonus = " + ";
    else
        strBonus = " - ";

    if (toRender.getStatBonuses()[1] >= 0)
        dexBonus = " + ";
    else
        dexBonus = " - ";

    if (toRender.getStatBonuses()[2] >= 0)
        intBonus = " + ";
    else
        intBonus = " - ";

    out <<

        toRender.getName() << std::setw(nameSpacer) << toRender.getRace() << std::setw(raceSpacer)
        << "Level: " << toRender.getLevel() << std::setw(levelSpacer)
        << "HP: " << std::setw(hpSpacer) << toRender.getCurrentHealth() << " / "
                                         << toRender.getMaxHealth()
        << "\n" << std::setfill('.')
        // Print out the players stats
        << "0.Str" << std::setw(5) << toRender.getStats()[0] << strBonus 
                         << abs(toRender.getStatBonuses()[0]) << "\n"
        << "1.Dex" << std::setw(5) << toRender.getStats()[1] << dexBonus
                         << abs(toRender.getStatBonuses()[1]) << "\n"
        << "2.Int" << std::setw(5) << toRender.getStats()[2] << intBonus
                         << abs(toRender.getStatBonuses()[2]) << "\n"
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
        if (i == 2 && mainStats[i] > tMainStat&& mainStats[0] < mainStats[i])
        {
            tMainStat = mainStats[i];
            tMainStatIndex = i;
        }
    }

    dice lvlDice;

    // Balancing comes into play here because the player gets 4 extra points at level 0
    // And the monsters points are all random
    for (int i = 0; i < level; i++)
    {
        int tIndex = lvlDice.roll();
        // Print out the dice roll for debugging
        // std::cout << tIndex << std::endl;
        // Roll 5 or 6, gain +2 to the main stat
        if (tIndex >= 5)
            mainStats[tMainStatIndex] += 2;
        // Roll 3 or 4, gain +1 to main stat, and + 1 to a random stat
        else if (tIndex >= 3)
        {
            mainStats[tMainStatIndex] += 1;
            mainStats[lvlDice.roll() % 3] += 1;
        }
        // Roll 2, gain 2 random stats
        else if (tIndex == 2)
        {
            mainStats[lvlDice.roll() % 3] += 1;
            mainStats[lvlDice.roll() % 3] += 1;
        }
        // Roll 1 gain +2 random stats, neither can be the monsters main stat
        // Ciritcal fail
        else
        {
            int availablePoints = 2;

            while (availablePoints != 0)
            {
                int rIndex = lvlDice.roll() % 3;
                if (rIndex != tMainStatIndex)
                {
                    mainStats[rIndex] += 1;
                    availablePoints -= 1;
                }
            }
        }
        // Add 10% of the monster current hp an 50% of the monster strength to their maxHP
        // Arbitrary and needs to be replaced with actual value
        maxHealth += (maxHealth * 0.1) + (mainStats[0] * 0.5);
        currentHealth = maxHealth;
    }
    checkStatBonuses();

    setGold(dice(level * 10).roll());
}