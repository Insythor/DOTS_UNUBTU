#include "combatManager.h"

combatManager::combatManager(player* p, monster* m)
{
    fightOrder = new baseCharacter* [2];

    if (p->getStats()[3] >= m->getStats()[3])
        playersTurn = true;
    else
        playersTurn = false;
    // Monster
    fightOrder[0] = m;
    // Player
    fightOrder[1] = p;
}

combatManager::~combatManager()
{
    delete[] fightOrder;
}

void combatManager::startFight()
{
    // Debugging
    bool forceQuit = true;
    //

    int tempDamage = 0;
    // Start of combat text formatting
    if (playersTurn)
    {

        std::cout << "\nCOMBAT HAS BEGUN!!!\n" << fightOrder[playersTurn]->getName() +
            "'s faster than the " + fightOrder[!playersTurn]->getRace() << "\nWhat's your first move? ";
    }
    else
    {
        std::cout << "\nCOMBAT HAS BEGUN!!!\n" << "A " + fightOrder[!playersTurn]->getRace() + 
                    " has gotten the first attack against you!" << std::endl;
    }
    
    // forceQuit if for debugging
    while (!checkCombatDone() && forceQuit)
    {
        // dummy variables to consume user input
        std::string command;
        std::vector<int> input;

        if (playersTurn)
        {
            std::cin >> command;
            input = formatCommand(command);
        }
        else
        {
            input.push_back(1);
        }

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
            // So printing won't cost you the turn
            playersTurn = !playersTurn;
            break;
        // pm, printMonster
        case 13:
            // Print the basic character information for the monster
            std::cout << *fightOrder[0] << std::endl;
            playersTurn = !playersTurn;
            break;

        case 0:
            forceQuit = false;
            break;
            
        case -1:
            std::cout << "\n"
                << "atk:        Attack the monster with your weapon.\n"
                
                
                << "\n\n                   DEBUGGING"  
                << "\n**************************************************\n"

                << "pp:         Display the basic details of your hero.\n" 
                << "pm:         Display the basic details of the monster.\n"

                << std::endl;
            break;

        default:
            std::cout << "Invalid command. Type 'Help' for all available commands\n" << std::endl;
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


    else if (tempCommand[0] == "Loot" || tempCommand[0] == "loot")
        temp.push_back(20);

    // Print the player
    else if (tempCommand[0] == "pPlayer" || tempCommand[0] == "pp")
        temp.push_back(12);
    // Print the monster
    else if (tempCommand[0] == "pMonster" || tempCommand[0] == "pm")
        temp.push_back(13);

    else if (tempCommand[0] == "Exit" || tempCommand[0] == "exit")
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
        
        //  *** Arbitrary amout of experience for the player to gain when they killed the monster ***
        
        int monsterXP =  (*dynamic_cast<player*> (fightOrder[1])).getExperience()[1] / 3 
                                               + (fightOrder[0]->getMaxHealth() * 0.2);

        dynamic_cast<player*> (fightOrder[1])->addExperience(monsterXP);
        // First line draws a bar of '*' to seperate the combat phase from the end of combat
        std::cout << "\n" << std::setfill('*') << std::setw(50) << "\n\n" << std::setfill(' ')
            << "Congratulations " + fightOrder[playersTurn]->getName() + "! You were victorious over the "
            << fightOrder[!playersTurn]->getRace() << ".\n"
            << "Defeating the monster has granted you " << monsterXP << " experience.\n Here's how "
            << fightOrder[1]->getName() << " is looking after that fight.\n"
            << *dynamic_cast<player*> (fightOrder[1]) << "\n"
            << "Type 'Loot' to see if the monster has any loot\n"

            << std::endl;

        int input;
        bool monsterLooted = false;
        std::string command;
        std::cin >> command;

        input = formatCommand(command)[0];

        switch (input)
        {
        case 20:
            // Insert looting here 
            break;

        case 0:
            if (!monsterLooted)
            {
                std::cout
                    << "\nOnce you leave the monster encounter, the loot will still be available until you leave the room.\n"
                    << "However, if there is another monster in this room that you haven't found yet, this monsters loot "
                    << "will be taken back into the spire as sacrifice.\nAnd will be gone forever.\n"
                    << "Are you sure there's no more monsters in the room? ";

                std::cin >> command;
                if (command == "Yes" || command == "yes" || command == "y")
                    break;
                else
                {
                    // loop back to looting function
                }
            }
            break;
        }
    }
    // We should create a gameOver state. And call it here
    else
    {
        
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