#include<fstream>
#include "dgraph.h"

int main(int argc, char* argv[])
{
    //Graph g(5);
    std::ifstream fin(argv[1]);
    DirectedDGraph::DGraph dg(fin);
    int v = dg.vertex();
    v = dg.edge();
    DirectedDGraph::DGraph dgr = dg.reverse();
    v = dgr.vertex();
    return 0;
}