#ifndef ROOM_H
#define ROOM_H

#define roomDir "docs/DATA/rooms/"
#define DEFAULT_WIDTH 79
#define DEFAULT_HEIGHT 16
#define DEFAULT_FILE ".txt"

#include "chest.h"
#include "player.h"
#include "monster.h"
#include "combatManager.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

class roomManager
{
public:
	roomManager();
	~roomManager();
  /**
    @brief stream in all .txt files which contain the ASCII art for the rooms
  */
  /**
    @brief Return a pointer to the requested room
    @param[in] int Type: 0 = boss, 1 = chest, 2 = monster, 3 = shop, 4 = default
    @param[in] int Index: Which iteration of the room type (i.e. boss room 4)
  */
  std::string getDescription();
  bool getRoomComplete();
  int getLevel();
  int getRoomType();
  static std::vector<std::string>* allNames;
private:
  int puzzleRoomCounter = 0;
  int roomType;
  bool roomComplete;
  std::vector<int> nextRooms;
  std::vector<chest*> chests;
  player* myPlayer;
  monster* myMonster;
  combatManager* myCombat;
  int roomLevel;
  std::string description;
  void enterRoom();
  void changeRoom(int nextRoom);
  void inventoryManagement(int type, int index);
  void createChestRoom();
  void createMonsterRoom();
  void createShopRoom();
  void createPuzzleRoom();
  bool is_number(const std::string& s);
  std::vector<int> formatCommand(std::string command);
  monster* generateMonster();
};

#endif // ROOM_H
