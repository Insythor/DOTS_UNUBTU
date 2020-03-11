/**
	@author

	@brief

*/

#ifndef SCREEN_H
#define SCREEN_H


#include <iostream>
#include <iomanip>

#include <string>
#include <vector>

//	Declarations of screen dimensions
#define DEFAULT_WIDTH 79
#define DEFAULT_HEIGHT 16
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
            This function draws the shape from top-left -> bottom-right.
    @param[in] startX: Which column will the image begin at
    @param[in] startY: Which row will the image begin on
  */
	void addToScreen(std::vector<std::vector<char>>* toAdd, int startX, int startZ);
	/**
    @brief  Add a vector<vector<char>> to the screen starting at (0,0).
  */
	void addToScreen(std::vector<std::vector<char>>* toAdd);

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
