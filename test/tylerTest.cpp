
/**
  DEBUGGING MAIN CURRENTLY IN USE BY TYLER FOR TESTING THINGS


*/

#include "gameManager.h"
#include "print.h"

#include <iostream>

int main()
{

  // Resize the terminal, and clear the terminal of text before game begins
  system("resize -s 32 80");
  // Set the background to black
  system("printf '\e[48;2;0;0;0m'");
  system("printf '\e[38;2;200;200;200m'");
  system("clear");
  print::setCursor(false);

/*
Where x takes a value from 1 to 6 (from xterm manual):

    0 -> blinking block.
    1 -> blinking block (default).
    2 -> steady block.
    3 -> blinking underline.
    4 -> steady underline.
    5 -> blinking bar (xterm).
    6 -> steady bar (xterm).

And the colour can be set with:
*/
// print::str_colour("Testaroonie", print::C_PURPLE);

  gameManager* myManager = new gameManager;

  myManager->startGame();

	return 0;
}











