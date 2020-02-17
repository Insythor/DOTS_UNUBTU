#ifndef ROOM_H
#define ROOM_H

#define roomDir "docs/DATA/rooms/"
#define DEFAULT_WIDTH 79
#define DEFAULT_HEIGHT 16
#define DEFAULT_FILE ".txt"

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "chest.h"
class roomManager
{
public:
	roomManager();
	~roomManager();
  /**
    @brief stream in all .txt files which contain the ASCII art for the rooms
  */
	void readInRooms();
  /**
    @brief Return a pointer to the requested room
    @param[in] int Type: 0 = boss, 1 = chest, 2 = monster, 3 = shop, 4 = default
    @param[in] int Index: Which iteration of the room type (i.e. boss room 4)
  */
	std::vector<std::vector<char>>* renderRoom(int type, int index);

private:
  int puzzleRoomCounter = 0;
  int type;
  bool roomComplete;
  int numChests;
  std::vector<chest> chests;
  std::vector<int> nextRooms;
  int roomLevel;
  std::string description;
  /**
      @brief Pointer to the next room which will be rendered on the screen
  */
  std::vector<std::vector<char>>* toRender;
  /**
    @brief 2D array of rooms that are ready to be rendered to the screen
  */
  std::vector<std::vector<char>>** allRooms;

  std::string formatRoomType(int type, int index);
  /**
    @brief Helper function which allocates memory for the 2D array of rooms
  */
  void allocateMemory();
  void changeRoom(int nextRoom);
  std::string getDescription();
  bool getRoomComplete();
  chest* getChest(int index);
  int getLevel();
  int getType();
};

#endif // ROOM_H
