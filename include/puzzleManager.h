#ifndef PUZZLEMANAGER_H
#define PUZZLEMANAGER_H


#include <vector>


class puzzleManager
{
  public:
    puzzleManager();
    virtual ~puzzleManager();

  private:
    static std::vector<int> puzzlesLeft;
};

#endif // PUZZLEMANAGER_H
