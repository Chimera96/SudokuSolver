void readFile(const char* path);
void writeFile(sudoku sudo, const char* path);
void readFromConsole(sudoku sudo);
void printToConsole(sudoku sudo);

void readFile(const char* path)
{

}

void writeFile(sudoku sudo, const char* path)
{
    FILE *datei;
    datei = fopen(path, "w");

    for(short y = 0; y < 9; y++)
    {
        for(short x = 0; x < 9; x++)
        {
            fprintf(datei, (sudo[y][x] == EMPTY) ? " " : "%d", sudo[y][x]);
        }
        if(y+1 < 9)
        {
            fprintf(datei,"\n");
        }
    }
    fclose(datei);
}

void readFromConsole(sudoku sudo)
{
    for(short line = 0; line < 9; line++)
    {
        printf("line %d: ", (line+1));
        scanf("%hd %hd %hd %hd %hd %hd %hd %hd %hd", &sudo[line][0], &sudo[line][1], &sudo[line][2],
            &sudo[line][3], &sudo[line][4], &sudo[line][5], &sudo[line][6], &sudo[line][7], &sudo[line][8]);
    }
}

void printToConsole(sudoku sudo)
{
    for(short y = 0; y < 9; y++)
    {
        for(short x = 0; x < 9; x++)
        {
            printf(((x + 1) % 3 == 0) ? "%d " : "%d", sudo[y][x]);
        }
        printf(((y + 1) % 3 == 0) ? "\n\n" :"\n");
    }
}

//TODO func that shows what numbers are placeable at pos x
/*
    123456789 123456789 1         123456789 x         x ...
    x         2345
*/
