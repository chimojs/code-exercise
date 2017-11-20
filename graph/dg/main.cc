#include<fstream>
#include <vector>
#include <iostream>
#include "dgraph.h"
#include "ddfs.h"
#include "dcycle.h"
#include "topological.h"
int main(int argc, char* argv[])
{
    std::ifstream fin(argv[1]);
    DirectedDGraph::DGraph dg(fin);
    DirectedDGraph::CycleDetected cd(dg);
    bool has = cd.hascycle();
    std::vector<int> cycle = cd.cycle();
    for (int v : cycle)
        std::cout << v << ' ';
    std::cout << std::endl;
    DirectedDGraph::Topological tp(dg);
    bool bDAG = tp.isDAG();
    getchar();
    return 0;
}