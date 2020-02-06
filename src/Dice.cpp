#include "Dice.h"

Dice::Dice()
{
	sides = 6;
	
	seed = new unsigned int;
	*(seed) = time(0);
}

Dice::Dice(int nSides)
{
	sides = nSides;
	
	seed = new unsigned int;
	*(seed) = time(0);
}

Dice::~Dice()
{
	delete seed;
}

//int Dice::roll() 
//{
//	unsigned int temp;
//
//	temp = rand_r(seed);
//
//	return temp;
//}