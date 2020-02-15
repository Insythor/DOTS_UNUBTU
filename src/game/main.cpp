
#include "screen.h"

#include "dice.h"
#include "player.h"


int main()
{
	screen myScreen;

	myScreen.addToScreen(data.nextRoom(), 0, 0);

	myScreen.print();

	return 0;
}
