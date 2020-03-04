#include "gameManager.h"

gameManager::gameManager()
{
  allRaces = new std::vector<raceData>;
  allWeaponNames = new std::vector<std::string>;

  readInRaceData();
  readInWeapons();

  currentLevel = 1;
  playerPtr = characterCreation(1);


  monsterPtr = generateMonster(1);

// mainMenu();
}

 gameManager::~gameManager()
{
  delete allRaces;
  delete allWeaponNames;
  delete playerPtr;
  delete monsterPtr;
}

void gameManager::readInWeapons()
{
  std::ifstream weaponNames;
  weaponNames.open(DIR_WEAPON);
  std::string line;
  // Store each line (name) in a dictionary of weaponNames
  while(getline(weaponNames, line))
  {
    allWeaponNames->push_back(line);
  }

  weaponNames.close();

  allWeaponNames->shrink_to_fit();

  // printWeapons();
}

void gameManager::readInRaceData()
{
  // ifstream to read in the csv file
  std::ifstream toRead;
  // Open the file
  toRead.open(DIR_RACE);
  // temp variables
  std::vector<std::string> tempData;
  std::string line;

  while(getline(toRead, line, ','))
  {
    tempData.push_back(line);
  }
  toRead.close();

  for(unsigned int i = 0; i < 10; i ++)
  {
    // Initialize a new index in the vector
    allRaces->push_back(raceData());
    // Init the stats vector to have a size of 4
    allRaces->at(i).mStats.resize(4);
    // Load all of the race data into the allRaces vector
    allRaces->at(i).index = std::stoi(tempData.at(0));
    allRaces->at(i).race = tempData.at(1);
    allRaces->at(i).maxHP = std::stoi(tempData.at(2));
    allRaces->at(i).mStats[0] = std::stoi(tempData.at(3));
    allRaces->at(i).mStats[1] = std::stoi(tempData.at(4));
    allRaces->at(i).mStats[2] = std::stoi(tempData.at(5));
    allRaces->at(i).mStats[3] = std::stoi(tempData.at(6));
    allRaces->at(i).description = tempData.at(7);

    // Once all the data for a race has been loaded, clear that section
    // of the tempData vector
    tempData.erase(tempData.begin(), tempData.begin() + 8);
  }
  allRaces->shrink_to_fit();
 // printRaces();
}

void gameManager::printRaces()
{
  for(auto i : (*allRaces))
  {
    // Spacers for formating race data
    int wName = 13 - i.race.length();
    int wHP = 4;
    int wStr = 4;
    int wDex = 4;
    int wInt = 4;
    int wSpd = 8;
    // Formatting text output based on how many digits the number is
    if(i.maxHP % 100 == 0)
      wHP ++;
    if(i.mStats[0] % 10 == 0 && i.mStats[0] != 0)
      wStr --;
    if(i.mStats[1] % 10 == 0 && i.mStats[1] != 0)
      wDex --;
    if(i.mStats[2] % 10 == 0 && i.mStats[2] != 0)
      wInt --;
    if(i.mStats[3] % 10 == 0 && i.mStats[3] != 0)
      wSpd --;

    std::cout <<
            i.index << "  " << i.race << std::setw(wName) << i.maxHP <<
            std::setw(wHP) << i.mStats[0] << std::setw(wStr) << i.mStats[1] <<
            std::setw(wDex) << i.mStats[2] << std::setw(wInt) << i.mStats[3] <<
            std::setw(wSpd) << i.description
    << std::endl;
  }
}

void gameManager::printWeapons()
{
    for (auto i : (*allWeaponNames))
        std::cout << i << std::endl;
}

void gameManager::printConsumables()
{
    for (int i = 0; i <= consumable::lastIndex; i++)
    {
        consumable* toPrint = new consumable(i);
        std::cout << *toPrint;
        delete toPrint;
    }
}

