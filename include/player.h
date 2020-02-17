#ifndef PLAYER_H
#define PLAYER_H
#include "baseCharacter.h"
#include <string>
#include <vector>
class player : public baseCharacter
{
public:
    player(std::string name, std::string race, std::vector<int> mainstats, int speed);

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
