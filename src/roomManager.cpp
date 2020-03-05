#include "roomManager.h"
#include "monster.h"
#include <iostream>

roomManager::roomManager()
{
  readInRooms();
  roomComplete = false;
  srand (time(NULL));
  for(int i = 0; i < 3; i++)
  {
    int tempRoomType = rand() % 3;
    nextRooms.push_back(tempRoomType);
  }
}

roomManager::~roomManager()
{

}

void roomManager::readInRooms()
{

}

void roomManager::enterRoom()
{
    bool play = true;
    // Temp variables used for comsuming input stream
    // Convert to string stream for dynamic input / overloading
    std::string command;
    // User input converted into integers
    // input[0] command to switch on in the main loop
    std::vector<int> input;
    while (play)
    {
        std::getline(std::cin, command);
        input = formatCommand(command);

        switch (input[0])
        {
        case 0:
            play = false;
            break;

        default:
            std::cout << "invalid command" << std::endl;
            break;
        }
    }
}


void roomManager::changeRoom(int nextRoom)
{
  if(!chests.empty())
  {
    for(chest* i : chests)
    {
      delete i;
    }
    chests.clear();
  }
  type = nextRooms[nextRoom];
  roomComplete = false;
  for(int i = 0; i < 3; i++)
  {
    int tempRoomType = rand() % 5;
    nextRooms.push_back(tempRoomType);
  }
  if(roomLevel % 5 == 0)
    nextRooms.push_back(3);
  switch(type)
  {
  case 0:
    createMonsterRoom();
    break;
    case 1:
      createChestRoom();
    break;
    case 2:
      createMonsterRoom();
    break;
    case 3:
      createShopRoom();
    break;
    case 4:
      createPuzzleRoom();
  }
}

void roomManager::createChestRoom()
{
  srand (time(NULL));
  int chestAmount = rand() % 4 + 1;
  for(int i = 0; i < chestAmount; i++)
  {
    chests.push_back(new chest(roomLevel));
  }
}

void roomManager::createMonsterRoom()
{
  monster* myMonster = generateMonster();
  combatManager* myCombat = new combatManager(myPlayer, myMonster);
}

void roomManager::createShopRoom()
{

}

void roomManager::createPuzzleRoom()
{

}

monster* roomManager::generateMonster()
{
  int spawnLevel = roomLevel / 5;
  if(spawnLevel < 1)
    spawnLevel = 1;
  else if(spawnLevel > 5)
    spawnLevel = 5;
    int index = rand() % baseCharacter::allRaces->size();
    monster* temp = new monster("Temp Monster",
        baseCharacter::allRaces->at(index).race,
        baseCharacter::allRaces->at(index).maxHP,
        baseCharacter::allRaces->at(index).mStats,
        spawnLevel);
    temp->spawnWeapon(spawnLevel);
    return temp;
}

std::vector<int> roomManager::formatCommand(std::string command)
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
    // GTFO
    if (tempCommand[0] == "exit" || tempCommand[0] == "quit"
          || tempCommand[0] == "e")
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

std::string roomManager::getDescription()
{
  return "n/a";
}

bool roomManager::getRoomComplete()
{
  return roomComplete;
}

int roomManager::getLevel()
{
  return roomLevel;
}

int roomManager::getType()
{
  return type;
}

