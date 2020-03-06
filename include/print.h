#ifndef PRINT_H
#define PRINT_H

#define DEFAULT_MOD 100

// Containters
#include <vector>
#include <string>
// I/O
#include <iostream>
#include <ostream>
// For sleep
#include <chrono>
#include <random>
#include <thread>

class print
{
  public:

    /**
      @brief Print out the string every few milliseconds, so it looks
             like the text is being typed to the screen
    */
    static void str(std::string toPrint);
    /**
      @brief Print out the string every x milliseconds
    */
    static void str_time(std::string toPrint, int maxMillis);
    /**
      @brief Print the std::vector<std::string>> to the screen, one char
             at a time, and wait a small amount of time between each char
    */
    static void vec(std::vector<std::string> toPrint);
    /**
      @brief Print the std::vector<std::string>> to the screen, one char
             at a time, and wait a small amount of time between each char,
             and increase the speed as it's printed.
    */
    static void vec_faster(std::vector<std::string> toPrint, bool increase);

  protected:


  private:
};

#endif // PRINT_H
