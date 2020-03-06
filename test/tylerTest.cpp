
/**
  DEBUGGING MAIN CURRENTLY IN USE BY TYLER FOR TESTING THINGS


*/

#include "gameManager.h"

#include <iostream>

int main()
{
  system("printf '\e[48;2;0;0;0m'");
  // Resize the terminal, and clear the terminal of text before game begins
  system("resize -s 30 80");


  gameManager* myManager = new gameManager;

  myManager->startGame();

	return 0;
}











