/**
    @author
    @brief
*/

#include "puzzleManager.h"

puzzleManager::puzzleManager()
{
    //ctor
}

puzzleManager::~puzzleManager()
{
    //dtor
}


// Puzzle 1
void puzzleManager::puzzleOne() {

    PuzzleOne *puzzle1 = new PuzzleOne;
    puzzle1->mainGame();
    if (puzzle1->getResult() == true) {
        // playyer's gold +10
    } else {
        // player's gold -10
    }

    delete puzzle1;

}


// Puzzle 2
void puzzleManager::puzzleTwo() {
    PuzzleTwo *puzzle2 = new PuzzleTwo;
    puzzle2->mainGame();
    if (puzzle2->getResult() == true) {
        // playyer's speed +10
    } else {
        // player's gold -10
    }
    delete puzzle2;
}



// Puzzle 3
void puzzleManager::puzzleThree() {
    PuzzleThree *puzzle3 = new PuzzleThree;
    puzzle3->mainGame();
    if (puzzle3->getResult() == true) {
        // playyer's intellenct +10
    }
    else {
        // playyer's intellenct -10
    }
    delete puzzle3;
}



// Puzzle 4
void puzzleManager::puzzleFour() {
    PuzzleFour *puzzle4 = new PuzzleFour("../docs/DATA/puzzle4-objects.tsv", 15);
    puzzle4->mainGame();
}


// Puzzle 5
void puzzleManager::puzzleFive() {
    PuzzleFour *puzzle5 = new PuzzleFour("../docs/DATA/puzzle5-objects.tsv", 11);
    puzzle5->mainGame();
}

