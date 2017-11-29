#include <iostream>
#include <fstream>
#include "lsd_sort.h"

int main(int argc, char* argv[])
{
    std::ifstream fin(argv[1]);
    std::vector<std::string> strs;
    while (!fin.eof())
    {
        std::string words;
        fin >> words;
        strs.push_back(std::move(words));
    }
    string::LSD::sort(strs, 3);
    for (auto& words : strs)
        std::cout << words << std::endl;
    getchar();
    return 0;
}