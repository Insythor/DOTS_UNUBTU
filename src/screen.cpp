#include "screen.h"


screen::screen()
{
	width = DEFAULT_WIDTH;
	height = DEFAULT_HEIGHT;
	spacing = DEFAULT_SPACING;

	brush = '*';
	fill = ' ';

	for (int y = 0; y < height; y++)
	{
		blankScreen.push_back(std::vector<char>());

		for (int x = 0; x < width; x++)
		{
			blankScreen[y].push_back(fill);
		}
	}
	toRender = blankScreen;
}

screen::~screen()
{

}



void screen::print()
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			std::cout << toRender[y][x];
			// Makes sure that setw is not called on the last char of each row
			// so that column 0 lines up
		//	if (x < width - 1)
			{
		//		std::cout << std::setw(spacing);
			}
		}
		std::cout << std::endl;
	}
}

void screen::addToScreen(const std::vector<std::vector<char>>* toAdd, int startX, int startY)
{
//	std::cout << (*toAdd).size() << "  " << toAdd[0].size() << "\n";

	for (unsigned int row = 0; row < (*toAdd).size(); row++)
	{
		for (unsigned int col = 0; col < toAdd[0].size(); col++)
		{
			toRender[row + startY][col + startX] = (*toAdd)[row][col];
		}
	}
	delete toAdd;
}
