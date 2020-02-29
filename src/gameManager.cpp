#include "gameManager.h"

gameManager::gameManager()
{
  allRaces = new std::vector<raceData>;
  allWeaponNames = new std::vector<std::string>;

  readInRaceData();
  readInWeapons();

//  printRaces();

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

#include<map>

// Main loop
void gameManager::startGame()
{

    bool play = true;
    // Temp variables used for comsuming input stream
    // Convert to string stream for dynamic input / overloading
    std::string command;
    int input0, input1;

    combatManager* thisFight = nullptr;



    while (play)
    {
      

        std::cin >> command;
   //     std::cout << std::endl << command << "  " << formatCommand(command) << std::endl;

        switch (formatCommand(command))
        {
            /**     print commands                    */

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
        case 130:
            std::cout << monsterPtr->getWeapon()->getName() << std::endl;
            break;

            /**        make commands (spawn an object)      */
            // makeWeapon,  mw
        case 20:
            playerPtr->spawnWeapon(currentLevel, allWeaponNames);
            std::cout << (*playerPtr->getWeapon());
            break;
            // makePlayer, mp
        case 21:
            std::cin >> input0;
            playerPtr = characterCreation(input0);
            std::cout << (*playerPtr);
            break;
            // levelUp, lvl
        case 210:
            playerPtr->levelUp();
            break;
            // makeMonster, mm
        case 22:
            // input0 = level, input1 = raceIndex
            std::cin >> input0 >> input1;
            monsterPtr = generateMonster(input0, input1);
            std::cout << (*monsterPtr);
            break;
            // makeCombat, mc
        case 23:
            monsterPtr = generateMonster(currentLevel);
            thisFight =  new combatManager(playerPtr, monsterPtr);
            thisFight->startFight();
            delete thisFight;
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

        case 91:
            std::cin >> input0;
            playerPtr->addExperience(input0);
            //std::cout << (*playerPtr);
            break;
        case 92:
          //  std::cout << testList.front()->dealDamage() << std::endl;
            break;

        case 0:
            play = false;
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

int gameManager::formatCommand(std::string command)
{
    int temp = -1;
    // Print functions are prefixed with 1
    if (command == "pRace" || command == "pr")
        temp = 10;

    else if (command == "pWeapon" || command == "pw")
        temp = 11;

    else if (command == "pPlayer" || command == "pp")
        temp = 12;
    else if (command == "pPlayerWeapon" || command == "ppw")
        temp = 120;
    else if (command == "pMonster" || command == "pm")
        temp = 13;
    else if (command == "pMonsterWeapon" || command == "pmw")
        temp = 130;

    // Create object prefixed with 2
    else if (command == "makeWeapon" || command == "mw")
        temp = 20;

    else if (command == "makePlayer" || command == "mp")
        temp = 21;
    else if (command == "levelUp" || command == "lvl")
        temp = 210;

    else if (command == "makeMonster" || command == "mm")
        temp = 22;
    // Start combat
    else if (command == "makeCombat" || command == "mc")
        temp = 23;


    // debugging gets a prefix of 9
    else if (command == "clear")
        temp = 90;
    // add x to the players current experience
    else if (command == "addExperience" || command == "xp")
        temp = 91;
    // print the damage done from a normal weapon attack by the player
    else if (command == "atk")
        temp = 92;


    else if (command == "exit" || command == "quit" || command == "end")
        temp = 0;

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
            " coming right up!" << "\n\n *scurrying and panting can be heard as "
            "the hero approaches*" <<
  std::endl;


  for(int i = 0; i < 3; i++)
  {
    //sleep(1);
    std::cout << "\n..." << std::endl;
  }

  //sleep(1);
  //system("clear");

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
    player* temp = new player("TempHero",
        allRaces->at(index).race,
        allRaces->at(index).maxHP,
        allRaces->at(index).mStats);

    temp->spawnWeapon(currentLevel, allWeaponNames);

    return temp;
}
// Overloaded characterCreation() generates a player with given race
player* gameManager::characterCreation(std::string race)
{
    player* temp = nullptr;
    for (auto i : (*allRaces))
    {
        if (i.race == race)
        {
            temp = new player("Temp Hero",
                allRaces->at(i.index).race,
                allRaces->at(i.index).maxHP,
                allRaces->at(i.index).mStats);
            temp->spawnWeapon(currentLevel, allWeaponNames);
            return temp;
        
        }
    }
    
    delete temp;
    return nullptr;
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



std::vector<std::string>* gameManager::getWeaponNames()
{
  return allWeaponNames;
}
