/**
  @author Tyler Justinen-Teite

*/

#include "gameManager.h"

int main()
{
  gameManager* myGame = new gameManager;

  myGame->startGame();

  delete myGame;

	return 0;
}
