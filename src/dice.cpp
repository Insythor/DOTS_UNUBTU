#include "dice.h"

dice::dice()
{
	sides = 6;

	seed = new unsigned int;
	*(seed) = time(0);
}

dice::dice(int nSides)
{
	sides = nSides;

	seed = new unsigned int;
	*(seed) = time(0);
}

dice::~dice()
{
	delete seed;
}

int dice::roll()
{
	unsigned int temp;

	temp = (rand_r(seed) % sides) + 1;

	return temp;
}
