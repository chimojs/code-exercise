#ifndef UDG_GRAPH_H_
#define UDG_GRAPH_H_
#include<fstream>
#include<set>
#include<vector>

namespace UndirectedGraph{
    class  Graph
    {
    public:
        typedef std::set<int> edge_set;
        typedef std::vector<edge_set> adj_list;

        Graph(int v);
        Graph(std::ifstream& fin);
        int vertex() const;
        int edge() const;
        void addedge(int v, int w);
        const edge_set& adj(int v) const;
    protected:
        int _v;
        int _edge;
        adj_list _adj;
    };
}
#endif // UDG_GRAPH_H_