#include<fstream>
#include "wgraph.h"

int main(int argc, char* argv[])
{
    std::ifstream fin(argv[1]);
    WeightedGraph::WGraph wg(fin);
    int v = wg.vertex();
    int edge = wg.edge();
    WeightedGraph::WGraph::edge_set edges = wg.adj(3);
    return 0;
}