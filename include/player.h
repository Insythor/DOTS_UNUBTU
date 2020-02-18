#ifndef PLAYER_H
#define PLAYER_H

#include "baseCharacter.h"

class player : public baseCharacter
{
  public:

    player();
    player(std::string n, std::string r, std::vector<int> mainS, int spd);
    virtual ~player();

    void levelUp();
    void swapAbilities();
    void addExperience (int toAdd);
    //  strength, dexterity, intellect, speed
    void addToStats(std::vector<int> toAdd);
    void applyStatusAffect(std::vector<int> toAdd);
    void swapWeapons(int index);
private:
    int currentExperience;
    int maxExperience;

    std::vector<ability> storedAbilities;

    std::vector<int> statusAffects;
};

#endif // PLAYER_H
