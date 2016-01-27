void readFile();
void writeFile(sudoku sudo /*, string path*/);
void readFromConsole(sudoku sudo);
void printToConsole(sudoku sudo);

void readFile()
{

}

void writeFile(sudoku sudo /*, string path*/)
{
    FILE *datei;
    datei = fopen("test.txt", "w");

    for(short y = 0; y < 9; y++)
    {
        for(short x = 0; x < 9; x++)
        {
            if(sudo[y][x] == EMPTY) //TODO make  ?:; - expression
            {
                fprintf(datei, " ", sudo[y][x]);
            }
            else
            {
                fprintf(datei, "%d", sudo[y][x]);
            }
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
