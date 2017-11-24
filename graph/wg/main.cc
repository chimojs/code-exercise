#include<fstream>
#include <iostream>
#include "wgraph.h"
#include "PrimMST.h"
#include "KruskalMST.h"
int main(int argc, char* argv[])
{
    std::ifstream fin(argv[1]);
    WeightedGraph::WGraph wg(fin);
    int v = wg.vertex();
    int edge = wg.edge();
    WeightedGraph::EagerPrimMST lpmst(wg);
    double value = lpmst.weight();
    std::queue<WeightedGraph::Edge> edges = lpmst.edges();
    while (!edges.empty())
    {
        WeightedGraph::Edge&  e = edges.front();
        std::cout << e << std::endl;
        edges.pop();
    }
    std::cout << lpmst.weight() << std::endl;
    getchar();
    return 0;
}