#ifndef DICE_H
#define DICE_H

#include <random>
#include <time.h>

class dice
{
public:

	dice();
	dice(int nSides);

	~dice();
  /**
    @brief Roll the dice a single time
    @param[out] int roll = rand(1, sides)
  */
	int roll();
	/**
    @brief Roll the dice n time(s).
    @param[in] int how many times the die is being rolled.
    @param[out] int roll = rand(1, sides).
  */
  int roll(int nRolls);
  int getSides();
private:
	int sides;


};

#endif // DICE_H
