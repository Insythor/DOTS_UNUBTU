#include "print.h"

int print::C_WHITE [3] = {255, 255, 255};
int print::C_BLACK [3] = {0, 0, 0};
int print::C_RED [3] = {255, 0, 0};
int print::C_GREEN [3] = {0, 255, 0};
int print::C_GREEN_D [3] = {0, 175, 0};
int print::C_BLUE [3] = {0, 0, 255};
int print::C_PURPLE [3] = {150, 75, 255};
int print::C_BROWN [3] = {153, 76, 0};
int print::C_PINK [3] = {255, 102, 255};


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

void print::str_colour(std::string toPrint, int colour[3])
{
    std::string bgColour = "printf '\e[38;2;";
    bgColour.append(std::to_string(colour[0]) + ";");
    bgColour.append(std::to_string(colour[1]) + ";");
    bgColour.append(std::to_string(colour[2]) + "m '");

    char sysCommand[bgColour.length()];

    strcpy(sysCommand, bgColour.c_str());

    system(sysCommand);

    str(toPrint);

    system(DEFAULT_COLOUR);
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