// Main loop
// Most of this is going to be ripped out as it is primarily debugging stuff atm
void gameManager::startGame()
{
    bool play = true;
    // Temp variables used for comsuming input stream
    // Convert to string stream for dynamic input / overloading
    std::string command;
    // User input converted into integers
    // input[0] command to switch on in the main loop
    std::vector<int> input;

    combatManager* thisFight = nullptr;
    consumable* myConsumable = nullptr;

    while (play)
    {
        std::getline(std::cin, command);
        input = formatCommand(command);

        switch (input[0])
        {
            /**     print commands       */

        // pPlayer, pp
        case 10:
            printRaces();
            break;
        // pWeapon, pw
        case 11:
            printWeapons();
            break;

        // pPlayer, pp
        case 12:
            std::cout << (*playerPtr);
            break;
        // pPlayerWeapon, ppw
        case 120:
            std::cout << (*playerPtr->getWeapon()) << std::endl;
            break;

         // pMonster, pm
        case 13:
            std::cout << (*monsterPtr);
            break;
        //pMonsterWeapon, pmw
        case 130:
            std::cout << (*monsterPtr->getWeapon()) << std::endl;
            break;
        // pMonsterGold, pmg
        case 131:
            std::cout << monsterPtr->getGold() << std::endl;
            break;
        // pConsumables, pcon
        case 14:
            printConsumables();
            break;

            /**        make commands (spawn an object)      */
        // makeWeapon,  mw
        case 20:
            // Replace the players equipped weapon at the given level
            if (input.size() == 2)
                playerPtr->spawnWeapon(input[1], allWeaponNames);
            // Replace the players equipped weapon with one of the global level
            else
                playerPtr->spawnWeapon(currentLevel, allWeaponNames);

            std::cout << (*playerPtr->getWeapon());
            break;
        // makePlayer, mp
        case 21:
            if (playerPtr != nullptr)
                delete playerPtr;

            // Spawn a player with the given race index
            if(input.size() == 2)
                playerPtr = characterCreation(input[1]);
            // Spawn a player at a given race index and levelUp x times
            else if (input.size() == 3)
            {
                playerPtr = characterCreation(input[1]);
                for (int i = 0; i < input[2]; i++)
                    playerPtr->levelUp();
            }
            // If no race is given, go through the default character creation
            else
            {
                playerPtr = characterCreation();
            }

            std::cout << (*playerPtr);
            break;

        // makeMonster, mm
        case 22:
            // input0 = level, input1 = raceIndex
            monsterPtr = generateMonster(input[1], input[2]);
            std::cout << (*monsterPtr);
            break;
        // makeCombat, mc
        case 23:
            // Generate a monster at a given level then begin combat
            if (input.size() == 2)
            {
                monsterPtr = generateMonster(input[1]);
                thisFight = new combatManager(playerPtr, monsterPtr);
                thisFight->startFight();
            }
            // Generate a monster at a given level, and race then begin combat
            else if (input.size() == 3)
            {
                monsterPtr = generateMonster(input[1], input[2]);
                thisFight = new combatManager(playerPtr, monsterPtr);
                thisFight->startFight();
            }
            // Start combat with a random monster based on the global level
            else
            {
                monsterPtr = generateMonster(currentLevel);
                thisFight = new combatManager(playerPtr, monsterPtr);
                thisFight->startFight();
            }

            delete thisFight;
            break;
        // makeConsumable, mcon
        case 24:
            myConsumable = new consumable(input[1]);
            std::cout << *myConsumable;
            delete myConsumable;
            break;

            /**             debugging commands            */
        // Clear the terminal window of all text
            /** MAKE SURE THAT THE RIGHT ONE IS ENABLED FOR THE SYSTEM YOU ARE ON! */
        case 90:
            // WINDOWS
            system("cls");
            // Linux
            // system("clear");
            break;
        // addExperience, xp
        case 91:
            playerPtr->addExperience(input[1]);
            //std::cout << (*playerPtr);
            break;
        // levelUp, lvl
        case 210:
            playerPtr->levelUp();
            break;
        //  atk : deal damage with the players equipped weapon
        case 92:
            std::cout << playerPtr->dealDamage() << std::endl;
            break;

        case 0:
            play = false;
            break;
        case 220:
            for(int i = 0; i < 20; i++)
            {
              playerPtr->getInventory()->addWeapon(new weapon(currentLevel, allWeaponNames));
              std::vector<consumable*> tempcon;
              tempcon.push_back(new consumable());
              playerPtr->getInventory()->addConsumables(tempcon);
            }

            playerPtr->getInventory()->viewInventory();
          break;
        default:
            std::cout << "invalid command" << std::endl;
            break;
        }
    }
}

