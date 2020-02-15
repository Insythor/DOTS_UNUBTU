#include "gameManager.h"

#include "screen.h"
#include "roomManager.h"

#include <iostream>
#include <string>

std::string formatRoomType(int type);
bool checkRoomIndex(int type, int index);

int main()
{
  screen myScreen;
  roomManager myRoom;

  bool play = true;
  int type, index = 0;

  while(play)
  {
    std::cin >> type >> index;

    if(checkRoomIndex(type, index))
    {
      myScreen.addToScreen(myRoom.renderRoom(type, index));
      myScreen.print();

      std::cout <<
        "\n" << formatRoomType(type) << " room: " << index
      << std::endl;
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

















