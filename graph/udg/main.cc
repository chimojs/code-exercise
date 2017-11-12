#include<fstream>
#include "graph.h"
#include "bfs.h"
int main(int argc, char* argv[])
{
    //Graph g(5);
    std::ifstream fin(argv[1]);
    UndirectedGraph::Graph g(fin);
    UndirectedGraph::BFS dfs(g, 4);
    int v = g.vertex();
    int e = g.edge();
    int c = dfs.count();
    bool con = dfs.marked(8);
    return 0;
}