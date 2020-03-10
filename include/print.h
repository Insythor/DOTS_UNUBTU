#ifndef PRINT_H
#define PRINT_H

#define DIR_COMMANDS "../docs/DATA/commands.csv"
#define DEFAULT_MOD 10
#define DEFAULT_COLOUR "printf '\e[38;2;200;200;200m'"

// Containters
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
// I/O
#include <iostream>
#include <ostream>
#include <sstream>
// For sleep
#include <chrono>
#include <random>
#include <thread>

/**
  @brief This is a very rough class atm, it's jank to be honest...
          BUT you can print strings like they're being typed by a "person"
          Change the colour of the text or the 'typing' speed

          To access a colour for any of the functions, call print::C_'colour'
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
    /**
      @brief Call print::str, and add a colour to the text
      @param[in] std::string toPrint
      @param[in] int[3] print::C-'colour'
    */
    static void str_colour(std::string toPrint, int colour[3]);
    /**
      @brief Call print::str_time, and add a colour to the text
      @param[in] std::string toPrint
      @param[in] int maxMillis
      @param[in] int[3] print::C-'colour'
    */
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
    /**
      @brief Print the std::vector<std::string>> to the screen, one char
             at a time, and wait a small amount of time between each char,
             and increase the speed as it's printed.
    */
    static void vec_time(std::vector<std::string> toPrint, int maxMillis);
    /**
      @brief  Set the text colour
      @param[in] int[3] print::C_'colour'
    */
    static void textColour(int colour[3]);
    /**
      @brief  Sets the cursor to a box (true) or an underscore
      @param[in] bool Box?
    */
    static void setCursor(bool box);
    /**
      @brief  Screen dimensions: 31h x 80h
              Background colour: Black
              Text Colour: Light Grey
              Cursor : Underscore
    */
    static void initScreen();
    /**
      @brief
      @param[in]
    */
    static bool is_number(const std::string& s);
    /**
      @brief Fade the screen to red, hold for 3 seconds, then fade back to black
    */
    static void deathScreen();
};


#endif // PRINT_H
