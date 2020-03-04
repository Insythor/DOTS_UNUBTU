#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#define DIR_CONSUMABLE "../docs/DATA/consumableData.csv"

// User Defined
#include "item.h"
// Constainers
#include <vector>
// I/O
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

class consumable : public item
{
  public:
    /**
      @brief Create a random consumable.
    */
    consumable();
    /**
        @brief Sets index and reads in that line from the docs/DATA/consumableData.csv.
               If an in valid number was given, the consumable will default to a bandage.
    */
    consumable(int cid);
    ~consumable();
    friend std::ostream& operator << (std::ostream& out, consumable &toRender);
    /**
      @brief Return the index of the csv that this consumable was generated from
      @param[out] [int] index
    */
    int getID();
    /**
        @brief return the stat to add, and how much is to be added
        @param[out] std::vector<int>[0] Stat to add
        @param[out] std::vector<int>[1] Quantity to add
    */
    std::vector<int> statsToAdd();
    /**
        @brief Returns if this consumable gives the player a permanent buff
        @param[out] [bool] Book?
    */
    bool getIsPerminant();

    /**
      @brief Last index in the consumables.csv
             Used as a mod in default constructor
    */
    const static int lastIndex = 8;

  private:


    int index;
    std::vector<int> stats;
    bool isPermanent;
    std::string description;

    /**
        @brief Reads a line from the consumableData.csv, and makes tha type of consumable
    */
    void readInConsumableData();

};

#endif // CONSUMABLE_H
