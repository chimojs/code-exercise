#include<stdio.h>
#include "LCS.h"

int main(int argv, char* args[])
{
    char* str1 = "the quick brown fox jumps over the lazy dog";
    char* str2 = "the quick brown dog jumps over the lazy fox";
    int substr = lcs_substr(str1, str2);
    int seq = lcs_sequence(str1, str2);
    int a = 13;
    return 0;
}