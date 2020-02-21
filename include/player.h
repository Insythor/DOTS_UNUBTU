#ifndef PLAYER_H
#define PLAYER_H

#include "baseCharacter.h"

class player : public baseCharacter
{
  public:
    player();
    player(std::string tName, std::string tRace, int tMaxHP,
                  std::vector<int> tStat);


    friend std::ostream& operator << (std::ostream& out, player& toRender);


    ~player();

    /**
      @brief
    */
    void swapAbilities();
    /**
      @brief
      @param [in] int how much experience is to be added
    */
    void addExperience(int toAdd);
    /**
      @brief
    */
    void checkForLevelUp();
    /**
        @brief
    */
    void levelUp();
    /**
      @brief
      @param [in] std::vector<int> [0] Strength [1] Dexterity [2] Int [3] Speed
    */
    void addToStats(std::vector<int> toAdd);
    /**
      @brief
      @param [in] std::vector<int> [0] Strength [1] Dexterity [2] Int [3] Speed
    */
    void applyStatusEffect(std::vector<int> toApply);
    /**
      @brief Overwrites the players equiped weapon with a new weapon at random
      @param [in] int for level of weapon to generate
    */

    void spawnWeapon(int level, std::vector<std::string>* weaponNames);


    void spawnWeapons(int index);
    void useConsumable(unsigned int index);


  private:

    int currentExperience;
    int maxExperience;

    std::vector<int> statusEffect;
};

#endif // PLAYER_H
