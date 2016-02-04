void Algorithm1(sudoku sudo);
void Algorithm2(sudoku sudo);
void Algorithm3(sudoku sudo);
void Algorithm4(sudoku sudo);

//simple exhaustive search
void Algorithm1(sudoku sudo)
{
    bool couldPlace = false;
    do
    {   couldPlace= false;
        for(short x = 0; x < 9;x++)
        {
            for(short y = 0; y < 9; y++)
            {
                if(sudo[y][x] == EMPTY)
                {
                    short foundValue = NONE;
                    for(short i = 1; i <= 9; i++)
                    {
                        if(isPlaceable(sudo, x, y, i))
                        {
                            if(foundValue == NONE)
                            {
                                foundValue = i;
                            }
                            else
                            {
                                foundValue = NONE;
                                break;
                            }
                        }
                    }
                    if(foundValue != NONE)
                    {
                        sudo[y][x] = foundValue;
                        couldPlace = true;
                    }
                }
            }
        }
    } while (couldPlace);
}

//same as 1 but with caching
void Algorithm2(sudoku sudo)
{
    //prepare cache
    short cache[9][9][9];
    for(short y = 0; y < 9; y++)
    {
        for(short x = 0; x < 9; x++)
        {
            if(sudo[y][x] == EMPTY)
            {
                for(short i = 1; i <= 9; i++)
                {
                    cache[y][x][i-1] = isPlaceable(sudo, x, y, i) ? i : EMPTY;
                }
            }
            else
            {
                cache[y][x][0] = NONE;
            }
        }
    }

    //solve
    bool couldPlace = false;
    do
    {   couldPlace = false;
        for(short y = 0; y < 9; y++)
        {
            for(short x = 0; x < 9; x++)
            {
                if(cache[y][x][0] == NONE) continue;
                short foundValue = NONE;
                bool foundAny = false;
                for(short i = 1; i <= 9; i++)
                {
                    if(cache[y][x][i-1] == EMPTY) continue;
                    if(!isPlaceable(sudo, x, y, i))
                    {
                        cache[y][x][i-1] = EMPTY;
                    }
                    else
                    {
                        foundAny = true;
                        if(foundValue == NONE)
                        {
                            foundValue = i;
                        }
                        else
                        {
                            foundValue = NONE;
                            break;
                        }
                    }
                }
                if(!foundAny)
                {
                    cache[y][x][0] = NONE;
                }
                else if(foundValue != NONE)
                {
                    sudo[y][x] = foundValue;
                    cache[y][x][foundValue-1] = EMPTY;
                    couldPlace = true;
                }
            }
        }
    } while (couldPlace);
}

void Algorithm3(sudoku sudo)
{
    bool couldPlace = false;
    do
    {   couldPlace = false;
        for(short a = 0; a < 9; a++)
        {
            short placeableRows[9] = {0,0,0,0,0,0,0,0,0};
            short placeableCols[9] = {0,0,0,0,0,0,0,0,0};
            short placeableSqur[9] = {0,0,0,0,0,0,0,0,0};

            short sqX = (a%3)*3;
            short sqY = (a/3)*3;

            for(short b = 0; b < 9; b++)
            {//Rows & Cols
                if(sudo[a][b] == EMPTY)
                {//Rows
                    for(int i = 1; i <= 9; i++)
                    {
                        if(isPlaceable(sudo, b, a, i))
                        {
                            placeableRows[i-1]++;
                        }
                    }
                }
                if(sudo[b][a] == EMPTY)
                {//Cols
                    for(int i = 1; i <= 9; i++)
                    {
                        if(isPlaceable(sudo, a, b, i))
                        {
                            placeableCols[i-1]++;
                        }
                    }
                }
            }

            for (int y = 0; y < 3; y++)
            {//Squares
                for (int x = 0; x < 3; x++)
                {
                    if(sudo[sqY+y][sqX+x] == EMPTY)
                    {
                        for(int i = 1; i <= 9; i++)
                        {
                            if(isPlaceable(sudo, sqX+x, sqY+y, i))
                            {
                                placeableSqur[i-1]++;
                            }
                        }
                    }
                }
            }

            //Check Results & Place (eventually)
            for(short i = 1; i <= 9; i++)
            {
                if(placeableRows[i-1] == 1)
                {
                    for(short b = 0; b < 9; b++)
                    {
                        if(sudo[a][b] == EMPTY)
                        {
                            if(isPlaceable(sudo, b, a, i))
                            {
                                sudo[a][b] = i;
                                couldPlace = true;
                            }
                        }
                    }
                }
                if(placeableCols[i-1] == 1)
                {
                    for(short b = 0; b < 9; b++)
                    {
                        if(sudo[b][a] == EMPTY)
                        {
                            if(isPlaceable(sudo, a, b, i))
                            {
                                sudo[b][a] = i;
                                couldPlace = true;
                            }
                        }
                    }
                }
                if(placeableSqur[i-1] == 1)
                {
                    for (int y = 0; y < 3; y++)
                    {//Squares
                        for (int x = 0; x < 3; x++)
                        {
                            if(sudo[sqY+y][sqX+x] == EMPTY)
                            {
                                if(isPlaceable(sudo, sqX+x, sqY+y, i))
                                {
                                    sudo[sqY+y][sqX+x] = i;
                                    couldPlace = true;
                                }
                            }
                        }
                    }
                }
            }
        }

    } while (couldPlace);
}

//alg4 (3 with cache)
//heuristic approach

//backtracking approach
//retParam backtracking(short pX, int pY, int i, sudoku field)
