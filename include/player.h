#ifndef PLAYER_H
#define PLAYER_H

#include "baseCharacter.h"

class player : public baseCharacter
{
  public:
    player(std::string tName, std::string tRace, int tMaxHP,
                  std::vector<int> tStat);
    ~player();
    /**
      @brief
    */
    void swapAbilities();
    /**
      @brief
      @param [in] int
    */
    void addExperience(int toAdd);
    /**
      @brief
    */
    void checkForLevelUp();
    /**
        @brief
    */
    void leveUp();
    /**
      @brief
      @param [in] std::vector<int>
    */
    void addToStats(std::vector<int> toAdd);
    /**
      @brief
      @param [in] std::vector<int>
    */
    void applyStatusEffect(std::vector<int> toApply);
    /**
      @brief
      @param [in] int
    */
    void spawnWeapons(int index);
    void useConsumable(unsigned int index);

  private:

    int currentExperience;
    int maxExperience;
    std::vector<ability*> storedAbilities;

    std::vector<int> statusEffect;
};

#endif // PLAYER_H
