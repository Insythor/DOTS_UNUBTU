#include "combatManager.h"

combatManager::combatManager(player* p, monster* m)
{
    fightOrder = new baseCharacter* [2];

    if (p->getStats()[3] >= m->getStats()[3])
        playersTurn = true;
    else
        playersTurn = false;

    fightOrder[0] = m;
    fightOrder[1] = p;

   
}

combatManager::~combatManager()
{
    delete[] fightOrder;
}

void combatManager::startFight()
{
    std::string firstAttacker;

    int tempDamage = 0;

    if (playersTurn)
    {
        firstAttacker = "Congratulations " + fightOrder[playersTurn]->getName() + 
            "!!! Your speed was higher than the " + fightOrder[!playersTurn]->getRace();
        std::cout << "\nCOMBAT HAS BEGUN!!!\n" << firstAttacker << std::endl; 
    }
    else
    {
        firstAttacker = "The " + fightOrder[!playersTurn]->getRace() + " is already attacking you!!! ";
        std::cout << "\nCOMBAT HAS BEGUN!!!\n" << firstAttacker << std::endl;
    }
    
    bool forceQuit = true;
    while (!checkCombatDone() && forceQuit)
    {
       

        std::string command;
        std::vector<int> input;

        if (playersTurn)
        {
            // Print basic character information
           // std::cout << *fightOrder[playersTurn] << std::endl;
            
            std::cin >> command;
            input = formatCommand(command);

        }
        else
        {
            input.push_back(1);
        }

        /*for (auto i : input)
            std::cout << i << std::endl;*/

        switch (input[0])
        {
        // Attack with base weapon
        case 1:
            tempDamage = fightOrder[playersTurn]->dealDamage();
            fightOrder[!playersTurn]->takeDamage(tempDamage);

            std::cout << fightOrder[playersTurn]->getName() << " dealt " << tempDamage
                << " to " << fightOrder[!playersTurn]->getName() <<std::endl;
            break;

        // pp, printPlayer
        case 12:
            // Print the basic character information for the player
            std::cout << *fightOrder[1] << std::endl;  
            //  std::cout << *dynamic_cast<player*> (fightOrder[1]) << std::endl; // detailed
            // So printing won't cost you the turn
            playersTurn = !playersTurn;
            break;
        // pm, printMonster
        case 13:
            // Print the basic character information for the monster
            std::cout << *fightOrder[0] << std::endl;
            // std::cout << *dynamic_cast<monster*> (fightOrder[0]) << std::endl; // detailed
            playersTurn = !playersTurn;
            break;

        case 0:
            forceQuit = false;
            break;
            

        default:
            std::cout << "Invalid command. Type 'Help' for all available commands\n" << std::endl;;
            break;
        }
        // Flip-Flop turns
        playersTurn = !playersTurn;
    }
    // Set the turn back to who the winner of the fight was
    playersTurn = !playersTurn;
    endFight();
}

std::vector<int> combatManager::formatCommand(std::string command)
{
    std::vector<int> temp;
    std::vector<std::string> tempCommand;
    std::string parsed;
    std::stringstream parser(command);

    while (getline(parser, parsed, ' '))
    {
        tempCommand.push_back(parsed);
    }
    
    if (tempCommand[0] == "attack" || tempCommand[0] == "atk")
        temp.push_back(1);


    // Print the player
    else if (tempCommand[0] == "pPlayer" || tempCommand[0] == "pp")
        temp.push_back(12);
    // Print the monster
    else if (tempCommand[0] == "pMonster" || tempCommand[0] == "pm")
        temp.push_back(13);

    else if (tempCommand[0] == "exit")
        temp.push_back(0);

    else
        temp.push_back(-1);
   
    // Get rid of the command string once it's been formatted
  //  tempCommand.erase(tempCommand.begin());

    // Push back all the type numbers that the player entered in their command
    //for (auto i : tempCommand)
    //    temp.push_back(std::stoi(i));

    return temp;
}

std::string combatManager::selectAction(int type, int subType)
{
  type *= -1;
  subType *= -1;
  return "n\a";
}

std::string combatManager::endFight()
{
    if (playersTurn)
    {
        std::cout << "Congratulations " + fightOrder[playersTurn]->getName() + " you were victorious over the "
            << fightOrder[!playersTurn]->getName()

            << std::endl;
    }

  return "n\a";
}

std::string combatManager::monsterAction()
{
  return "n\a";
}

bool combatManager::checkCombatDone()
{
    if (fightOrder[0]->isDead() || fightOrder[1]->isDead())
    {
        return true;
    }

    else 
        return false;
}