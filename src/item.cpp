#include "item.h"

item::item()
{
    name = "n\a";
    cost = -1;
    sellValue = -1;
}

item::~item()
{
  //dtor
}
const std::string& item::getName()
{
  return name;
}

const int& item::getCost()
{
  return cost;
}

const int& item::getSellValue()
{
  return sellValue;
}
