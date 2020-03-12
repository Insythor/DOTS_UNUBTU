#include "player.h"


player::player()
{
    name = "temp";
    race = "n/a";

    maxHealth = 0;
    currentHealth = maxHealth;

    currentExperience = 0;
    maxExperience = 100;

    statusEffect.resize(3, 0);
    checkStatBonuses();
}
// Essentially the default constructor for the player
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

  statusEffect.resize(3, 0);

}

player::~player()
{
    //dtor
}

// Print
std::ostream& operator << (std::ostream& out, player& toRender)
{
    // Figure out the widths for each section of the player output stream
    int nameSpacer = 17 - toRender.getName().length();
    int raceSpacer = 12 - toRender.getRace().length();
    int levelSpacer = 3 - std::to_string(toRender.getLevel()).length();
    int currentXpSpacer = std::to_string(toRender.getExperience()[0]).length();
    int maxXpScacer = 5 + std::to_string(toRender.getExperience()[1]).length();
    int hpSpacer = 4 - std::to_string(toRender.getCurrentHealth()).length();
    int goldSpacer = 10 - std::to_string(toRender.getGold()).length();
    std::string strBonus;
    std::string dexBonus;
    std::string intBonus;
    // Formatting variables for the damage bonus the player recieves
    // from using their current weapon based on their stats
    int dmgBonus = abs(toRender.getDamagePower());
    std::string dmgBonusSign;
    // Change the operation after the weapon damage to +/- based on their stats
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

    out << "\n" <<
        toRender.getName() << std::setw(nameSpacer) << toRender.getRace()
        << std::setw(raceSpacer)
        << "HP: " << std::setw(hpSpacer)
        << toRender.getCurrentHealth() << " / " << toRender.getMaxHealth()
        << std::setw(9)
        << "Level: " << toRender.getLevel() << std::setw(levelSpacer)
        << "(" << toRender.getExperience()[0] << std::setw(currentXpSpacer)
        << " / " << toRender.getExperience()[1] << ")" << std::setw(maxXpScacer)
        << std::setw(goldSpacer) << "Gold: " << toRender.getGold()

        << "\n" << std::setfill('.')
        /** Stats */
        << "Str" << std::setw(5) << toRender.getStats()[0] << strBonus
                         << abs(toRender.getStatBonuses()[0]) << "\n"
        << "Dex" << std::setw(5) << toRender.getStats()[1] << dexBonus
                         << abs(toRender.getStatBonuses()[1]) << "\n"
        << "Int" << std::setw(5) << toRender.getStats()[2] << intBonus
                         << abs(toRender.getStatBonuses()[2]) << "\n"
        << "Spd" << std::setw(5) << toRender.getStats()[3]
        // reset the fill back to empty space
        << std::setfill(' ') << "\n"

        /** Weapon */
        << "Equipped Weapon: "
        << toRender.getWeapon()->getName() << std::setw(3)
        << toRender.getWeapon()->getDiceRolls() << "d"
        << toRender.getWeapon()->getDiceSize()
        << dmgBonusSign << dmgBonus << "\n";


        if(!toRender.getActiveAbilities().empty())
        {
          int index = 0;
          out << "Active Abilities:\n";
          for(auto i : toRender.getActiveAbilities())
            out
            << std::setw(4) << ++index
            << std::setw(10 + i->getName().length() / 2)
            << *i << std::endl;
        }

    out << std::endl;
    return out;
}

