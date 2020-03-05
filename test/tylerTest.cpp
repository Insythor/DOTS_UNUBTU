
/**
  DEBUGGING MAIN CURRENTLY IN USE BY TYLER FOR TESTING THINGS


*/

#include "gameManager.h"

#include <iostream>

int main()
{
  // Resize the terminal, and clear the terminal of text before game begins
  system("resize -s 30 80");
  system("reset");

  gameManager* myManager = new gameManager;

  myManager->startGame();

	return 0;
}











