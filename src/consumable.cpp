#include "consumable.h"
#include <vector>

consumable::consumable()
{
    //for randomID
}

consumable::consumable(int tid)
{
  id = tid;
}

consumable::~consumable()
{

}

std::ostream& operator << (std::ostream& out, consumable& toRender)
{
 out <<
 std::endl;
 return out;
}

int consumable::getID()
{
  return id;
}

int consumable::getStatToAdd()
{
    return statToAdd;
}

int consumable::getStatValue()
{
    return statValue;
}

bool consumable::getIsPerminant()
{
    return isPerminant;
}

/*
0 strength    mainStats[0]
1 dexterity   mainStats[1]
2 intellect   mainStats[2]
3 speed
*/















