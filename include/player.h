#ifndef PLAYER_H
#define PLAYER_H
#include "baseCharacter.h"
class player : public baseCharacter
{
public:
    player();

    virtual ~player();

    void levelUp();
    void swapAbilities();
    void addExperience (int toAdd);
    //  strength, dexterity, intellect, speed
    void addToStats(std::vector<int> toAdd);
    void applyStatusAffect(std::vector<int> toAdd);

private:
    int currentExperience;
    int maxExperience;

    std::vector<ability> storedAbilities;

    std::vector<int> statusAffects;
};

#endif // PLAYER_H
