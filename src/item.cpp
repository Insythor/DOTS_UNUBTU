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

int item::getCost()
{
  return cost;
}

int item::getSellValue()
{
  return sellValue;
}
