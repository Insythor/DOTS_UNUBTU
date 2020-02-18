#include "dice.h"

dice::dice()
{
	sides = 6;

}

dice::dice(int nSides)
{
	sides = nSides;

}

dice::~dice()
{

}

int dice::getSides()
{
  return sides;
}

int dice::roll()
{
  srand(time(NULL));
  int temp = rand() % sides;
  temp++;

	return temp;
}
#include <iostream>
int dice::roll(int nRolls)
{
  int carry = 0;
  srand(time(NULL));

  for(int i = 0; i < nRolls; i++)
  {
    int temp = rand() % sides;
    temp++;

    carry += temp;
  }

	return carry;
}