void player::swapAbilities()
{

  int index = 0;
  // Last index of the active abilities, because active use a shared index
  int lastActiveIndex = 0;

  if(!activeAbilities.empty())
  {
    std::cout
        << "\n                    Active Abilities\n"
        << "---------------------------------------------------------\n";
    for(auto ab : activeAbilities)
        std::cout
        << std::setw(3) << ++index
        << std::setw(15 + ab->getName().length() / 2)
        << *ab << std::endl;
    if(index > 0)
      lastActiveIndex = index;
  }
  else
    std::cout << "Currently " + name + " has no active abilities." << std::endl;
  if(!cInventory->getAbilities().empty())
  {
    std::cout
        << "\n                    Stored Abilities\n"
        << "---------------------------------------------------------\n";

    for(auto ab : cInventory->getAbilities())
      std::cout
        << std::setw(3) << ++index
        <<std::setw(15 + ab->getName().length() / 2)
        << *ab
      << std::endl;
  }
  else
    std::cout << "Currently " + name + " has no stored abilities." << std::endl;

    std::cout
        << "Which two abilities would you like to swap? [int] [int]\n"
        << "Or would you like to 'add' or 'remove' an active ability?"
        << " [string][int]\n"
      << std::endl;

    std::string rawInput;
    std::string parsed;

    while(rawInput.empty() || rawInput[0] == '\n')
      getline(std::cin, rawInput);

    std::stringstream ss(rawInput);
    std::vector<int> input;

    while(getline(ss, parsed, ' '))
    {
      if(isdigit(parsed[0]))
        input.push_back(std::stoi(parsed));
      else if(parsed[0] == 'a')
        input.push_back(100);
      else if(parsed[0] == 'r')
        input.push_back(101);
    }
    // Decrement the user input so that it starts counting at 0
    for(unsigned int i = 0; i < input.size(); i++)
    {
      input[i]--;
    }
    // Decrement the index so that it starts counting at 0
    index--;

    // Temp pointer to swap abilities
    ability* tempAb = nullptr;

    switch(input[0])
    {
      // add an abilitiy to the active abilities from the stored abilities
      case 99:
          if(
             // get the stat amount required
             cInventory->getAbilities()[input[1] - lastActiveIndex]
                  ->getStatRequirements()[1] <=
             // At the players main stats of the required stat
                mainStats[cInventory->getAbilities()[input[1] - lastActiveIndex]
                  ->getStatRequirements()[0]]
             // check the player is at the required level
             && cInventory->getAbilities()[input[1] - lastActiveIndex]
                ->getStatRequirements()[2] <= level )
          {
            if(activeAbilities.size() >= 2)
            {
              cInventory->addAbility(activeAbilities.back());
              activeAbilities.pop_back();
            activeAbilities.push_back(cInventory->removeAbility
                                      (input[1] - lastActiveIndex));
          }
          else if(!activeAbilities.empty())
            activeAbilities.push_back(cInventory->removeAbility
                                      (input[1] - lastActiveIndex));
           else
            activeAbilities.push_back(cInventory->removeAbility
                                      (input[1]));
          }

          else
            std::cout <<
                name + " does not meet the stat requirements for that ability"
            << std::endl;
        break;
    // Remove an ability from the active abilities
        // and place it in the stored abilities
      case 100:
          if(input[1] <= lastActiveIndex && input[1] >= 0)
          {
            cInventory->addAbility(activeAbilities[input[1]]);
            activeAbilities.erase(activeAbilities.begin() + input[1]);
          }
          else
            std::cout << "Invalid Active Ability Index" << std::endl;
        break;

      default:
      // If the first ability is an active ability
      if(input[0] < lastActiveIndex)
      {
        // Store ability 1 to swap
        tempAb = activeAbilities[input[0]];
        // If the second ability is an active ability
        if(input[1] < lastActiveIndex)
        {
          activeAbilities[input[0]] = activeAbilities[input[1]];
          activeAbilities[input[1]] = tempAb;
        }
        // If the second ability is a stored ability
        else if(input[1] <= index)
        {
          // input[1] - lastActiveIndex so that it matches with the inventory
          activeAbilities[input[0]] =
                cInventory->removeAbility(input[1] - lastActiveIndex);
          // Add the swapped ability back into the inventory
          cInventory->addAbility(tempAb);
        }
      }
      // If the first ability is a stored ability
      else
      {
        // Get the ability from the inventory
        tempAb = cInventory->removeAbility(input[0] - lastActiveIndex);
        if(input[1] <= lastActiveIndex)
        {
          cInventory->addAbility(activeAbilities[input[1]]);
          activeAbilities[input[1]] = tempAb;
        }
        else if(input[1] <= index)
        {
          std::cout
           << "cannot swap abilities in inventory currently" << std::endl;
        }
      }
      break;
    }
}

