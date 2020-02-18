#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#define DIR_RACE "../docs/DATA/raceData.csv"

#include "player.h"
#include "monster.h"
#include "chest.h"
#include "outputManager.h"
#include "combatManager.h"
#include "roomManager.h"


#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

class gameManager
{
public:


	gameManager();
	~gameManager();

	void startGame();

private:
  struct raceData
  {
    int index;
    std::string race;
    int maxHP;
    std::vector<int> mStats;
    std::string description;
  };

  std::vector<raceData>* allRaces;

  player* playerPtr;
  monster* monsterPtr;
  roomManager* currentRoom;

  int currentLevel;


  void characterCreation();

  void mainMenu();

  void loadGame();

  void enterRoom();

  void beginCombat();

  void chooseNextRoom();

  void readInRaceData();

  void printRaces();

};
#endif // GAMEMANAGER_H










