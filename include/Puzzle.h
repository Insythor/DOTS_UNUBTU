/**
    @author
    @brief
*/

#ifndef PUZZLE_H
#define PUZZLE_H
#include <string>

class Puzzle {
 public:
  Puzzle();
  virtual ~Puzzle();

 protected:
  /**
   *  @brief  title of the puzzle
   */
  std::string PUZZLE_TITLE;

  /**
   *  @brief  character in the room
   */
  std::string ROOM_CHARACTER;

  /**
   *  @brief  displays the title and the instruction
   *          of the puzzle
   */
  virtual void displayStartingMessage() = 0;

  /**
   *  @brief  displays what the player can get or lose
   *          once the puzzle is completed
   */
  virtual void displayConsequence() = 0;

  /**
   *  @brief  displays the goal of the puzzle
   */
  virtual void displayGoal() = 0;

  /**
   *  @brief  the game proper
   */
  virtual void mainGame() = 0;

  /**
   *  @brief  determine if player successfully completes the puzzle
   *  @return true if it's successful, otherwise false
   */
  virtual bool getResult() {
    return result;
  }

 private:
  bool result = false;
};

#endif // PUZZLE_H
