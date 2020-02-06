#ifndef SHAPEMAKER_H
#define SHAPEMAKER_H


#include <string>
#include <vector>

class shapeMaker
{
public:

	// Default Constructor
	shapeMaker();
	// Overloaded Constructors
	shapeMaker(int h, int w, char b, char bf, char s, bool fill);
	shapeMaker(int h, int w, char b, char bf, char s, int t, bool f);

	// Destructor
	~shapeMaker();

	// Select a shape to be drawn on the screen, and how big it is
	// Centre of the shape == ((height / 2) + 1))

	const std::vector<std::vector<char>>* makeShape(char makeShape, int w, int h);

	void resize(int w, int h);


private:


	void square();
	void column();

	char shape = 's';
	char brush = '*';
	char fillBrush = ' ';

	int width = 0;
	int height = 0;
	int thickness;

	bool fill = false;

	std::vector<std::vector<char>>* shapeInfo;
};

#endif // SHAPEMAKER_H
