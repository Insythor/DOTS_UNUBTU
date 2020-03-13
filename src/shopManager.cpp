#include "shopManager.h"

shopManager::shopManager()
{
  //ctor
}

shopManager::~shopManager()
{
  //dtor
}
shopManager::shopManager(int roomCount, player* myPlayer)
{
  int level = (roomCount / 5);
  customer = myPlayer;
  std::cout << level << std::endl;
  if(level > 0)
    gold = 200 * level;
  else
      gold = 200;

  sinventory = new inventory;
  // Give the shop 5 of the current level of healing consumable
  std::vector<consumable*> tempCon;
  for(int i = 0; i < 5; i++)
    tempCon.push_back(new consumable(level));
  sinventory->addConsumables(tempCon);
  tempCon.clear();
  // Give the shop one of every book
  tempCon.push_back(new consumable(5));
  tempCon.push_back(new consumable(6));
  tempCon.push_back(new consumable(7));
  tempCon.push_back(new consumable(8));

  sinventory->addConsumables(tempCon);

  // Give the shop a weapon of this level
  sinventory->addWeapon(new weapon(level));
  // Give the player an option to buy a level for the next tier of rooms
  sinventory->addWeapon(new weapon(level + 1));

  sinventory->addAbility(new ability(level));


  startTransaction();
}

void shopManager::startTransaction()
{
  std::string command;

  std::cout
    << std::setw(40) << "WELCOME ADVENTURER!!!\n"
    << "Got stuff to sell? Need to buy some supplies?!\n";

  std::cin >> command;
  std::cout << std::endl;


  switch(formatCommand(command))
  {
    case 0:
      sinventory->viewInventory();
      break;

    case 1:
      customer->getInventory()->viewInventory();
      break;

    default:
      std::cout
       << "Invalid Command\n"
       << "Type 'buy' or 'sell' to access the different shop menus"
       << std::endl;
      break;
  }


}

int shopManager::formatCommand(std::string command)
{
  for(unsigned int i = 0; i < command.length(); i++)
    command[i] = std::tolower(command[i]);

  if(command == "sell" || command == "s")
    return 0;

  else if (command == "buy" || command == "b")
    return 1;

  return -1;
}
