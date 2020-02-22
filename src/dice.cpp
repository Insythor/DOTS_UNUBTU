#include "dice.h"

dice::dice()
{
	sides = 6;
    srand(time(NULL));
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

  int temp = rand() % sides;
  temp++;

	return temp;
}
#include <iostream>
int dice::roll(int nRolls)
{
  int carry = 0;


  for(int i = 0; i < nRolls; i++)
  {
    int temp = rand() % sides;
    temp++;

    carry += temp;
  }

	return carry;
}





