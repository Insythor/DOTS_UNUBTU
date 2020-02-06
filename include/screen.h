#ifndef SCREEN_H
#define SCREEN_H


#include <iostream>
#include <iomanip>

#include <string>
#include <vector>

//	Declarations of screen dimensions
#define DEFAULT_WIDTH 79
#define DEFAULT_HEIGHT 21
//	Width between each "pixel"
#define DEFAULT_SPACING 4


class screen
{
public:

	screen();
	~screen();

	void print();
	/**
    @brief  Add a vector<vector<char>> to the screen, starting at an X-Y location
            This function draws the shape from top-left -> bottom-right

   */
	void addToScreen(std::vector<std::vector<char>>* toAdd, int startX, int startZ);


private:

	std::vector<std::vector<char>> toRender;
	std::vector<std::vector<char>> blankScreen;

	int width;

	int height;
	int spacing;

	char brush;
	char fill;
};
#endif // SCREEN_H
