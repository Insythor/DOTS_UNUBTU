#ifndef PLAYER_H
#define PLAYER_H

#define DIR_PLAYERSAVE "../../docs/DATA/save"
#define PLAYERSAVE_EXT ".csv"

#include "baseCharacter.h"

class player : public baseCharacter
{
  public:

    // Default constructor
    player();
    /**
        @brief  Overloaded constructor (typically used) to create a new hero
    */

    player(std::string tName, std::string tRace, int tMaxHP,
                  std::vector<int> tStat);

   virtual ~player();

    /**
        @brief Overloaded class operator to add & format player information,
               then add it to the output stream
    */
    friend std::ostream& operator << (std::ostream& out, player& toRender);
    /**
      @brief
    */
    void swapAbilities();
    /**
      @brief Adds the given amount of experience to the players current experience,
             then checks if the player has enough experience to level up, and call levelup()
      @param [in] int how much experience is to be added
    */
    void addExperience(int toAdd);
    /**
        @brief  Set currentExperience to current - maxExperience, allow the user
                to select which stats they would like to add, and check if the 
                added stats will give the player an increase to their stat bonuses
                , finally, increase the players HP.
        @param Level 1: 100
        @param Level 2: 175
        @param Level 3: 250
        @param Level 4: 325
        @param Level 5: 401
        @param Level 6: 477
    */
    void levelUp();
    /**
      @brief Add to the players main stats perminantly
      @param [in] std::vector<int> [0] Strength [1] Dexterity [2] Int 
    */
    void addToStats(std::vector<int> toAdd);
    /**
      @brief
      @param [in] std::vector<int> [0] Strength [1] Dexterity [2] Int [3] Speed
    */
    void applyStatusEffect(std::vector<int> toApply, bool apply);
    /**
        @brief 
        @param[in] 
    */
    void useConsumable(unsigned int index);
    /**
        @brief return the players currentExperience and the experience they need
        to level up
        @param[out] std::vector<int> [0] = currentExperience [1] = maxExperience 
    */
    std::vector<int> getExperience();

    void save();


  private:

    int currentExperience;
    int maxExperience;

    std::vector<int> statusEffect;

};

#endif // PLAYER_H
