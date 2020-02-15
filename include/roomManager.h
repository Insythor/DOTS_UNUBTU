#ifndef ROOM_H
#define ROOM_H

#define roomDir "docs/DATA/rooms/"
#define DEFAULT_WIDTH 79
#define DEFAULT_HEIGHT 21

#include <fstream>

#include <string>
#include <vector>

class roomManager
{
public:
	roomManager();
	~roomManager();

	void readInRooms();

	std::vector<std::vector<char>>* renderRoom(int type, int index);

private:
  int puzzleRoomCounter = 0;

  int nextRoom[];
  int roomLevel;

  bool shop;

  /**
      @brief Pointer to the next room which will be rendered on the screen
  */
  std::vector<std::vector<char>>* toRender;
  /**
    @brief 2D array of rooms that are ready to be rendered to the screen
  */
  std::vector<std::vector<char>>** allRooms;

  std::string formatRoomType(int type);

  void allocateMemory();

};

#endif // ROOM_H
