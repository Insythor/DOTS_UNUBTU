#include "shapeMaker.h"



shapeMaker::~shapeMaker()
{
	delete shapeInfo;
}


shapeMaker::shapeMaker(int h, int w, char b, char bf, char s, bool f)
{
	height = h;
	width = w;

	brush = b;
	fillBrush = bf;
	shape = s;

	fill = f;

}

shapeMaker::shapeMaker(int h, int w, char b, char bf, char s, int t, bool f)
{
	height = h;
	width = w;
	thickness = t;

	brush = b;
	fillBrush = bf;
	shape = s;

	fill = f;
}

shapeMaker::shapeMaker()
{

}

void shapeMaker::resize(int h, int w)
{
	height = h;
	width = w;


	(*shapeInfo).clear();
	
}

const std::vector<std::vector<char>>* shapeMaker::makeShape(char makeShape, int w, int h)
{
	width = w; 
	height = h;

	switch (makeShape)
	{
	case 's':
		square();
		break;

	case 'c':
		column();
		break;

	default:
		square();
		break;
	}
	return shapeInfo;
}

//	Makes a square
void shapeMaker::square()
{
	shapeInfo = new std::vector<std::vector<char>>;

	for (int y = 0; y < height; y++)
	{
		(*shapeInfo).push_back(std::vector<char>());

		for (int x = 0; x < width; x++)
		{
			if (y == 0 || height - y == 1)
			{
				(*shapeInfo)[y].push_back(brush);
			}

			else if (x == 0 || width - x == 1)
			{
				(*shapeInfo)[y].push_back(brush);
			}

			//	Fill the shape with spaces
			else
			{
				(*shapeInfo)[y].push_back(fillBrush);
			}
		}
	}
}


void shapeMaker::column()
{
	(*shapeInfo).clear();

	for (int y = 0; y < height; y++)
	{
		(*shapeInfo).push_back(std::vector<char>());

		for (int x = 0; x <= width; x++)
		{
			if (x == width)
			{
				(*shapeInfo)[y].push_back(brush);
			}
			else
			{
				(*shapeInfo)[y].push_back(fillBrush);
			}
		}
	}
}