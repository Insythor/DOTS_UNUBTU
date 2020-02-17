#include "player.h"

player::player()
{

}

player::~player()
{
  //dtor
}

void player::levelUp()
{


}

void player::swapAbilities()
{

}


void player::addExperience(int toAdd)
{
  currentExperience += toAdd;

  if(currentExperience >= maxExperience)
  {
    levelUp();
  }

}

void player::addToStats(std::vector<int> toAdd)
{
  mainStats[0] += toAdd[0];
  mainStats[1] += toAdd[1];
  mainStats[2] += toAdd[2];
  speed += toAdd[3];
}

void player::applyStatusAffect(std::vector<int> toAdd)
{


}








