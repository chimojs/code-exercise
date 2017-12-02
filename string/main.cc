#include <iostream>
#include <fstream>
#include "lsd_sort.h"
#include "msd_sort.h"
#include "quick3string.h"
#include "kmp.h"

int main(int argc, char* argv[])
{
    std::ifstream fin(argv[1]);
    std::vector<std::string> strs;
    std::string pat, text;

    while (!fin.eof())
    {
        fin >> pat >> text;
    }
    string::KMP kmp(pat);
    int idx = kmp.search(text);
    std::cout << text << std::endl;
    int len = text.length();
    int m = pat.length();
    for (int i = 0; i < len; ++i)
    {
        if (i == idx)
        {
            std::cout << pat;
            i += m - 1;
        }
        else
        {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;
    getchar();
    return 0;
}