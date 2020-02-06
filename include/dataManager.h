#pragma once

#include "room.h"

// directory definitions
#define ROOM_DEFAULT "docs/DATA/rooms/default.txt"
#define ROOM_BOSS "docs/DATA/rooms/0Boss/boss"
#define ROOM_CHEST "docs/DATA/rooms/1Chest/chest"
#define ROOM_MONSTER "docs/DATA/rooms/2monster"
#define ROOM_SHOP "docs/data/rooms/3Shop/shop"
// file extension of all rooms is a .txt
#define FILE_EXTENSION ".txt"

#include <fstream>
#include <vector>
#include <string>
#include <iostream>

class dataManager
{
public:
	dataManager();
	~dataManager();

	std::vector<std::vector<char>>* nextRoom();

private:

};

