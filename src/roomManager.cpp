#include "roomManager.h"
#include "monster.h"
#include <iostream>

roomManager::roomManager()
{
  roomComplete = false;
  srand (time(NULL));
  for(int i = 0; i < 3; i++)
  {
    int tempRoomType = rand() % 3;
    nextRooms.push_back(tempRoomType);
  }
  roomLevel = 0;
  roomType = 2;
}

roomManager::~roomManager()
{
  delete myPlayer;
  if(!chests.empty())
  {
    for(chest* i : chests)
    {
      delete i;
    }
    chests.clear();
  }
  delete myMonster;
  delete myCombat;
}

void roomManager::enterRoom()
{
    roomLevel++;
    bool play = true;
    // Temp variables used for comsuming input stream
    // Convert to string stream for dynamic input / overloading
    std::string command;
    // User input converted into integers
    // input[0] command to switch on in the main loop
    std::vector<int> input;
  switch (roomType) {
  case 0:
    myMonster = generateMonster();
    myCombat = new combatManager(myPlayer, myMonster);
    createMonsterRoom();
    break;
  case 1:
    createChestRoom();
    break;
  case 2:
    myMonster = generateMonster();
    myCombat = new combatManager(myPlayer, myMonster);
    createMonsterRoom();
    break;
  case 3:
    //shop
    break;
  case 4:
    //puzzle
    break;
  }
    while (play)
    {
        std::getline(std::cin, command);
        input = formatCommand(command);

        switch (input[0])
        {
        case 0:
            play = false;
            break;
        case 121:
            inventoryManagement(0, 0);
            break;
        case 15:
          if(input[1] <= chests.size())
          {
            chests[input[1] - 1]->open();
            inventoryManagement(1, input[1] - 1);
          }
          else
          {
            std::cout << "invalid command" << std::endl;
          }
            break;
        case 151:
          if(input[1] <= chests.size())
          {
            chests[input[1] - 1]->open();
            inventoryManagement(1, input[1] - 1);
          }
           else
          {
            std::cout << "invalid command" << std::endl;
          }
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
  roomType = nextRooms[nextRoom];
  roomComplete = false;
  for(int i = 0; i < 3; i++)
  {
    int tempRoomType = rand() % 5;
    nextRooms.push_back(tempRoomType);
  }
  if(roomLevel % 5 == 0)
    nextRooms.push_back(3);
    enterRoom();
}

void roomManager::createChestRoom()
{
  if(chests.empty())
  {
    srand (time(NULL));
    int chestAmount = rand() % 4 + 1;
    for(int i = 0; i < chestAmount; i++)
    {
      chests.push_back(new chest(roomLevel));
    }
  }
  int index = 1;
  description = "Need room description here\n";
  for(chest* i : chests)
  {
    description += std::to_string(index) + ". Chest";
    if(i->getIsOpen())
      description += "(Open)\n";
    else
      description += "\n";
  }
  description += "What would you like to do: ";
  std::cout << description;
}
//0 = player 1 = chest for type and index is for chest
void roomManager::inventoryManagement(int type, int index)
{
  if(type == 0)
  {

  }
  else
  {

  }
}

void roomManager::createMonsterRoom()
{
  description = "Need room description here\n";
  description += "1. Start Fight\n2. View Inventory\nWhat would you like to do: ";
  std::cout << description;
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
    else if(tempCommand[0] == "i" || tempCommand[0] == "inventory")
          temp.push_back(121);
    //Open chest at value
    else if(roomType == 1 && tempCommand[0] == "open" && (tempCommand[1] == "1" || tempCommand[1] == "2" || tempCommand[1] == "3"))
          temp.push_back(15);
    //Open chest using index
    else if(roomType == 1 && (tempCommand[0] == "1" || tempCommand[0] == "2" || tempCommand[0] == "3") && tempCommand.size() == 1)
    {
      temp.push_back(151);
      temp.push_back(std::stoi(tempCommand[0]));
    }
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
        for (std::string i : tempCommand)
        {
            if(is_number(i))
              temp.push_back(std::stoi(i));
        }
    }
    temp.shrink_to_fit();
    return temp;
}

bool roomManager::is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(),
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
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

int roomManager::getRoomType()
{
  return roomType;
}

