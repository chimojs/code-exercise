#include <stdlib.h>
#include <string.h>
#include "LCS.h"

int row_size = 0;
int col_size = 0;

int value_at(int* pT, int row, int col)
{
    int index = col_size * row + col;
    return pT[index];
}

void setval_at(int* pT, int row, int col, int val)
{
    int index = col_size * row + col;
    pT[index] = val;
}

void init(int* pT, int row, int col)
{
    for (int i = 0; i < row_size; ++i)
        setval_at(pT, i, 0, 0);
    for (int i = 0; i < col_size; ++i)
        setval_at(pT, 0, i, 0);
}

int lcs_sequence(char * seq1, char * seq2)
{
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);
    if (len1 == 0 || len2 == 0)
        return 0;

    row_size = len1 + 1;
    col_size = len2 + 1;
    int* pT = (int*)malloc(row_size * col_size * sizeof(int));
    init(pT, len1, len2);

    int max = 0;
    for (int i = 1; i < len1; ++i)
    {
        for (int j = 1; j < len2; ++j)
        {
            if (seq1[i - 1] == seq2[j - 1])
            {
                int val = value_at(pT, i - 1, j - 1);
                setval_at(pT, i, j, val + 1);
            }
            else
            {
                int v1 = value_at(pT, i - 1, j);
                int v2 = value_at(pT, i, j - 1);
                setval_at(pT, i, j, v1 > v2 ? v1 : v2);
            }
            if (value_at(pT, i, j) > max)
                max = value_at(pT, i, j);
        }
    }
    free(pT);
    return max;
}

int lcs_substr(char * substr1, char * substr2)
{
    int len1 = strlen(substr1);
    int len2 = strlen(substr2);
    if (len1 == 0 || len2 == 0)
        return 0;

    row_size = len1 + 1;
    col_size = len2 + 1;
    int* pT = (int*)malloc(row_size * col_size * sizeof(int));
    init(pT, len1, len2);

    int max = 0;
    for (int i = 1; i < len1; ++i)
    {
        for (int j = 1; j < len2; ++j)
        {
            if (substr1[i - 1] == substr2[j - 1])
            {
                int val = value_at(pT, i - 1, j - 1);
                setval_at(pT, i, j, val + 1);
            }
            else
            {
                setval_at(pT, i, j, 0);
            }
            if (value_at(pT, i, j) > max)
                max = value_at(pT, i, j);
        }
    }
    free(pT);
    return max;
}
