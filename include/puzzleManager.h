/**
    @author
    @brief
*/

#ifndef PUZZLEMANAGER_H
#define PUZZLEMANAGER_H
#include "player.h"
#include "Puzzle.h"
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
        bool startPuzzle(player* myPlayer);
        std::vector<Puzzle*> getPuzzles();
    private:
        std::vector<Puzzle*> puzzles;
        void puzzleOne();
        void puzzleTwo();
        void puzzleThree();
        void puzzleFour();
        void puzzleFive();

};

#endif // PUZZLEMANAGER_H