std::string gameManager::formatRoomType(int type)
{
    std::string temp;

    if (type == 0)
        temp = "boss";
    else if (type == 1)
        temp = "chest";
    else if (type == 2)
        temp = "monster";
    else if (type == 3)
        temp = "shop";
    else if (type == 4)
        temp = "default";

    return temp;
}

bool gameManager::checkRoomIndex(int t, int i)
{
    bool validIndex;

    if (t < 4 && t >= 0)
        validIndex = true;
    else
    {
        std::cout << "invalid room type\n";
        validIndex = false;
    }

    if (i < 3 && i >= 0)
        validIndex = true;
    else
    {
        std::cout << "invalid room type index\n";
        validIndex = false;
    }
    return validIndex;
}

std::vector<int> gameManager::formatCommand(std::string command)
{
    std::vector<int> temp;

    std::vector<std::string> tempCommand;
    std::string parsed;
    std::stringstream parser(command);

    while (getline(parser, parsed, ' '))
    {
        tempCommand.push_back(parsed);
    }
    for (unsigned int i = 0; i < tempCommand.size(); i++)
    {
        for (unsigned int c = 0; c < tempCommand[i].size(); c++)
        {
            tempCommand[i][c] = tolower(tempCommand[i][c]);
        }
    }

    // Print functions are prefixed with 1
    if (tempCommand[0] == "prace" || tempCommand[0] == "pr")
        temp.push_back(10);

    else if (tempCommand[0] == "pweapon" || tempCommand[0] == "pw")
        temp.push_back(11);
    // Print the player's detailed stats
    else if (tempCommand[0] == "pplayer" || tempCommand[0] == "pp")
        temp.push_back(12);
    // Print the players weapon
    else if (tempCommand[0] == "pplayerweapon" || tempCommand[0] == "ppw")
        temp.push_back(120);
    // Print the monsters detailed stats
    else if (tempCommand[0] == "pmonster" || tempCommand[0] == "pm")
        temp.push_back(13);
    // Print the monsters weapon
    else if (tempCommand[0] == "pmonsterweapon" || tempCommand[0] == "pmw")
        temp.push_back(130);
    // Print the monsters gold
    else if (tempCommand[0] == "pmonstergold" || tempCommand[0] == "pmg")
        temp.push_back(131);
    // Print all the consumables in the csv
    else if (tempCommand[0] == "pconsumables" || tempCommand[0] == "pcon")
        temp.push_back(14);


    // Create object prefixed with 2std::vector<consumable*> t
    else if (tempCommand[0] == "makweapon" || tempCommand[0] == "mw")
        temp.push_back(20);
    // Make a player with a chosen race
    else if (tempCommand[0] == "makeplayer" || tempCommand[0] == "mp")
        temp.push_back(21);
    // Increase the players level by 1
    else if (tempCommand[0] == "levelup" || tempCommand[0] == "lvl")
        temp.push_back(210);

    else if (tempCommand[0] == "makemonster" || tempCommand[0] == "mm")
        temp.push_back(22);
    // Start combat
    else if (tempCommand[0] == "makecombat" || tempCommand[0] == "mc")
        temp.push_back(23);

    // Make a consumable, also needs an index.
    else if (tempCommand[0] == "makeconsumable" || tempCommand[0] == "mcon")
        temp.push_back(24);

    // debugging gets a prefix of 9
    else if (tempCommand[0] == "clear")
        temp.push_back(90);
    // add x to the players current experience
    else if (tempCommand[0] == "addexperience" || tempCommand[0] == "xp")
        temp.push_back(91);
    // print the damage done from a normal weapon attack by the player
    else if (tempCommand[0] == "atk")
        temp.push_back(92);
        //print view inventory
    else if (tempCommand[0] == "viewinventory" || tempCommand[0] == "vi")
        temp.push_back(220);
    // GTFO
    else if (tempCommand[0] == "exit" || tempCommand[0] == "quit" || tempCommand[0] == "e")
        temp.push_back(0);
    // If no valid command was entered
    else
    {
       temp.push_back(-1);
       return temp;
    }
    // Remove the command  string
    tempCommand.erase(tempCommand.begin());
    // Pushback all the numbers remaining in the command
    if (!tempCommand.empty())
    {
        for (auto i : tempCommand)
        {
            temp.push_back(std::stoi(i));
        }
    }

    temp.shrink_to_fit();

    return temp;
}

