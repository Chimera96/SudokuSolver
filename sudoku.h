#define EMPTY 0
#define NONE -1

typedef short sudoku[9][9];
bool isPlaceable(sudoku sudo, short px, short py, short pi);
bool isSolved(sudoku sudo);

bool isPlaceable(sudoku sudo, short px, short py, short pi)
{
    for(short y = 0; y < 9; y++)
        if(sudo[y][px] == pi) return false;
    for(short x = 0; x < 9; x++)
        if(sudo[py][x] == pi) return false;
    short aX = (px - px%3);
    short aY = (py - py%3);
    for(short sx = 0; sx < 3; sx++)
    for(short sy = 0; sy < 3; sy++)
        if(sudo[aY + sy][aX + sx] == pi) return false;
    return true;
}

bool isSolved(sudoku sudo)
{
    short sumTotal = 0;
    short sumRow = 0;
    short sumCol = 0;

    for(short x = 0; x < 9; x++)
    {
        sumRow = 0;
        short rowParts[9] = {0,0,0, 0,0,0, 0,0,0};
        sumCol = 0;
        short colParts[9] = {0,0,0, 0,0,0, 0,0,0};
        for(short y = 0; y < 9; y++)
        {
            sumCol   += sudo[x][y];
            sumRow   += sudo[y][x];
            sumTotal += sudo[y][x];

            rowParts[sudo[x][y]]++;
            colParts[sudo[y][x]]++;
        }

        //cached for performance (1 + 2 + ... + 9)
        if(sumRow != 45 || sumCol != 45) return false;

        for(short i = 0; i < 9; i++)
        {
            if(rowParts[i] != 1) return false;
            //if(colParts[i] != 1) return false;
        }
    }

    //cached for performance (9*1 + 9*2 + ... + 9*9)
    if(sumTotal != 405) return false;

    short sumSqu = 0;
    for(short x = 0; x < 9; x += 3)
    {
        for(short y = 0; y < 9; y += 3)
        {
            sumSqu = 0;
            short squParts[9] = {0,0,0, 0,0,0, 0,0,0};
            short aX = (x - x%3);
            short aY = (y - y%3);
            for(short sx = 0; sx < 3; sx++)
            {
                for(short sy = 0; sy < 3; sy++)
                {
                    sumSqu += sudo[aY + sy][aX + sx];
                    squParts[(sudo[aY + sy][aX + sx])]++;
                }
            }

            //cached for performance (1 + 2 + ... + 9)
            if(sumSqu != 45) return false;

            for(short i = 0; i < 9; i++)
            {
                //if(squParts[i] != 1) return false;
            }
        }
    }

    return true;
}
