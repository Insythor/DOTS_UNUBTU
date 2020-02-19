#include "gameManager.h"

gameManager::gameManager()
{
  allRaces = new std::vector<raceData>;
  allWeaponNames = new std::vector<std::string>;

  readInRaceData();
  readInWeapons();

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

void gameManager::startGame()
{

}

void gameManager::characterCreation()
{
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





   playerPtr = new player(tempName,
                          allRaces->at(tempRaceIndex).race,
                          allRaces->at(tempRaceIndex).maxHP,
                          allRaces->at(tempRaceIndex).mStats);

//  system("clear");
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

monster* gameManager::generateMonster(int l, int index, std::string tName)
{
    monster* temp = new monster(tName,
                                 allRaces->at(index).race,
                                 allRaces->at(index).maxHP,
                                 allRaces->at(index).mStats, 
                                 l );

    return temp;
}

std::vector<std::string>* gameManager::getWeaponNames()
{
  return allWeaponNames;
}
