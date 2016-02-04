#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "sudoku.h"
#include "solver.h"
#include "generator.h"
#include "IO.h"

void printProjectTitle();

int main()
{
    printProjectTitle();
    sudoku currentSudoku = {//easy one
        { 0,9,4, 0,3,0, 0,0,0 },
        { 8,0,3, 0,0,0, 0,0,0 },
        { 0,7,5, 0,0,4, 9,3,2 },

        { 0,3,0, 0,9,2, 0,4,1 },
        { 0,2,0, 4,0,5, 0,9,0 },
        { 7,4,0, 3,6,0, 0,2,0 },

        { 9,6,1, 5,0,0, 2,7,0 },
        { 0,0,0, 0,0,0, 4,0,9 },
        { 0,0,0, 0,7,0, 5,1,0 }
    };

    /*= {//Difficult one
            { 7,0,3, 0,0,0, 0,0,0 },
            { 0,6,0, 0,0,0, 8,0,0 },
            { 0,0,9, 6,0,3, 5,0,0 },

            { 0,1,5, 7,0,0, 0,0,6 },
            { 0,0,0, 0,3,0, 0,0,4 },
            { 0,0,0, 2,0,0, 0,0,9 },

            { 0,0,0, 0,2,0, 0,9,0 },
            { 0,0,2, 0,0,0, 0,0,0 },
            { 0,0,0, 0,8,5, 0,7,1 }
        };*/

    Algorithm1(currentSudoku);
    Algorithm3(currentSudoku);
    printToConsole(currentSudoku);
    printf("%s", isSolved(currentSudoku) ? "solved" : "!!!!");

    return 0;
}

void printProjectTitle()
{
    printf("SudokuSolver\n\n");
}
