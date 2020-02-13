#ifndef ROOM_H
#define ROOM_H

#include <fstream>
#include <vector>

class room
{
public:
	room();
	~room();

	void readInRooms();

private:
  static int puzzleRoomCounter;

  int nextRoom[];
  int roomLevel;
  //  Pass the screen the parsed text file and add it to the screen
  std::vector<std::vector<char>>* toRender;

  bool shop;

};

#endif // ROOM_H
