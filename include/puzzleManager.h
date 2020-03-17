/**
    @author
    @brief
*/

#ifndef PUZZLEMANAGER_H
#define PUZZLEMANAGER_H

#include "Puzzle.h"
#include "PuzzleOne.h"
#include "PuzzleTwo.h"
#include "PuzzleThree.h"
#include "PuzzleFour.h"
#include <vector>


class puzzleManager
{
    public:
        puzzleManager();
        virtual ~puzzleManager();
        void startPuzzle(player* myPlayer);
        std::vector<puzzle*> getPuzzles();
    private:
        std::vector<puzzle*> puzzles;
        void puzzleOne();
        void puzzleTwo();
        void puzzleThree();
        void puzzleFour();
        void puzzleFive();

};

#endif // PUZZLEMANAGER_H