void gameManager::mainMenu()
{
  std::ifstream toRead;
  std::string line;

  toRead.open(DIR_INTRO);

  while(getline(toRead, line, ' '))
  {
//    for(unsigned int i = 0; i < line.length(); i++)
    {
  //    std::cout << line;
    }
    std::cout << " ";
  }
  std::cout << std::endl;
  toRead.close();

  // Call the default characterCreation function
  // This has the I/O required for character customization
  characterCreation();
}

void gameManager::saveGame()
{
    playerPtr->save();
}

void gameManager::loadGame()
{

}

void gameManager::enterRoom()
{

}

void gameManager::beginCombat(int l, int index)
{
    std::string tName = "Cheeky McGee";
    monsterPtr = generateMonster(l, index, tName);
}

void gameManager::chooseNextRoom()
{

}

monster* gameManager::generateMonster(int l)
{
    int index = rand() % allRaces->size();

    monster* temp = new monster("Temp Monster",
        allRaces->at(index).race,
        allRaces->at(index).maxHP,
        allRaces->at(index).mStats,
        l);

    temp->spawnWeapon(currentLevel, allWeaponNames);

    return temp;
}

monster* gameManager::generateMonster(int l, int index)
{
    monster* temp = new monster("Temp Monster",
        allRaces->at(index).race,
        allRaces->at(index).maxHP,
        allRaces->at(index).mStats,
        l);

    temp->spawnWeapon(currentLevel, allWeaponNames);

    return temp;
}

monster* gameManager::generateMonster(int l, int index, std::string tName)
{
    monster* temp = new monster(tName,
        allRaces->at(index).race,
        allRaces->at(index).maxHP,
        allRaces->at(index).mStats,
        l );

    temp->spawnWeapon(currentLevel, allWeaponNames);

    return temp;
}

// Default characterCreation(), has cout and cin
player* gameManager::characterCreation()
{
  player* temp;
  int tempRaceIndex;
  std::string tempName;

  std::cout << "\nWhat race is your Hero?\n\n";

  printRaces();

  std::cin >> tempRaceIndex;

  std::cout << "One " << allRaces->at(tempRaceIndex).race <<
            " coming right up!" << "\n\n *scurrying and panting can be heard as"
            " the hero approaches*" <<
  std::endl;


  for(int i = 0; i < 3; i++)
  {
    //sleep(1);
   // std::cout << "\n..." << std::endl;
  }

 // sleep(1);

//  system("clear");

  std::cout <<
        "Finally! Your hero has arrived!\nWhat shall we call this one then?" <<
        "\nName: ";

  std::cin >> tempName;

  std::cout <<
        "Cool a " << allRaces->at(tempRaceIndex).race << " named " << tempName
        << " \nNo ones ever done that combo before I'm sure... Anyways! " <<
        "\nONWARD TO STAT SELECTION!"
  << std::endl;
  // Set the temp player to what the user has selected, and genereate their hero
   temp = new player(tempName,
                          allRaces->at(tempRaceIndex).race,
                          allRaces->at(tempRaceIndex).maxHP,
                          allRaces->at(tempRaceIndex).mStats);

   temp->spawnWeapon(currentLevel, allWeaponNames);

   return temp;

//  system("clear");
}
// Overloaded characterCreation(), generates a player at given race index
player* gameManager::characterCreation(int index)
{
    player* temp = new player("Temp_Hero",
        allRaces->at(index).race,
        allRaces->at(index).maxHP,
        allRaces->at(index).mStats);

    temp->spawnWeapon(currentLevel, allWeaponNames);

    return temp;
}



std::vector<std::string>* gameManager::getWeaponNames()
{
  return allWeaponNames;
}
