#include "consumable.h"
#include <vector>


consumable::consumable(int tid)
{
  id = tid;
}

consumable::~consumable()
{

}

int consumable::getID()
{
  return id;
}

/*
0 strength    mainStats[0]
1 dexterity   mainStats[1]
2 intellect   mainStats[2]
3 speed
*/
/*
void consumable::use(player* p)
{
  std::vector<int>stats;

  // assign value to stats
  for(int i=0; i<4; ++i)
  {
    if(i == statToAdd)
      stats.push_back(statValue);
    else
      stats.push_back(0);
  }
  //add stats to player
  p->addToStats(stats);
  //destroyConsumable(p);
}
*/













