
#include "screen.h"
#include "shapeMaker.h"
#include "dataManager.h"
#include "dice.h"



int main()
{
	screen myScreen;
  dataManager data;

	myScreen.addToScreen(data.nextRoom(), 0, 0);

	myScreen.print();

	dice myDice;

  std::cout << myDice.roll();

	return 0;
}
