#include "gtest/gtest.h"
#include "chest.h"

TEST(testChest, constructorTest)
{
  chest c(5);

  //testing for inventory?
  EXPECT_TRUE(c.getGold() >= 1 || c.getGold() <= 100);

}

TEST(testChest, lootGoldTest)
{
  chest c(2);

  EXPECT_TRUE(c.getGold() >= 1 || c.getGold() <= 100);
  c.lootGold();
  EXPECT_TRUE(c.getGold() == 0);
}

TEST(testChest, getInventoryTest)
{
  //needs to do this still
}

TEST(testChest, getGoldTest)
{
  //need to do this still
}
