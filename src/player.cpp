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

void player::addGold(int toAdd)
{
  gold += toAdd;
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
  strength += toAdd[0];
  dexterity += toAdd[1];
  intellect += toAdd[2];
  speed += toAdd[3];
}

void player::applyStatusAffect(std::vector<int> toAdd)
{


}








