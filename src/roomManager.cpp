#include "roomManager.h"


#include <iostream>

roomManager::roomManager()
{
  allocateMemory();
  readInRooms();
}

roomManager::~roomManager()
{

}

void roomManager::readInRooms()
{
  std::ifstream toRead;



  // for each [t]ype of room
    for(int t = 0; t < 5; t++)
    {
    // for each [i]ndex of that [t]ype
    for(int i = 0; i < 3; i ++)
    {
      std::string room = roomDir;
      char ct = t;
      char ci = i;
      room.append(ct).append(forrmatRoomType(t)).append(ci);
      toRead.open(room);

      std::cout << room << std::endl;

      while(!toRead.eof())
      {
        std::string line;
        toRead >> line;
        for(int y = 0; y < DEFAULT_HEIGHT; y++)
        {
            allRooms[t][i].push_back(std::vector<char>());

            for (int x = 0; x < DEFAULT_WIDTH; x++)
            {
              allRooms[t][i][y].push_back(line[x]);
            }
          }
        }
        toRead.close();
      }
    }
  }


std::string roomManager::formatRoomType(int type)
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

std::vector<std::vector<char>>* roomManager::renderRoom(int type, int index)
{
  toRender = &allRooms[type][index];
  return toRender;
}

void roomManager::allocateMemory()
{
  /// 0boss 1chest 2monster 3shop 4default
  allRooms = new std::vector<std::vector<char>>* [5];

  for(int y = 0; y < 5; y++)
  {
    allRooms[y] = new std::vector<std::vector<char>> [3];

  //  for(int x = 0; x < 3; x++)
    {
//      allRooms[y][x] = new std::vector<std::vector<char>>;
    }
  }
}
