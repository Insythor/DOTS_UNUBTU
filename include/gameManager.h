#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

/// UPDATE 
#define DIR_RACE "../docs/DATA/raceData.csv"
#define DIR_WEAPON "../docs/DATA/weaponNames.txt"
#define DIR_INTRO "../docs/DATA/introStory.txt"

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
    /**
        @brief  Initiate the main loop of the game
    */
	void startGame();
    /**
        @brief Debugging: Print all weapon names read in the the weaponNames dictionary
    */
	std::vector<std::string>* getWeaponNames();


private:
    // Easiest to store all of the race data in a vector<classData>
    struct raceData
    {
        int index;
        std::string race;
        int maxHP;
        std::vector<int> mStats;
        std::string description;
    };
    // All race data read in from races.csv
  std::vector<raceData>* allRaces;
  // 
  player* playerPtr;
  monster* monsterPtr;
  roomManager* currentRoom;

  std::vector<std::string>* allWeaponNames;

  int currentLevel;

  // Helper functions for main loop
  std::string formatRoomType(int type);
  bool checkRoomIndex(int t, int i);
  // Format the users input string to an int to switch on in the mian loop
  int formatCommand(std::string command);

  /**
    @brief Create a character based on user input. Base function 
           is used during main menu
  */
  player* characterCreation();
  /**
    @brief Overloaded character creation which allows you to 
            create a hero based on a race index (see races.csv)
    @param[in] int index of csv to create
  */
  player* characterCreation(int index);
  /**
    @brief Overloaded character creation which allows you to
            create a hero based on a race name (see races.csv)
    @param[str::string] nameof race to createfrom csv
  */
  player* characterCreation(std::string race);

  void mainMenu();

  void saveGame();
  void loadGame();

  void enterRoom();
  // We'll have to start each room description with an index so we know what 
  // type of monster to spawn
  void beginCombat(int l, int index);

  void chooseNextRoom();

  void readInRaceData();

  void printRaces();  // debugging

  void readInWeapons();

  /**
    @brief 
  */
  monster* generateMonster(int l);
  monster* generateMonster(int l, int index);
  monster* generateMonster(int l, int index, std::string tName);
  
};
#endif // GAMEMANAGER_H