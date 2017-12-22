#include <iostream>
#include "CPM.h"

int main(int argc, char* argv[])
{
    std::ifstream fin(argv[1]);
    CPM cpm;
    cpm.Parse(fin);
    getchar();
    return 0;
}
