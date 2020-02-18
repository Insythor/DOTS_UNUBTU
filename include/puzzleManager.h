#ifndef PUZZLEMANAGER_H
#define PUZZLEMANAGER_H


#include <vector>


class puzzleManager
{
  public:
    puzzleManager();
    ~puzzleManager();

  private:
    static std::vector<int> puzzlesLeft;
};

#endif // PUZZLEMANAGER_H
