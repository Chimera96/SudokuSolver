#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef short sudoku[9][9];

#define EMPTY 0
#define NONE -1

#include "sudoku.h"
#include "solver.h"
#include "generator.h"
#include "IO.h"

int main()
{
    srand(time(NULL));

    sudoku currentSudoku = {
            { 0,0,0, 0,0,0, 0,0,0 },
            { 0,0,0, 0,0,0, 0,0,0 },
            { 0,0,0, 0,0,0, 0,0,0 },

            { 0,0,0, 0,0,0, 0,0,0 },
            { 0,0,0, 0,0,0, 0,0,0 },
            { 0,0,0, 0,0,0, 0,0,0 },

            { 0,0,0, 0,0,0, 0,0,0 },
            { 0,0,0, 0,0,0, 0,0,0 },
            { 0,0,0, 0,0,0, 0,0,0 }
        };

        generateOneSolutionSudoku(35, currentSudoku);

    //algorithm1(currentSudoku);
    //algorithm2(currentSudoku);
    //algorithm3(currentSudoku);
    algorithmBT(currentSudoku);

    printToConsole(currentSudoku);
    printPlaceables(currentSudoku);

    printf("%s", isSolved(currentSudoku) ? "solved" : "!!!!");

    return 0;
}
