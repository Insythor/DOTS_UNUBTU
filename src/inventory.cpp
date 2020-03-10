#include "inventory.h"

inventory::inventory() {
  inventorySize = 10;
  for (int i = 0; i < 9; i++) {
    std::vector<consumable*> tempvec;
    consumableStacks.push_back(tempvec);
  }
}

inventory::~inventory() {
  for (std::vector<consumable*> i : consumableStacks) {
    for (consumable* j : i) {
      delete j;
    }
    i.clear();
  }
  for (weapon* i : weapons) {
    delete i;
  }
  weapons.clear();
  for (ability* i : abilities) {
    delete i;
  }
  abilities.clear();
}

int inventory::getInventorySize() {
  return inventorySize;
}
std::string inventory::formatIndex(std::string index) {
  while (index.length() < 7) {
    if (index.length() < 7)
      index = " " + index;
    if (index.length() < 7)
      index = index + " ";
  }
  return index;
}

void inventory::viewInventory() {
  int index = 0;
  if (weapons.size() > 0) {
    std::cout << "\nWeapon's\n"
              << "| index |             name              |  stat req | lvl req | damage | price |\n"
              << "--------------------------------------------------------------------------------\n";
    for (weapon* i : weapons) {
      index++;
      std::cout << "|" << formatIndex(std::to_string(index)) << *i << std::endl;
    }
  }
  if (consumableStacks[0].size() > 0 || consumableStacks[1].size() > 0
      || consumableStacks[2].size() > 0
      || consumableStacks[3].size() > 0 || consumableStacks[4].size() > 0
      || consumableStacks[5].size() > 0
      || consumableStacks[6].size() > 0 || consumableStacks[7].size() > 0
      || consumableStacks[8].size() > 0) {
    std::cout << "\nConsumable's\n"
              << "| index |         name          |  type  | price | amount|\n"
              << "---------------------------------------------------------\n";
    for (std::vector<consumable*> j : consumableStacks) {
      if (!j.empty()) {
        index++;
        consumable* c = j.front();
        std::cout << "|" << formatIndex(std::to_string(index)) << *c
                  << formatIndex(std::to_string(static_cast<int>(j.size())))
                   << "|" << std::endl;
      }
    }
  }
  if (abilities.size() > 0) {
    std::cout
        << "\nStored Abilities\n"
        << "---------------------------------------------------------\n";
    for (ability* k : abilities) {
      index++;
      std::cout

      << std::setw(3) << index << std::setw(15 + (k->getName().length() / 2))
      << *k

      << std::endl;
    }
  }

}


void inventory::increaseInventorySize(int amount) {
  inventorySize += amount;
}

std::vector<std::vector<consumable*>> inventory::removeAllConsumables() {
  std::vector<std::vector <consumable*>> tempvector = consumableStacks;

  for (std::vector<consumable*> i : consumableStacks) {
    i.clear();
  }
  return tempvector;
}

std::vector<weapon*> inventory::removeAllWeapons() {
  std::vector<weapon*> tmpvector = weapons;
  weapons.clear();
  return tmpvector;
}

bool inventory::checkForRoom(unsigned int amountToAdd) {
  int counter = amountToAdd;
  for (std::vector<consumable*> i : consumableStacks) {
    counter += i.size();
  }
  counter += weapons.size();
  if (counter > inventorySize) {
    return false;
  } else {
    return true;
  }
}

bool inventory::deleteConsumables(unsigned int index, unsigned int amount) {
  // to stop the compiler from giving warning
  if (consumableStacks.size() > index) {
    if (consumableStacks[index].size() < amount) {
      amount = consumableStacks[index].size();
    }
    for (int i = amount; i <= 0; i--) {
      delete consumableStacks[index].front();
      consumableStacks[index].erase(consumableStacks[index].begin());
    }
    return true;
  }
  return false;
}

bool inventory::deleteWeapon(unsigned int index) {
  if (weapons.size() > index) {
    delete weapons[index];
    weapons.erase(weapons.begin() + index);
    return true;
  }
  /// temp
  return false;
}

void inventory::addConsumables(std::vector<consumable*> conStack) {

  if (conStack.size() > 0) {
    int index = conStack[0]->getID();
    for (consumable* con : conStack) {
      if (con != nullptr) {
        consumableStacks[index].push_back(con);
      }
    }
  }
}


std::vector<consumable*> inventory::removeConsumables(unsigned int index,
    unsigned int amount) {
  std::vector<consumable*> tempvector;
  if (consumableStacks.size() > index) {
    if (consumableStacks[index].size() < amount) {
      amount = consumableStacks[index].size();
    }
    for (int i = amount; i <= 0; i--) {
      tempvector.push_back(consumableStacks[index].front());
      consumableStacks[index].erase(consumableStacks[index].begin());
    }
  }
  return tempvector;
}


weapon* inventory::removeWeapon(unsigned int index) {
  weapon* tempweapon = new weapon;
  if (weapons.size() > index) {
    tempweapon = weapons[index];
    weapons.erase(weapons.begin() + index);
  }
  return tempweapon;
}

void inventory::addWeapon(weapon* wpnToAdd) {
  if (wpnToAdd != nullptr) {
    weapons.push_back(wpnToAdd);
  }
}

void inventory::addAbility(ability* abilityToAdd) {
  if (abilityToAdd != nullptr) {
    abilities.push_back(abilityToAdd);
  }
}

ability* inventory::removeAbility(unsigned int index) {
  ability* tempability = new ability;
  if (abilities.size() > index) {
    tempability = abilities[index];
    abilities.erase(abilities.begin() + index);
  }
  return tempability;
}

std::vector<ability*> inventory::getAbilities()
{
  return abilities;
}
