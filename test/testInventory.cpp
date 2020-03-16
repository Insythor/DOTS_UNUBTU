#include "gtest/gtest.h"
#include "inventory.h"

//only needed when compiling this test seperately from testAbilities.cpp
/*
#include "gameManager.h"
gameManager* myManager = new gameManager;
*/

TEST(testInventory, constructorTest)
{
  inventory i;

  EXPECT_TRUE(i.isEmpty());
}

TEST(testInventory, viewInventoryTest)
{
  //still need this done
}

TEST(testInventory, getConsumablesTest)
{
  inventory i;
  std::vector<consumable*> c;
  consumable con;

  for(int i = 0; i < 3; i++)
    c.push_back(new consumable(i));
  i.addConsumables(c);

  for(int n = 0; n < c.size(); n++)
  {
    con =  *i.getConsumables()[0][n];
    EXPECT_EQ(c[n]->getName(), con.getName());
  }
}

TEST(testInventory, getAbilitiesTest)
{
  inventory i;
  std::vector<ability*> ab;
  ability* a;
  std::vector<ability*> atest;

  for(int n = 1; n < 6; n++)
  {
    a = new ability(n);
    ab.push_back(a);
    i.addAbility(a);
  }

  atest =  i.getAbilities();

  for(int n = 0; n < ab.size(); n++)
  {
    EXPECT_EQ(ab[n]->getName(), atest[n]->getName());
    EXPECT_EQ(ab[n]->getDescription(), atest[n]->getDescription());
    EXPECT_EQ(ab[n]->getDiceRolls(), atest[n]->getDiceRolls());
    EXPECT_EQ(ab[n]->getDiceSize(), atest[n]->getDiceSize());
    EXPECT_EQ(ab[n]->getCurrentCooldown(), atest[n]->getCurrentCooldown());
    EXPECT_EQ(ab[n]->getCooldown(), atest[n]->getCooldown());
    EXPECT_EQ(ab[n]->getStatRequirements()[0], atest[n]->getStatRequirements()[0]);
    EXPECT_EQ(ab[n]->getStatRequirements()[1], atest[n]->getStatRequirements()[1]);
    EXPECT_EQ(ab[n]->getStatRequirements()[2], atest[n]->getStatRequirements()[2]);
  }

}

TEST(testInventory, getWeaponsTest)
{
  inventory i;
  std::vector<weapon*> wb;
  weapon* w;
  std::vector<weapon*> wtest;

  for(int n = 1; n < 6; n++)
  {
    w = new weapon(n);
    wb.push_back(w);
    i.addWeapon(w);
  }

  wtest =  i.getWeapons();

  for(int n = 0; n < wb.size(); n++)
  {
    EXPECT_EQ(wb[n]->getName(), wtest[n]->getName());
    EXPECT_EQ(wb[n]->getDiceRolls(), wtest[n]->getDiceRolls());
    EXPECT_EQ(wb[n]->getDiceSize(), wtest[n]->getDiceSize());
    EXPECT_EQ(wb[n]->getStatRequirements()[0], wtest[n]->getStatRequirements()[0]);
    EXPECT_EQ(wb[n]->getStatRequirements()[1], wtest[n]->getStatRequirements()[1]);
    EXPECT_EQ(wb[n]->getStatRequirements()[2], wtest[n]->getStatRequirements()[2]);
  }

}

TEST(testInventory, addConsumablesTest)
{
  inventory i;
  std::vector<consumable*> c;
  consumable con;
  std::vector<consumable*> ctest;

  for(int i = 0; i < 5; i++)
    c.push_back(new consumable(i));

  EXPECT_TRUE(i.isEmpty());
  i.addConsumables(c);
  EXPECT_FALSE(i.isEmpty());

  //makes sure it adds consumables specifically
  for(int n = 0; n < c.size(); n++)
  {
    ctest.push_back(i.getConsumables()[0][n]);
  }

  EXPECT_FALSE(ctest.empty());
}

TEST(testInventory, addAbilityTest)
{
  inventory i;
  std::vector<ability*> ab;
  ability* a;
  std::vector<ability*> atest;

  EXPECT_TRUE(i.isEmpty());

  for(int n = 1; n < 4; n++)
  {
    a = new ability(n);
    ab.push_back(a);
    i.addAbility(a);
  }

  EXPECT_FALSE(i.isEmpty());

  //makes sure it adds abilities specifically
  atest =  i.getAbilities();

  EXPECT_FALSE(atest.empty());
}

TEST(testInventory, addWeaponTest)
{
  inventory i;
  std::vector<weapon*> wb;
  weapon* w;
  std::vector<weapon*> wtest;

  EXPECT_TRUE(i.isEmpty());

  for(int n = 1; n < 4; n++)
  {
    w = new weapon(n);
    wb.push_back(w);
    i.addWeapon(w);
  }

  EXPECT_FALSE(i.isEmpty());

  //makes sure it adds weapons specifically
  wtest =  i.getWeapons();

  EXPECT_FALSE(wtest.empty());
}

TEST(testInventory, deleteConsumablesTest)
{

}

TEST(testInventory, removeConsumablesTest)
{

}

TEST(testInventory, removeAllConsumablesTest)
{

}

TEST(testInventory, removeAbilityTest)
{

}

TEST(testInventory, deleteWeaponTest)
{

}

TEST(testInventory, removeWeaponTest)
{

}

TEST(testInventory, removeAllWeaponsTest)
{

}

TEST(testInventory, isEmptyTest)
{

}
