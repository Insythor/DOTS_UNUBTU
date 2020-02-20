#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

/// UPDATE 
#define DIR_RACE "../../docs/DATA/raceData.csv"
#define DIR_WEAPON "../../docs/DATA/weaponNames.txt"
#define DIR_INTRO "../../docs/DATA/introStory.txt"

#include "baseCharacter.h"
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
#include <iomanip>
#include <sstream>

// trying to find what libraries i need to slowly print text
#include <chrono>
#include <thread>
//#include "unistd.h"

#include <time.h>

class gameManager
{
public:


	gameManager();
	~gameManager();

	void startGame();
	std::vector<std::string>* getWeaponNames();


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

  std::vector<std::string>* allWeaponNames;

  int currentLevel;


  void characterCreation();

  void mainMenu();

  void loadGame();

  void enterRoom();
  // We'll have to start each room description with an index so we know what 
  // type of monster to spawn
  void beginCombat(int l, int index);

  void chooseNextRoom();

  void readInRaceData();

  void printRaces();  // debugging

  void readInWeapons();

  monster* generateMonster(int l, int index, std::string tName);

};
#endif // GAMEMANAGER_H










