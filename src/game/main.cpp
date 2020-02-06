
#include "screen.h"
#include "shapeMaker.h"
#include "dataManager.h"

#include <iostream>
#include <vector>



int main()
{
	screen myScreen;
  dataManager data;

	myScreen.addToScreen(data.nextRoom(), 0, 0);

	myScreen.print();

	return 0;
}
