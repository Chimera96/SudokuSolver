void readFile (sudoku sudo, const char* path);
void writeFile(sudoku sudo, const char* path);
void readFromConsole(sudoku sudo);
void printToConsole(sudoku sudo);
void printPlaceables(sudoku sudo);

#define G 9

/*
    path is the relative path to the file
*/

void readFile(sudoku sudo, const char* path)
{
    //TODO check if file is unavailable
    FILE *fp;
    sudoku feld;
    int i, j;
    char temp[G+3] = {0};
    bool succeeded = true;

    fp = fopen(path, "r");

    for(i = 0; i < G; i++)
    {
        if(fgets(temp, G + 3, fp) == NULL)
        {
            printf("Daten nicht vollstaendig!\n");
            fclose(fp);
            succeeded = false;
        }
        for(j = 0; j < G; j++)
        {
            if(temp[j] >= '0' && temp[j] <= '9')
                feld[i][j] = temp[j] - '0';
            else
                succeeded = false;
        }
    }
    fclose(fp);

    if(succeeded)
        copySudoku(feld, sudo);
    else
        printf("Datei nicht lesbar !\n");
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
        scanf("%hd %hd %hd %hd %hd %hd %hd %hd %hd",
            &sudo[line][0], &sudo[line][1], &sudo[line][2],
            &sudo[line][3], &sudo[line][4], &sudo[line][5],
            &sudo[line][6], &sudo[line][7], &sudo[line][8]);
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

void printPlaceables(sudoku sudo)
{
    for(short y = 0; y < 9; y++)
    {
        for(short x = 0; x < 9; x++)
        {
            if(sudo[y][x] == EMPTY)
            {
                for(short i = 1; i <= 9; i++)
                {
                    if(isPlaceable(sudo, x, y, i))
                        printf("%d", i);
                    else
                        printf("_");
                }
                printf(((x + 1) % 3 == 0) ? "    " : " ");
            }
            else
            {
                printf("---------");
                printf(((x + 1) % 3 == 0) ? "    " : " ");
            }
        }
        printf(((y + 1) % 3 == 0) ? "\n\n" :"\n");
    }
}
