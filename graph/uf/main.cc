#include "union-find.h"
#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
    std::ifstream infile(argv[1]);
    int size = -1;
    infile >> size;
    UnionFind ufclient(size);
    while(!infile.eof())
    {
        int p, q;
        infile >> p >> q;
        if (!ufclient.Connected(p, q))
        {
            std::cout << p << " " << q << std::endl;
            ufclient.Union(p, q);
        }
    }
    std::cout << ufclient.Count() << " components" << std::endl;
    return 0;
}