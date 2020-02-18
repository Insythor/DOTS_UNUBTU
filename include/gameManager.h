#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H



#include "monster.h"
#include "chest.h"

#include "outputManager.h"
#include "combatManager.h"
#include "roomManager.h"


#include <vector>
#include <string>


class gameManager
{
public:
	struct raceData
	{
	  int index;
	  std::string race;
	  int health;
	  int strength;
	  int dexterity;
	  int intelligence;
	  int speed;
	  std::string description;

	};

	gameManager();
	~gameManager();

	void startGame();

private:


  monster* monsterPtr;

  int currentLevel;

  roomManager* currentRoom;



  void characterCreation();

  void mainMenu();

  void loadGame();

  void enterRoom();

  void beginCombat();

  void chooseNextRoom();


};
#endif // GAMEMANAGER_H










