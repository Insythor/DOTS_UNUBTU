#include "shopManager.h"

shopManager::shopManager()
{
  //ctor
}

shopManager::~shopManager()
{
  //dtor
}
shopManager::shopManager(const int& roomCount, player* myPlayer)
{
  int level = (roomCount / 5);
  customer = myPlayer;

  if(level > 0)
    gold = 200 * level;
  else
      gold = 200;

  sinventory = new inventory;
  /// Give the shop 5 of the current level of healing consumable
  std::vector<consumable*> tempCon;
  for(int i = 0; i < 5; i++)
    tempCon.push_back(new consumable(level));

  sinventory->addConsumables(tempCon);
  tempCon.clear();
  /// Give the shop one of every book
  tempCon.push_back(new consumable(5));
  sinventory->addConsumables(tempCon);
  tempCon.clear();

  tempCon.push_back(new consumable(6));
  sinventory->addConsumables(tempCon);
  tempCon.clear();

  tempCon.push_back(new consumable(7));
  sinventory->addConsumables(tempCon);
  tempCon.clear();

  tempCon.push_back(new consumable(8));
  sinventory->addConsumables(tempCon);
  tempCon.clear();

  /// Give the shop a weapon of this level
  sinventory->addWeapon(new weapon(level));
  /// Give the player an option to buy a level for the next tier of rooms
  sinventory->addWeapon(new weapon(level + 2));

  sinventory->addAbility(new ability(level));

  /// Harded coded indexes for the shop
  lastWeapon = 2;
  lastConsumable = 7;
  lastIndex = 8;

  startTransaction();
}

void shopManager::startTransaction()
{
  bool stillShoping = true;

  while(stillShoping)
  {
    std::cout << "So. Here to 'buy' or 'sell'? ";
    // Temp
    int cost;
    // Input
    std::string command;
    int itemIndex;
    print::setCursor(true);

    std::cin >> command;
    std::cout << std::endl;
    print::setCursor(false);

    switch(formatCommand(command))
    {
      case 0:
        print::str("Let me know if you see something you like.");
        std::cout << std::endl << std::endl;

        /// Show the user what's in the shop
        sinventory->viewInventory();

        /// Select an item to purchase
        print::setCursor(true);
        std::cout << ">>> ";
        std::cin >> itemIndex;
        std::cout << std::endl;
        print::setCursor(false);

        /// Decrement so that it starts counting at 0
        itemIndex--;

        /** If the selected item is a weapon */
        if(itemIndex < lastWeapon)
        {
          /// Reusing the command variable for printing
          command = "Are you use that you would like to purchase the " +
           sinventory->getWeapons().at(itemIndex)->getName() + "?\nIt's only " +
           std::to_string(sinventory->getWeapons().at(itemIndex)->getCost()) +
           " gold!\nSpecial price for my special friend!!!";
           print::str(command);
           std::cout << std::endl;
           /// Enter purchase confirmation
           print::setCursor(true);
           std::cin >> command;
           print::setCursor(false);
           switch(formatCommand(command))
           {
            case 0:
              /// Set the cost as a dummy variable
              cost = sinventory->getWeapons().at(itemIndex)->getCost();

              if(canAfford(cost))
              {
                /// Make the customer pay for their goods
                customer->setGold(-cost);
                /// Add the purchased weapon to the players inventory
                customer->getInventory()->
                            addWeapon(sinventory->removeWeapon(itemIndex));
                /// Reduce the stock amount
                lastWeapon--;
                lastIndex--;
              }
              else
                tooExpensive(cost);
              break;

            case 1:
              somethingElse();
              break;
           }
        }
        /** If the selected item is a consumable */
        else if(itemIndex < lastConsumable)
        {
          itemIndex -= lastWeapon;

        }
        /** If the selected item is an ability */
        else
        {
          itemIndex -= (lastWeapon + lastConsumable);
        }

        break;

      case 1:
        if(customer->getInventory()->isEmpty())
          print::str
          ("What do you want to sell me?! The lint in your pockets! HA!");
          std::cout << std::endl;

        customer->getInventory()->viewInventory();
        break;

      case -1:
        std::cout
         << std::cout <<
         "Type 'buy' or 'sell' to access the different shop menus\n"
         << std::endl;
         break;

      default:
        print::textColour(print::C_RED);
        std::cout << "Invalid Command" << std::endl;
        print::textColour(print::C_DEFAULT);
        std::cout <<
         "Type 'buy' or 'sell' to access the different shop menus\n"
         << std::endl;
        break;
    }
  }
}

int shopManager::formatCommand(std::string command)
{
  for(unsigned int i = 0; i < command.length(); i++)
    command[i] = std::tolower(command[i]);

  if(command == "buy" || command == "b" || command == "yes" || command == "y")
    return 0;

  else if (command == "sell" || command == "s"
            || command == "no" || command == "n")
    return 1;


  return -1;
}

bool shopManager::canAfford(const int& cost)
{
  return customer->getGold() >= cost;
}

void shopManager::tooExpensive(const int& cost)
{
  std::string toPrint;
  switch(rand() % 3)
  {
    case 0:
      toPrint = "Look. The price is the price kid. Maybe one day you'll have "
       + std::to_string(cost - customer->getGold()) +
       " more gold and you can get this one.";
       print::str(toPrint);
       std::cout << std::endl;
       break;

    case 1:
      toPrint = "Some monster slayer. Can't even afford " + std::to_string(cost)
      +" coins for some clearly needed supplies.\n" +
      "\nMaybe there's something here you actually can afford...\n" +
      "Take another look around kid";
      print::str(toPrint);
      std::cout << std::endl;
      break;

    case 2:
      toPrint = "O.K. You have " + std::to_string(customer->getGold())
        +" gold.\n"
       "What you want costs " + std::to_string(cost) + " gold.\n" +
       "See how that first number is smaller than the second one.\n" +
       "That means you can't have it, until the first number is bigger.";
      print::str(toPrint);
      std::cout << std::endl;
      break;
  }
}

void shopManager::somethingElse()
{
  switch(rand() % 3)
  {
    case 0:
      print::str("Something else perhaps?");
      break;
    case 1:
      print::str("I'm sure we can find you something more your style!");
      break;
    case 2:
      print::str("Yeah, no one ever wants that one");
      break;
    default:
      print::str("Not for you, that's fine. I got lots of good stuff around");
      std::cout << std::endl;
      break;
  }
}
















