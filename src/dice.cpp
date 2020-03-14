#include "dice.h"

dice::dice()
{
	sides = 6;
  srand(time(NULL));
}

dice::dice(int nSides)
{
	sides = nSides;
	srand(time(NULL));
}

dice::~dice()
{

}

const int& dice::getSides()
{
  return sides;
}

int dice::roll()
{
	return (rand() % sides) + 1;
}

int dice::roll(int nRolls)
{
  int carry = 0;
  for(int i = 0; i < nRolls; i++)
  {
    carry += (rand() % sides) + 1;
  }
	return carry;
}