void player::swapWeapon()
{
  int index = 1;
  std::cout
      << "| Index |             Name              |  Stat Req | "
      << "Lvl Req | Damage | Price |\n"
      << "|   " << index << "   " << *equippedWeapon
   << std::endl;

  if (cInventory->getWeapons().size() > 0)
  {
    std::cout
     << "\nStored Weapons\n"
      << "| Index |             Name              |  Stat Req | "
      << "Lvl Req | Damage | Price |\n"

      << std::setw(80) << std::setfill('-') << std::endl;
    for (weapon* i : cInventory->getWeapons())
    {
      index++;
      std::cout << "|" << index << *i << std::endl;
    }
  }

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
      // So we can level up the player without giving them negative experience
      if(currentExperience - maxExperience >= 0)
        currentExperience -= maxExperience;
      else
        currentExperience = 0;

        // Don't increase the max experience required for level 1 as it is set
        // by default in the constructor
        maxExperience += ((level + 1) - 1 + (300 *
                                          pow(2, ((level + 1) - 1) / 7))) / 4;
        availablePoints = 2;
    }
    // stored amount of available points incase the user does not want
    //  to commit their changes
    int backupAvailPoints = availablePoints;
    // ding!
    level += 1;

    // Print out the current player before they level up for reference
    std::cout << (*this);

    std::cout
        << "First choose the stat you wish to increase[int]\n"
        << "then type the amount of points to add [int]\n"
        << "For every 2 points about 10 in any stat, you will gain a +1 bonus"
        << "\ni.e. 0 will choose strength and then type 1 to add one point "
        << "to strength.\n\n"
        << "Available points: " << availablePoints << std::endl;

    print::setCursor(true);
    // While the player still has points to spend on additional stat upgrades
    while (availablePoints > 0)
    {
      bool done = false;
      std::string In;
      std::string AmountIn;
      while(!done)
      {
         std::cout.flush() << "Choose stat: ";
         std::cin >> In;
         if(print::is_number(In) && (In == "0" || In == "1" || In == "2"))
         {
           statIn = std::stoi(In);
           while(!done)
           {
             std::cout << "Choose amount: ";
             std::cin >> AmountIn;
             std::cout << std::endl;
             if(print::is_number(AmountIn))
             {
               statAmountIn = std::stoi(AmountIn);
               done = true;
             }
             else
             {
               std::cout << "Invalid stat amount" << std::endl;
             }
           }
         }
         else
          std::cout << "\nInvalid stat type" << std::endl;
      }
        // Check that the amount of stats input does not exceed the amount of available points
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
                std::cout
                    << statAmountIn << " point(s) added to Strength. "
                    << availablePoints << " points remaining."
                    << std::endl;
                break;

            case 1:
                std::cout
                    << statAmountIn << " point(s) added to Dexterity. "
                    << availablePoints << " points remaining."
                    << std::endl;
                break;

            case 2:
                std::cout
                    << statAmountIn << " point(s) added to Intellect. "
                    << availablePoints << " points remaining."
                    << std::endl;
                break;
            }
        }
        // Tell the user if they entered an invalid command / stat amount
        else
        {
            std::cout << "Invalid stat type or amount" << std::endl;
        }
        // If all the available points are spent, show the user what they
        // have selected so far
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

            // reset the available points and tempStats vector which
            // essentially restarts the loop
            else if (command == "no" || command == "No" || command == "n")
            {
                availablePoints = backupAvailPoints;
                tempStats.clear();
                tempStats.resize(4);

                std::cout <<
                    "Place your stat points by choosing a stat, then typing the"
                    " amount of points to add."
                    << "\ni.e. 0 1  will add one ability point to your "
                    << "heros strength.\n"
                    << "Available points: " << availablePoints << std::endl;
            }
        }
    }
    print::setCursor(false);
    // Add 10% of the players current hp an 50% of their strength to maxHP
    // Arbitrary and needs to be replaced with actual value
    maxHealth += (maxHealth * 0.1) + (mainStats[0] * 0.5);
    // Give the player back full HP when they level up because we're not savages
    currentHealth = maxHealth;

    // Print out the player so the user can see their changes
    std::cout << (*this);

    // Check if the player has enough experience to levelup again
    addExperience(0);
}

void player::addToStats(std::vector<int>toAdd)
{
    // For all the stats the player has, add the given stats
    for(unsigned int i = 0; i < mainStats.size(); i++)
        mainStats[i] += toAdd[i];
    // Check to see if the stats added change the players bonuses
    checkStatBonuses();
}

void player::applyStatusEffect(std::vector<int> toApply, bool apply)
{
    // This may need to be changed based off how we do atatus effects
    // Add the negative or positive effect
    if (apply)
    {
        statusEffect = toApply;
        for (unsigned int i = 0; i < 3; i++)
            mainStats[i] += statusEffect[i];
    }
    // Reverse the negative or positive effect
    else
    {
        for (unsigned int i = 0; i < 3; i++)
            mainStats[i] -= statusEffect[i];
    }
    // Check if the status effect changes the players stat bonuses
    checkStatBonuses();
}

void player::useConsumable(unsigned int index)
{
    std::vector<consumable*> tempC = cInventory->removeConsumables(index, 1);
    if(tempC.size() > 0)
    {
        int stat = tempC.front()->statsToAdd()[0];
        int amount = tempC.front()->statsToAdd()[1];
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
    // Return the experience in a vector to save time
    std::vector<int> temp;

    temp.push_back(currentExperience);
    temp.push_back(maxExperience);

    return temp;
}

void player::save()
{

  std::fstream toWrite;






    /*
        player:
            Name
            Race
            Level
            current HP
            maxHP
            gold
            mainStats
            statusEffect

        weapon:
            dice Size
            dice rolls
            name
            statRequirements

        inventory:

    */
}
