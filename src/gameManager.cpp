#include "gameManager.h"

gameManager::gameManager()
{
  allRaces = new std::vector<raceData>;

  readInRaceData();
}

gameManager::~gameManager()
{

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
}

void gameManager::printRaces()
{
    for(auto i : (*allRaces))
  {
    std::cout <<
            i.index << "  " << i.race << "  " << i.maxHP << "  " <<
            i.mStats[0] << "  " << i.mStats[1] << "  " << i.mStats[2] << "  " <<
            i.mStats[3] << "  " << i.description
    << std::endl;
  }
}

void gameManager::startGame()
{

}

void gameManager::characterCreation()
{

}

void gameManager::mainMenu()
{

}

void gameManager::loadGame()
{

}

void gameManager::enterRoom()
{

}

void gameManager::beginCombat()
{

}

void gameManager::chooseNextRoom()
{

}
