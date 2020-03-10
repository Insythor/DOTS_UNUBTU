#ifndef PRINT_H
#define PRINT_H

#define DEFAULT_MOD 100
#define DEFAULT_COLOUR "printf '\e[38;2;200;200;200m'"

// Containters
#include <vector>
#include <string>
#include <cstring>
// I/O
#include <iostream>
#include <ostream>
// For sleep
#include <chrono>
#include <random>
#include <thread>

/**
  @brief This is a very rough class atm, it's jank to be honest...
          BUT you can print strings like they're being typed by a "person"
          Change the colour of the text or the 'typing' speed

          To access a colour for any of the functions, call print::C_'somecolour'
          i.e. print::str_colour(string toPrint, print::C_WHITE);

*/

class print
{
  public:
    // I guess?
    /**
      @brief access with print::C_
    */
    static int C_WHITE [3];
    static int C_BLACK [3];
    static int C_RED [3];
    static int C_GREEN [3];
    static int C_GREEN_D [3];
    static int C_BLUE [3];
    static int C_PURPLE [3];
    static int C_BROWN [3];
    static int C_PINK [3];

    static int C_DEFAULT [3];


    /**
      @brief Print out the string every few milliseconds, so it looks
             like the text is being typed to the screen
    */
    static void str(std::string toPrint);

    static void str_colour(std::string toPrint, int colour[3]);

    static void str_time_colour(std::string toPrint,
                                int maxMillis, int colour[3]);
    /**
      @brief Print out the string one char at a time every x milliseconds
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

    static void vec_time(std::vector<std::string> toPrint, int maxMillis);

    static void textColour(int colour[3]);

    static void setCursor(bool box);
    static void initScreen();

};


#endif // PRINT_H
