
/**
  DEBUGGING MAIN CURRENTLY IN USE BY TYLER FOR TESTING THINGS


*/

#include "gameManager.h"
#include "print.h"

#include <iostream>

int main()
{

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











