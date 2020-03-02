#include "combatManager.h"

combatManager::combatManager(player* p, monster* m)
{
    fightOrder = new baseCharacter* [2];
    // If the player has more, or the same, speed as the monster, the player goes first
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
    // Stores how much damage was done so it can be printed
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
            " has gotten the first attack against you!";
    }
    // Comsumes extra characters or w/e from the stream before asking the player for input
    // Was crashing without it
    std::cin.ignore();

    // forceQuit is for debugging
    while (!checkCombatDone() && forceQuit)
    {
        // dummy variables to consume user input
        std::string command;
        std::vector<int> input;

        if (playersTurn)
        {

            std::cout << *fightOrder[1] << "\n"
                << "What will " << fightOrder[1]->getName() << " do next: ";

            std::getline(std::cin, command);
            input = formatCommand(command);
        }
        else
        {
            input.push_back(1);
        }

        switch (input[0])
        {
        // Attack with base weapon
        // attack, atk
        case 1:
            tempDamage = fightOrder[playersTurn]->dealDamage();
            fightOrder[!playersTurn]->takeDamage(tempDamage);

            std::cout << "\n"
                << fightOrder[playersTurn]->getName() << " dealt " << tempDamage
                << " to " << fightOrder[!playersTurn]->getName() << "\n"
                << std::endl;
            break;
        // ability, abl
        case 2:
            std::cout <<
                "Ability selected, this feature is currently under development, select something else" 
                << std::endl;
            playersTurn = !playersTurn;
            break;
        // pp, pplayer
        case 12:
            // Print the basic character information for the player
            std::cout << *fightOrder[1] << std::endl;  
            // So printing won't cost you the turn
            playersTurn = !playersTurn;
            break;
        // pm, pmonster
        case 13:
            // Print the basic character information for the monster
            std::cout << *fightOrder[0] << std::endl;
            playersTurn = !playersTurn;
            break;

        // exit
        case 0:
            forceQuit = false;
            break;
        
         // help
        case -1:
            std::cout << "\n"
                << "atk:        Attack the monster with your weapon.\n"
                << "abl [int]:  Choose an ability to perform on the monster.\n"
                

                << "\n\n                   DEBUGGING"  
                << "\n**************************************************\n"

                << "pp:         Display the basic details of your hero.\n" 
                << "pm:         Display the basic details of the monster.\n"

                << std::endl;
            // Stops the player from loosing their turn if they enter a wrong command
            playersTurn = !playersTurn;
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



// Not sure if we're going to need this function
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
            << "Defeating the monster has granted you " << monsterXP << " experience.\n"
            << "Here's how " << fightOrder[1]->getName() << " is looking after that fight.\n"
            << *dynamic_cast<player*> (fightOrder[1]) << "\n"

            << "Would you like to 'Loot' the monster? \n"

            << std::endl;

        int input;
        bool monsterLooted = false;


        while (!monsterLooted)
        {
            std::string command;
            std::cin >> command;

            input = formatCommand(command)[0];

            switch (input)
            {
            // loot, yes
            case 20:
                // Until we have looting in the game, I figure we can get a bit of gold :)
                fightOrder[1]->setGold(fightOrder[0]->getGold());

                monsterLooted = true;
                break;

            case 0:
                if (!monsterLooted)
                {
                    std::cout
                        << "\nOnce you leave the monster encounter, the loot will still be available until you leave the room.\n"
                        << "However, if there is another monster in this room that you haven't found yet, this monsters loot "
                        << "will be taken back into the spire as sacrifice.\nAnd will be gone forever.\n"
                        << "Are you sure that you're actually alone now...? ";

                    std::cin >> command;

                    if (command == "Yes" || command == "yes" || command == "y")
                        monsterLooted = true;

                    else if(command == "No" || command == "no" || command == "n")
                        break;
                }
                break;
            }
        }
    }
    // We should create a gameOver state. And call it here
    else
    {
        std::cout
            << "Sorry Adventurer, but this is where your journey ends.\n"
            // Print out the full character details for the hero
            << *dynamic_cast<player*> (fightOrder[1])
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

std::vector<int> combatManager::formatCommand(std::string command)
{
    // Return a vector of ints as formatted commands
    std::vector<int> temp;
    // Push back each new command to a new vector index
    std::vector<std::string> tempCommand;
    std::string parsed;
    std::stringstream parser(command);

    // Parse the line of commands input by the player
    while (getline(parser, parsed, ' '))
    {
        tempCommand.push_back(parsed);
    }
    // Format the commands to be all lower case
    for (unsigned int i = 0; i < tempCommand.size(); i++)
    {
        for (unsigned int c = 0; c < tempCommand[i].size(); c++)
            tempCommand[i][c] = tolower(tempCommand[i][c]);
    }

    // Perform a basic attack with the equipped weapon
    if (tempCommand[0] == "attack" || tempCommand[0] == "atk")
        temp.push_back(1);
    // Choose an ability to perform
    if (tempCommand[0] == "ability" || tempCommand[0] == "abl")
        temp.push_back(2);


    // Only used during the endFight phase
    else if (tempCommand[0] == "loot" || tempCommand[0] == "lt" || tempCommand[0] == "yes" || tempCommand[0] == "y")
        temp.push_back(20);

    // **** Debugging Commands **** \\
    // Print the player
    else if (tempCommand[0] == "pplayer" || tempCommand[0] == "pp")
        temp.push_back(12);
    // Print the monster
    else if (tempCommand[0] == "pmonster" || tempCommand[0] == "pm")
        temp.push_back(13);

    else if (tempCommand[0] == "exit" || tempCommand[0] == "exit")
        temp.push_back(0);

    // If no valid command was entered, display the available commands to the user
    else
        temp.push_back(-1);


    //// Get rid of the command string once it's been formatted
    tempCommand.erase(tempCommand.begin());
    // Push back all the type numbers that the user entered in their command
    if (!tempCommand.empty())
        for (auto i : tempCommand)
            // Need to add an exception for if the player enters in a sequence of words
            // This is currently assuming that only 1 word will be entered, followed by numbers
            temp.push_back(std::stoi(i));

    return temp;
}