#ifndef ABILITY_H
#define ABILITY_H

#include <string>
#include <vector>

class ability
{
  public:
    ability();
    virtual ~ability();


 private:
   std::string name;
   std::string description;

   int cooldown;

   int diceRolls;
   int diceSize;

   std::vector<int> statRequirement;

};

#endif // ABILITY_H
