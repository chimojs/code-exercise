#include<fstream>
#include "graph.h"
#include "cc.h"
int main(int argc, char* argv[])
{
    //Graph g(5);
    std::ifstream fin(argv[1]);
    UndirectedGraph::Graph g(fin);
    UndirectedGraph::CC cc(g);
    int c = cc.count();
    return 0;
}