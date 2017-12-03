#include <stdbool.h>
#include "eight_queen.h"

bool compatible(int cols[8], int col)
{
    for (int i = 0; i < col; ++i)
    {
        //same line
        if (cols[i] == cols[col])
            return false;
        //45 degree
        else if (cols[i] - cols[col] == i - col)
            return false;
        //-45 degree
        else if (cols[i] - cols[col] == col - i)
            return false;
    }
    return true;
}

void trace_back(int cols[8], int col, int* pCount, void(*pfun)(int col[8]))
{
    for (int i = 0; i < 8; ++i)
    {
        cols[col] = i;
        if (compatible(cols, col))
        {
            if (col == 7)
            {
                ++*pCount;
                pfun(cols);
            }

            else
                trace_back(cols, col + 1, pCount, pfun);
        }
    }
}

int eight_queen(void(*pfun)(int col[8]))
{
    int cols[8] = { -1 };
    int count = 0;
    trace_back(cols, 0, &count, pfun);
    return count;
}
