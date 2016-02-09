#define SUM 45
#define SUMTOTAL 405

bool isPlaceable(sudoku sudo, short px, short py, short pi);
bool isSolved(sudoku sudo);
void copySudoku(sudoku source, sudoku destination);

bool isPlaceable(sudoku sudo, short px, short py, short pi)
{
    for(short y = 0; y < 9; y++)
        if(sudo[y][px] == pi)
            return false;
    for(short x = 0; x < 9; x++)
        if(sudo[py][x] == pi)
            return false;
    short aX = (px - px%3);
    short aY = (py - py%3);
    for(short sx = 0; sx < 3; sx++)
    for(short sy = 0; sy < 3; sy++)
        if(sudo[aY + sy][aX + sx] == pi)
            return false;
    return true;
}

bool isSolved(sudoku sudo)
{
    for(short x = 0; x < 9; x++)
        for(short y = 0; y < 9; y++)
            if(sudo[x][y] == EMPTY)
                return false;

    short sumTotal = 0,
          sumRow   = 0,
          sumCol   = 0;

    for(short x = 0; x < 9; x++)
    {
        sumRow = 0;
        sumCol = 0;
        for(short y = 0; y < 9; y++)
        {
            sumCol   += sudo[x][y];
            sumRow   += sudo[y][x];
            sumTotal += sudo[y][x];
        }

        if(sumRow != SUM || sumCol != SUM)
            return false;
    }

    if(sumTotal != SUMTOTAL)
        return false;

    short sumSqu = 0;
    for(short x = 0; x < 9; x += 3)
    {
        for(short y = 0; y < 9; y += 3)
        {
            sumSqu = 0;
            short aX = (x - x%3),
                  aY = (y - y%3);
            for(short sx = 0; sx < 3; sx++)
            {
                for(short sy = 0; sy < 3; sy++)
                {
                    sumSqu += sudo[aY + sy][aX + sx];
                }
            }

            if(sumSqu != SUM)
                return false;
        }
    }

    for(int x = 0; x < 9; x++)
    {
        short placedCols[9] = {0,0,0,0,0,0,0,0,0};
        short placedRows[9] = {0,0,0,0,0,0,0,0,0};
        for(int y = 0; y < 9; y++)
        {
            placedCols[sudo[x][y]]++;
            placedRows[sudo[y][x]]++;
        }
        for(int i = 0; i < 9; i++)
        {
            if(placedCols[i] > 1 || placedRows[i] > 1)
                return false;
        }
    }

    for(short x = 0; x < 9; x += 3)
    {
        for(short y = 0; y < 9; y += 3)
        {
            short placedSqur[9] = {0,0,0,0,0,0,0,0,0};
            short aX = (x - x%3),
                  aY = (y - y%3);
            for(short sx = 0; sx < 3; sx++)
            {
                for(short sy = 0; sy < 3; sy++)
                {
                    placedSqur[sudo[aY + sy][aX + sx]]++;
                }
            }
            for(int i = 0; i < 9; i++)
            {
                if(placedSqur[i] > 1)
                    return false;
            }
        }
    }
    return true;
}

void copySudoku(sudoku source, sudoku destination)
{
    for(short y = 0; y < 9; y++)
        for(short x = 0; x < 9; x++)
            destination[y][x] = source[y][x];
}
