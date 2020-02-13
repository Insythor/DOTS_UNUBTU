#ifndef DICE_H
#define DICE_H



#include <cstdlib>
#include <time.h>


class dice
{
public:

	dice();
	dice(int nSides);

	~dice();

	int roll();


private:
	int sides;


};

#endif // DICE_H
