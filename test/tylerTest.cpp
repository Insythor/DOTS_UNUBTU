
/**
  DEBUGGING MAIN CURRENTLY IN USE BY TYLER FOR TESTING THINGS


*/

#include "gameManager.h"

#include <iostream>

int main()
{


  // Resize the terminal, and clear the terminal of text before game begins
  system("resize -s 30 80");
  // Set the background to black
  system("printf '\e[48;2;0;0;0m'");
  system("printf '\e[38;2;200;200;200m'");
  system("clear");

  gameManager* myManager = new gameManager;

  myManager->startGame();

	return 0;
}











