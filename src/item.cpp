#include "item.h"

item::item()
{
  //ctor
}

item::~item()
{
  //dtor
}
std::string item::getName()
{
  return name;
}

std::string item::getDescription()
{
  return description;
}

int item::getCost()
{
  return cost;
}

int item::getSellValue()
{
  return sellValue;
}
