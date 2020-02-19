
/**
  DEBUGGING MAIN CURRENTLY IN USE BY TYLER FOR TESTING THINGS


*/

#include "gameManager.h"
#include "screen.h"
#include "roomManager.h"
#include "dice.h"
#include "weapon.h"


// For sleep
#include <unistd.h>
#include <iostream>
#include <string>

// Prototypes for temp functions
std::string formatRoomType(int type);
bool checkRoomIndex(int type, int index);

int main()
{

  screen myScreen;
  roomManager myRoom;
  dice myDice;
  gameManager myManager;


  bool play = true;
  int type, index = 0;
  char command;


  while(play)
  {
    std::cin >> command;

    switch (command)
    {
    case 'r':
      std::cin >> type >> index;

      if(checkRoomIndex(type, index))
      {
        myScreen.addToScreen(myRoom.renderRoom(type, index));
        myScreen.print();

        std::cout <<
          "\n" << formatRoomType(type) << " room: " << index
        << std::endl;
      }
      break;

    case 'd':
        std::cin >> type;
        std::cout << myDice.roll(type) << std::endl;
    break;
    /// generate a bunch of weapons for testing
    case 'w':
      for( int i = 1; i <= 10; i ++)
      {
        //sleep(1);
        weapon tempWeapon(i, myManager.getWeaponNames());
          // tempWeapon.generateWeapon(i);
        std::cout << "Level " << i << " : " << tempWeapon;

      }
    break;

    case 'm':

    break;

    /// Quit
    case 'q':
      play = false;
      break;

    default:
      std::cout << "invalid command" << std::endl;
      break;
    }
  }
	return 0;
}

std::string formatRoomType(int type)
{
  std::string temp;


  if(type == 0)
    temp = "boss";
  else if(type == 1)
    temp = "chest";
  else if(type == 2)
    temp = "monster";
  else if(type == 3)
    temp = "shop";
  else if(type == 4)
    temp = "default";

    return temp;
}

bool checkRoomIndex(int t, int i)
{
  bool validIndex;

  if(t < 4 && t >= 0)
    validIndex = true;
  else
  {
    std::cout << "invalid room type\n";
    validIndex = false;
  }

  if(i < 3 && i >= 0)
    validIndex = true;
  else
  {
    std::cout << "invalid room type index\n";
    validIndex = false;
  }
    return validIndex;
}











