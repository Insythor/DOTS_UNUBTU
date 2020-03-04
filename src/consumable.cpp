#include "consumable.h"

consumable::consumable()
{
    srand(time(NULL));
    index = rand() % lastIndex;
    readInConsumableData();
}

consumable::consumable(int tid)
{
    if (tid <= lastIndex)
    {
        index = tid;

    }
    else
        index = 0;

    readInConsumableData();
}

consumable::~consumable()
{

}


std::ostream& operator << (std::ostream& out, consumable& toRender)
{
    std::string stat;

    switch (toRender.stats[0])
    {
    case 0:
        stat = "Strength";
        break;
    case 1:
        stat = "Dexterity";
        break;
    case 2:
        stat = "Intellect";
        break;
    case 3:
        stat = "Speed";
        break;
    case 4:
        stat = "Health";
        break;
    }

    out << toRender.index << "   " << toRender.name << ": + "
        << toRender.stats[1] << " " << stat << std::setw(10 - stat.length())
        << " Costs " << toRender.cost << std::setw(10)
        << " Sells for: " << toRender.sellValue << "\n"
        << "    " << toRender.description

        << std::endl << std::endl;

 return out;
}

int consumable::getID()
{
  return index;
}

std::vector<int> consumable::statsToAdd()
{
    return stats;
}

bool consumable::getIsPerminant()
{
    return isPermanent;
}


void consumable::readInConsumableData()
{
    std::ifstream toRead;

    toRead.open(DIR_CONSUMABLE);

    std::vector<std::string> tempData;
    std::string line;

    int lineCount = 0;

    if (toRead.is_open())
    {
        while (getline(toRead, line))
        {
            if (lineCount == index)
            {
                std::stringstream parsedText(line);
                while (getline(parsedText, line, ','))
                {
                    tempData.push_back(line);
                }
                break;
            }
            lineCount++;
        }
        toRead.close();
    }

    index = std::stoi(tempData[0]);
    name = tempData[1];
    stats.push_back(std::stoi(tempData[2]));
    stats.push_back(std::stoi(tempData[3]));
    isPermanent = std::stoi(tempData[4]);
    cost = std::stoi(tempData[5]);
    sellValue = std::stoi(tempData[6]);
    description = tempData[7];

}













