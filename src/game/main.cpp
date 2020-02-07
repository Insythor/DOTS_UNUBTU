
#include "screen.h"
#include "dataManager.h"
#include "dice.h"
#include "player.h"


int main()
{
	screen myScreen;
  dataManager data;

	myScreen.addToScreen(data.nextRoom(), 0, 0);

	myScreen.print();

	return 0;
}
