/**
    @author

    @brief

*/

#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H
//User Defined
#include "chest.h"
#include "player.h"
#include "monster.h"
#include "combatManager.h"
// Containers
#include <string>
#include <vector>
// I/O
#include <fstream>
#include <sstream>
// Math
#include <algorithm>

class roomManager
{
public:
  /**
    @brief
    @param[out]
  */
	roomManager();
	~roomManager();
  /**
    @brief
    @param[out]
  */
  std::string getDescription();
  /**
    @brief
    @param[out]
  */
  bool getRoomComplete();
  /**
    @brief
    @param[out]
  */
  int getLevel();
  /**
    @brief
    @param[out]
  */
  int getRoomType();
  /**
    @brief
    @param[out]
  */
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
  std::vector<int> formatCommand(std::string command);
  monster* generateMonster();
};

#endif // ROOMMANAGER_H
