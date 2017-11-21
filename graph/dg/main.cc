#include<fstream>
#include <vector>
#include <iostream>
#include "dgraph.h"
#include "ddfs.h"
#include "dcycle.h"
#include "topological.h"
#include "scc.h"
int main(int argc, char* argv[])
{
    std::ifstream fin(argv[1]);
    DirectedDGraph::DGraph dg(fin);
    DirectedDGraph::SCC scc(dg);
    int n = scc.count();
    getchar();
    return 0;
}