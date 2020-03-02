#include "consumable.h"

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

std::vector<int> consumable::statsToAdd()
{
    return stats;
}

bool consumable::getIsPerminant()
{
    return isPerminant;
}

/*
0 strength    mainStats[0]
1 dexterity   mainStats[1]
2 intellect   mainStats[2]
3 speed       mainStats[3]
4 health      
*/















