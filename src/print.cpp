#include "print.h"

void print::str(std::string toPrint)
{
  for(auto c : toPrint)
  {
    std::cout.flush() << c;
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % DEFAULT_MOD));
  }
  std::cout << std::endl;
}

void print::str_time(std::string toPrint, int maxMillis)
{
    for(auto c : toPrint)
  {
    std::cout.flush() << c;
    std::this_thread::sleep_for(std::chrono::milliseconds(maxMillis));
  }
  std::cout << std::endl;
}

void print::vec(std::vector<std::string> toPrint)
{
  for(auto l : toPrint)
  {
    for(auto c : l)
    {
      std::cout.flush() << c;
      std::this_thread::sleep_for(std::chrono::milliseconds(rand() % DEFAULT_MOD));
    }
      std::cout << std::endl;
  }
}

void print::vec_faster(std::vector<std::string> toPrint, bool increase)
{
  int mod = DEFAULT_MOD;
  int lineCounter = -1;

    for(auto l : toPrint)
    {
      lineCounter++;
      if(lineCounter % (toPrint.size() /5) == 0)
        mod *= 0.8;
      for(auto c : l)
      {
        std::cout.flush() << c;
       if(c != ' ')
          std::this_thread::sleep_for(std::chrono::milliseconds(rand() % mod));
      }
      std::cout << std::endl;
  }
}
