#ifndef PUZZLEMANAGER_H
#define PUZZLEMANAGER_H
#include "player.h"
#include <vector>
class puzzleManager
{
  public:
    puzzleManager(myPlayer player*);
    ~puzzleManager();
    void
  private:
    player* myPlayer;
    static vector<int> puzzlesLeft;
};

#endif // PUZZLEMANAGER_H
