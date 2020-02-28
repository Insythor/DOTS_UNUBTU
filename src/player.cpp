#include "player.h"


player::player()
{
    name = "temp";
    race = "n/a";

    maxHealth = 0;
    currentHealth = maxHealth;

    // equippedWeapon = nullptr;

    currentExperience = 0;
    maxExperience = 100;

    level = 0;
    gold = 0;

    checkStatBonuses();
}

player::~player()
{
  //dtor
}


player::player(std::string tName, std::string tRace, int tMaxHP,
              std::vector<int> tStat)
{
  name = tName;
  race = tRace;

  maxHealth = tMaxHP;
  currentHealth = maxHealth;

  mainStats = tStat;
  checkStatBonuses();

  currentExperience = 0;
  maxExperience = 100;

  level = 0;
  gold = 0;

}

player* player::getSelf() { return this; }

// Print 
std::ostream& operator << (std::ostream& out, player& toRender)
{
    // Figure out the widths for each section of the player output stream
    int nameSpacer = 20 - toRender.getName().length();
    int raceSpacer = 20 - toRender.getRace().length();
    int levelSpacer = 3 - std::to_string(toRender.getLevel()).length();
    int currentXpSpacer = std::to_string(toRender.getExperience()[0]).length();
    int maxXpScacer = 5 + std::to_string(toRender.getExperience()[1]).length();
    int hpSpacer = 4 - std::to_string(toRender.getCurrentHealth()).length();
    int goldSpacer = 10 - std::to_string(toRender.getGold()).length();
    int weaponSpacer = 3 + toRender.getWeapon()->getName().length();
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
    // WILL BE CLEANED UP! Just had some weird bugs that needed to be tracked down
    // Print out the: Name, Race, Level, currentHP, maxHP, gold, weapon of the current player
    out << "\n" <<
        toRender.getName() << std::setw(nameSpacer) << toRender.getRace() << std::setw(raceSpacer);
    out << "HP: " << std::setw(hpSpacer) << toRender.getCurrentHealth() << " / " << toRender.getMaxHealth();
    out << "Level: " << toRender.getLevel() << std::setw(levelSpacer);
        out << "(" << toRender.getExperience()[0] << std::setw(currentXpSpacer) << " / ";
     out   << toRender.getExperience()[1] << ")" << std::setw(maxXpScacer);
        out << "HP: " << std::setw(hpSpacer) << toRender.getCurrentHealth() << " / " << toRender.getMaxHealth();
        out << std::setw(goldSpacer) << "Gold: " << toRender.getGold();
        out << std::setw(weaponSpacer) << toRender.getWeapon()->getName() << std::setw(3);
        out << toRender.getWeapon()->getDiceRolls() << "d" << toRender.getWeapon()->getDiceSize();
        out << dmgBonusSign << dmgBonus;
        out << "\n" << std::setfill('.');
        // Print out the players stats
 out       << "0.Str" << std::setw(5) << toRender.getStats()[0] << strBonus
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

void player::swapAbilities()
{

}

void player::addExperience(int toAdd)
{
    currentExperience += toAdd;

    if (currentExperience >= maxExperience)
        levelUp();
}


void player::levelUp()
{
    // temp variables used to for input
    int statIn;
    int statAmountIn;
    std::string command;
    // Stats the user has chosen to upgrade
    std::vector<int> tempStats(4);
    // how many stat points the player can add to their hero
    int availablePoints;
    // When you create your character you get more points
    if (level == 0)
        availablePoints = 6;
    else
    {
        // If the player has more experience than the max experience, carry over that amount,
        // else set the current experience to 0
        if (currentExperience > maxExperience)
            currentExperience -= maxExperience;
        else
            currentExperience = 0;

        // Don't increase the max experience required for level 1 as it is set by default in the constructor
        maxExperience += ((level + 1) - 1 + (300 * pow(2, ((level + 1) - 1) / 7))) / 4;
        availablePoints = 2;
    }
    // stored amout of available points incase the user does not want to commit their changes
    int backupAvailPoints = availablePoints;
    // ding!
    level += 1;

    currentExperience -= maxExperience;
    // Increase the experience needed for the next level by %150 of the current max experience
    maxExperience += maxExperience / 2;

    std::cout << (*this);


    std::cout <<
        "Place your stat points by choosing a stat, then typing the amount of points to add."
        << "\n i.e. 0 1  will add one ability point to your heros strength.\n"
        << "Available points: " << availablePoints << "\n";
    // Print out the current player before they level up so they have a reference
    std::cout << (*this);

    while (availablePoints > 0)
    {
        std::cin >> statIn >> statAmountIn;

        if (statIn < 3 && availablePoints - statAmountIn >= 0)
        {
            // Add the stats input by the player to the tempStats vector
            tempStats[statIn] += statAmountIn;
            // reduce the available points by the amount of points the player just spent
            availablePoints -= statAmountIn;
            // Print what the user just did so they know whats up
            switch (statIn)
            {
            case 0:
                std::cout <<
                    statAmountIn << " point(s) added to Strength. " << availablePoints << " points remaining."
                    << std::endl;
                break;

            case 1:
                std::cout <<
                    statAmountIn << " point(s) added to Dexterity. " << availablePoints << " points remaining."
                    << std::endl;
                break;

            case 2:
                std::cout <<
                    statAmountIn << " point(s) added to Intellect. " << availablePoints << " points remaining."
                    << std::endl;
                break;
            }
        }
        // Tell the user if they entered an invalid command / stat amount
        else
        {
            std::cout << "Invalid stat type or amount" << std::endl;
        }
        // If all the available points are spent, show the user what they have selected so far
        if (availablePoints == 0)
        {
            std::cout << "Would you like to commit?\n"
                << "Strength  + " << tempStats[0] << "\n"
                << "Dexterity + " << tempStats[1] << "\n"
                << "Intellect + " << tempStats[2] << "\n"
                << std::endl;

            std::cin >> command;
           // add the chosen stats from the player to the main stats vector
            // break for the while loop
            if (command == "yes" || command == "Yes" || command == "y")
            {
                addToStats(tempStats);
                // Positive reinforcement is a key value of the Spire...
                std::cout << "Good Choice Adventurer!" << std::endl;
                break;
            }
                  
            // reset the available points and tempStats vector which essentially restarts the loop
            else if (command == "no" || command == "No" || command == "n")
            {
                availablePoints = backupAvailPoints;
                tempStats.clear();
                tempStats.resize(4);

                std::cout <<
                    "Place your stat points by choosing a stat, then typing the amount of points to add."
                    << "\n i.e. 0 1  will add one ability point to your heros strength.\n"
                    << "Available points: " << availablePoints << "\n";
            }
        }
    }


    // Add 10% of the players current hp an 50% of the players strength to their maxHP
    // Arbitrary and needs to be replaced with actual value
    maxHealth += (maxHealth * 0.1) + (mainStats[0] * 0.5);
    // Give the player back full HP when they level up because we're not savages ;P
    currentHealth = maxHealth;

    // Print out the player so the user can see their changes
    std::cout << (*this);

    // Check if the player has enough experience to levelup again
    addExperience(0);
}


void player::addToStats(std::vector<int>toAdd)
{
    for(unsigned int i = 0; i < mainStats.size(); i++)
        mainStats[i] += toAdd[i];

    checkStatBonuses();
}



void player::useConsumable(unsigned int index)
{
    std::vector<consumable*> tempC = cInventory->removeConsumables(index, 1);
    if(tempC.size() > 0)
    {
        int stat = tempC.front()->getStatToAdd();
        int amount = tempC.front()->getStatValue();
        if(tempC.front()->getIsPerminant())
        {
            switch(stat)
            {
            case 1: mainStats[0] += amount;
                    break;
            case 2: mainStats[1] += amount;
                    break;
            case 3: mainStats[2] += amount;
                    break;
            case 4: mainStats[3] += amount;
                    break;
            case 5: maxHealth += amount;
                    currentHealth += amount;
                    break;
            }
        }
        else
        {
            switch(stat)
            {
            case 1: statusEffect[0] += amount;
                    break;
            case 2: statusEffect[1] += amount;
                    break;
            case 3: statusEffect[2] += amount;
                    break;
            case 4: statusEffect[3] += amount;
                    break;
            }
        }
        delete tempC.front();
        tempC.clear();
    }
    // Check if updating the players stats changes their damage
    updateDamagePower();
}

std::vector<int> player::getExperience()
{
    std::vector<int> temp;

    temp.push_back(currentExperience);
    temp.push_back(maxExperience);

    return temp;
}

void player::save()
{
    /*
        player:
            Name
            Race
            Level
            currentHealth
            Max Health
            current HP
            maxHP
            gold
            damagePower
        
        weapon:
            dice Size
            dice rolls
            name
            statRequirements
        
    
   
    */
}