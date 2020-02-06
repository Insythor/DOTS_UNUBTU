#include "dataManager.h"

dataManager::dataManager()
{

}
dataManager::~dataManager()
{

}

//	How should we select which room comes next???
std::vector<std::vector<char>>* dataManager::nextRoom()
{
	std::string directory;
	std::ifstream newRoom;
	std::string line;

	int counter = 0;
	int row = 0;

	//switch (roomType)
	//{
	//case 0:
	//	directory = ROOM_BOSS;
	//	break;

	//case 1:
	//	directory = ROOM_CHEST;
	//	break;

	//case 2:
	//	directory = ROOM_MONSTER;
	//	break;

	//case 3:
	//	directory = ROOM_SHOP;
	//	break;

	//default:
	//	directory = ROOM_MONSTER;
	//	break;
	//}

	std::vector<std::vector<char>>* temp;
	temp = new std::vector<std::vector<char>>;

//  directory = ROOM_DEFAULT;

  directory = "docs/DATA/rooms/default.txt";

	newRoom.open(directory);

	if (newRoom.is_open())
	{
		while (getline(newRoom, line))
		{
			temp->push_back(std::vector<char>());
			for (unsigned int i = 0; i < line.length(); i++)
			{
				temp[row][i].push_back(line[i]);
			}
			row++;
		}
		newRoom.close();
	}
	return temp;
}
