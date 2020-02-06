#pragma once

#include <cstdlib>
#include <time.h>


class Dice
{
public:
	
	Dice();
	Dice(int nSides);
	
	~Dice();

//	int roll();


private:
	int sides;

	unsigned int* seed;
};

