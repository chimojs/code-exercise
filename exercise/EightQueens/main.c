#include <stdio.h>
#include "eight_queen.h"

void write(int col[8])
{
    FILE* f;
    fopen_s(&f, "F:\\code-exercise\\exercise\\EightQueens\\data.txt", "a+");
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (col[i] == j)
                fprintf(f, "%2d", 1);
            else
                fprintf(f, "%2d", 0);
        }
        fprintf(f, "%c%c", '\r', '\n');
    }
    fprintf(f, "%c%c", '\r', '\n');
    fclose(f);
}

int main()
{
    int val = eight_queen(write);
    printf("solution : %d", val);
    return 0;
}
