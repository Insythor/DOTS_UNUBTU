/**
    @author
    @brief
*/

#include "../include/puzzleManager.h"

puzzleManager::puzzleManager() {
    for(unsigned int i = 1; i <= numOfPuzzles; ++i)
        puzzlesLeft.push_back(i);
}

puzzleManager::~puzzleManager() {

}


// Puzzle 1: Price Beat Challenge
void puzzleManager::puzzleOne(player* myPlayer) {
    PuzzleOne *puzzle1 = new PuzzleOne;
    puzzle1->mainGame();
    bool result = puzzle1->getResult();
    if (result == true) {
        myPlayer->setGold(10);
    } else {
        myPlayer->setGold(-10);
    }
    delete puzzle1;
}


// Puzzle 2: Matching Card Challenge
void puzzleManager::puzzleTwo(player* myPlayer) {
    PuzzleTwo *puzzle2 = new PuzzleTwo;
    puzzle2->mainGame();
    bool result = puzzle2->getResult();
    if (result == true) {
        // player's speed +10
        std::vector<int> stats;
        stats.push_back(0); // str
        stats.push_back(0); // dex
        stats.push_back(0); // int
        stats.push_back(10); // speed
        myPlayer->addToStats(stats);
    } else {
        // player's speed -10
        std::vector<int> stats;
        stats.push_back(0); // str
        stats.push_back(0); // dex
        stats.push_back(0); // int
        stats.push_back(-10); // speed
        myPlayer->addToStats(stats);
    }
    delete puzzle2;
}



// Puzzle 3: Decipher the Hidden Message Challenge
void puzzleManager::puzzleThree(player* myPlayer) {
    PuzzleThree *puzzle3 = new PuzzleThree;
    puzzle3->mainGame();
    bool result = puzzle3->getResult();
    if (result == true) {
        // playyer's intellect +10
        std::vector<int> stats;
        stats.push_back(0); // str
        stats.push_back(0); // dex
        stats.push_back(10); // int
        stats.push_back(0); // speed
        myPlayer->addToStats(stats);
    } else {
        // player's intellect -10
        std::vector<int> stats;
        stats.push_back(0); // str
        stats.push_back(0); // dex
        stats.push_back(-10); // int
        stats.push_back(0); // speed
        myPlayer->addToStats(stats);
    }
    delete puzzle3;
}



// Puzzle 4
// return false if player has less than 1 health
bool puzzleManager::puzzleFour(player* myPlayer) {
    PuzzleFour *puzzle4;
    puzzle4 = new PuzzleFour("docs/DATA/puzzle4-objects.tsv", 16, myPlayer);
    puzzle4->mainGame();
    delete puzzle4;
    if (myPlayer->getCurrentHealth() < 1) {
        return false;
    } else {
        return true;
    }
}


// Puzzle 5
// return false if player has less than 1 health
bool puzzleManager::puzzleFive(player* myPlayer) {
    PuzzleFour *puzzle5;
    puzzle5 = new PuzzleFour("docs/DATA/puzzle5-objects.tsv", 13, myPlayer);
    puzzle5->mainGame();
    delete puzzle5;
    if (myPlayer->getCurrentHealth() < 1) {
        return false;
    } else {
        return true;
    }
}

bool puzzleManager::startPuzzle(player* myPlayer) {
    bool survive = true;
    // choose a random puzzle index
    srand(time(NULL));
    std::random_shuffle(puzzlesLeft.begin(), puzzlesLeft.end());
    int puzzleIndex = puzzlesLeft.back();
    // redirect to the main game of the puzzles
    switch(puzzleIndex) {
    case 1:
        puzzleOne(myPlayer);
        break;
    case 2:
        puzzleTwo(myPlayer);
        break;
    case 3:
        puzzleThree(myPlayer);
        break;
    case 4:
        survive = puzzleFour(myPlayer);
        break;
    case 5:
        survive = puzzleFive(myPlayer);
        break;
    default:
        break;
    }
    // reduce puzzLesLeft
    //puzzlesLeft.pop_back();
    return survive;
}

std::vector<int> puzzleManager::getPuzzlesLeft() {
    return puzzlesLeft;
}

/*
std::vector<Puzzle*> puzzleManager::getPuzzles() {
    return puzzles;
}*/
