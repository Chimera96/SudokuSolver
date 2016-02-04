//Fastest results with 26-30
#define MAGIC_NUMBER 28

void generateSudoku(int numberCount, sudoku sudo);
void generateOneSolutionSudoku(int numberCount, sudoku sudo);

void generateSudoku(int numberCount, sudoku sudo)
{
    do
    {   //reset sudoku
        for(short y = 0; y < 9; y++)
            for(short x = 0; x < 9; x++)
                sudo[y][x] = 0;

        //place <magic_number> Numbers
        short placed = 0;
        do
        {   short y, x;
            do
            {   y = (rand() % 9);
                x = (rand() % 9);
            } while (sudo[y][x] != 0);

            short i = (rand() % 9) + 1;
            if(isPlaceable(sudo, x, y, i))
            {
                sudo[y][x] = i;
                placed++;
            }
        } while(placed < MAGIC_NUMBER);

        //TODO add other algs.
        //try solving
        algorithm1(sudo);
        algorithm3(sudo);
    } while (!isSolved(sudo));

    //remove (random)numbers
    short removeCount = (9*9) - numberCount;
    short y, x;
    while(removeCount > 0)
    {
        do
        {   y = (rand() % 9);
            x = (rand() % 9);
        } while (sudo[y][x] == 0);

        sudo[y][x] = 0;
        removeCount--;
    }
}

void generateOneSolutionSudoku(int numberCount, sudoku sudo)
{//generate sudokus that have only one solution
    //doesn't work with numbers < 17 !!!
    sudoku suCopy;
    do
    {   generateSudoku(numberCount, sudo);
        copySudoku(sudo, suCopy);
        algorithm1(sudo);
        algorithm3(sudo);
    } while (!isSolved(sudo));
    copySudoku(suCopy, sudo);
}
