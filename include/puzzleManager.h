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
        void puzzleOne();
        void puzzleTwo();
        void puzzleThree();
        void puzzleFour();
        void puzzleFive();
        bool checkPuzzleDone();
        void startPuzzle();
        void endPuzzle();

    protected:

    private:
        static std::vector<int> puzzlesLeft;


};

#endif // PUZZLEMANAGER_H
