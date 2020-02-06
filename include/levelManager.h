#pragma once


#include <vector>
#include <string>


class levelManager
{
public:
	levelManager();
	~levelManager();

	void importRooms();

	std::vector<std::vector<char>>* nextRoom(int roomType);


private:


};

