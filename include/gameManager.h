#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "player.h"
#include "monster.h"

#include "outputManager.h"
#include "combatManager.h"
#include "roomManager.h"


#include <vector>
#include <string>


class gameManager
{
public:
	gameManager();
	~gameManager();

	void startGame();


private:
  player* playerPtr;

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










