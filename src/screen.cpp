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
		}
		std::cout << std::endl;
	}
}

void screen::addToScreen(std::vector<std::vector<char>>* toAdd,
                                        int startX, int startY)
{
	for (unsigned int row = 0; row < (*toAdd).size(); row++)
	{
		for (unsigned int col = 0; col < (*toAdd)[0].size(); col++)
		{
			toRender[row + startY][col + startX] = (*toAdd)[row][col];
		}
	}
//	delete toAdd;
}

void screen::addToScreen(std::vector<std::vector<char>>* toAdd)
{
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			toRender[row][col] = (*toAdd)[row][col];
		}
	}
//	delete toAdd;
}
