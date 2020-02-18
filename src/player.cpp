#include "player.h"

player::player()
{
  //ctor
}

player::~player()
{
  //dtor
}

player::player(std::string tName, std::string tRace, int tMaxHP,
              std::vector<int> tStat)
{
  name = tName;
  race = tRace;

  maxHealth = tMaxHP;
  currentHealth = maxHealth;

  mainStats = tStat;

  equippedWeapon = new weapon;
}

void player::swapAbilities()
{

}

void player::addExperience(int toAdd)
{
  toAdd *= -1;
}

void player::leveUp()
{

}

void player::addToStats(std::vector<int>toAdd)
{
  toAdd.clear();
}

void player::applyStatusEffect(std::vector<int>toApply)
{
  toApply.clear();
}

void player::spawnWeapons(int index)
{
  index *= -1;
}
