#include "player.h"
<<<<<<< HEAD

player::player()
{
    name = "temp";
    race = "n/a";

    maxHealth = 0;
    currentHealth = maxHealth;

    equippedWeapon = nullptr;

    currentExperience = 0;
    maxExperience = 100;

    level = 0;
    gold = 0;
}

player::~player()
{
  //dtor
}

=======
>>>>>>> 2273b378aa816a2b7feccc5c0cbc62879c97e27d
player::player(std::string tName, std::string tRace, int tMaxHP,
              std::vector<int> tStat)
{
  name = tName;
  race = tRace;

  maxHealth = tMaxHP;
  currentHealth = maxHealth;

  mainStats = tStat;

<<<<<<< HEAD
  currentExperience = 0;
  maxExperience = 100;

  level = 0;
  gold = 0;

}

std::ostream& operator << (std::ostream& out, player& toRender)
{
    int nameSpacer = 15 - toRender.getName().length();
    int raceSpacer = 13 - toRender.getRace().length();
    int levelSpacer = 8 - std::to_string(toRender.getLevel()).length();
    int hpSpacer = 4 - std::to_string(toRender.getCurrentHealth()).length();
    int goldSpacer = 10 - std::to_string(toRender.getGold()).length();
    int weaponSpacer = 3 + toRender.getWeapon()->getName().length();

    out <<

        toRender.getName() << std::setw(nameSpacer) << toRender.getRace() << std::setw(raceSpacer)
        << "Level: " << toRender.getLevel() << std::setw(levelSpacer)
        << "HP: " << std::setw(hpSpacer) << toRender.getCurrentHealth() << " / " << toRender.getMaxHealth()
        << std::setw(goldSpacer) << "Gold: " << toRender.getGold()
        << std::setw(weaponSpacer) << toRender.getWeapon()->getName() << std::setw(3)
        << toRender.getWeapon()->getDiceRolls() << "d" << toRender.getWeapon()->getDiceSize()
        << "\n" << std::setfill('.')

        << "0.Str" << std::setw(5) << toRender.getStats()[0] << "\n"
        << "1.Dex" << std::setw(5) << toRender.getStats()[1] << "\n"
        << "2.Int" << std::setw(5) << toRender.getStats()[2] << "\n"
        << "3.Spd" << std::setw(5) << toRender.getStats()[3]
        << std::setfill(' ')

    << std::endl;

   

    return out;
=======
  equippedWeapon = new weapon;
}

player::~player()
{
  //dtor
>>>>>>> 2273b378aa816a2b7feccc5c0cbc62879c97e27d
}



void player::swapAbilities()
{

}

void player::addExperience(int toAdd)
{
<<<<<<< HEAD
    currentExperience += toAdd;
    if (currentExperience >= maxExperience)
        levelUp();
=======
  currentExperience += toAdd;
  checkForLevelUp();
>>>>>>> 2273b378aa816a2b7feccc5c0cbc62879c97e27d
}

void player::checkForLevelUp()
{
 if(currentExperience >= maxExperience)
  {
      int difference = currentExperience - maxExperience;
      leveUp();
      currentExperience = difference;
      checkForLevelUp(); //recursion for if you gain more than one level
  }
}

<<<<<<< HEAD
void player::levelUp()
{
    int statIn;
    int statAmountIn;
    std::vector<int> tempStats(3);

    int availablePoints;
    if (level == 0)
        availablePoints = 6;
    else
        availablePoints = 2;

    level += 1;
    // IF the player has more experience than the max experience, carry over that amount,
    // else set the current experience to 0
    if (currentExperience > maxExperience)
        currentExperience -= maxExperience;
    else
        currentExperience = 0;
    // Increase the experience needed for the next level by %150 of the current max experience
    maxExperience += maxExperience/2;

    std::cout << (*this);

    std::cout <<
        "Place your stat points by choosing a stat, then typing the amount of points to add."
        << "\n i.e. 0 1  will add one ability point to your heros strength.\n"
        << "Available points: " << availablePoints << "\n";
    
    while (availablePoints > 0)
    {
        std::cin >> statIn >> statAmountIn;

        if (statIn < 3 && availablePoints - statAmountIn >= 0)
        {
           
            tempStats[statIn] += statAmountIn;
            availablePoints -= statAmountIn;

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
        else
        {
            std::cout << "Invalid stat type" << std::endl;
        }
        if (availablePoints == 0)
        {
            std::cout << "Would you like to commit\n"
                << "Strength  + " << tempStats[0] << "\n"
                << "Dexterity + " << tempStats[1] << "\n"
                << "Intellect + " << tempStats[2] << "\n"
            << std::endl;
                
        }
    }


=======
void player::leveUp()
{
    level++;
    //osrs multiplier;
    maxExperience += ((level + 1) - 1 + (300 * pow(2, ((level + 1) - 1) / 7))) / 4;
>>>>>>> 2273b378aa816a2b7feccc5c0cbc62879c97e27d
}

void player::addToStats(std::vector<int>toAdd)
{
    for(unsigned int i = 0; i < mainStats.size(); i++)
        mainStats[i] += toAdd[i];
    checkStatBonuses();
}

void player::applyStatusEffect(std::vector<int>toApply)
{
  toApply.clear();
}

void player::spawnWeapon(int level, std::vector<std::string>* weaponNames)
{
    // If there is a weapon already equipped
    //if (equippedWeapon != nullptr)
    //    delete equippedWeapon;
    if(this != nullptr)
        equippedWeapon = new weapon(level, weaponNames);
}
<<<<<<< HEAD

=======
void player::useConsumable(unsigned int index)
{
    std::vector<consumable*> tempC = cInventory->removeConsumable(index, 1);
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
}
>>>>>>> 2273b378aa816a2b7feccc5c0cbc62879c97e27d
