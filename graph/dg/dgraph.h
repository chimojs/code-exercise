#ifndef UDG_DGraph_H_
#define UDG_DGraph_H_
#include<fstream>
#include<set>
#include<vector>

namespace DirectedDGraph{
    class  DGraph
    {
    public:
        typedef std::set<int> edge_set;
        typedef std::vector<edge_set> adj_list;

        DGraph(int v);
        DGraph(std::ifstream& fin);
        DGraph(const DGraph& other);
        DGraph(DGraph&& other);
        int vertex() const;
        int edge() const;
        void addedge(int v, int w);
        const edge_set& adj(int v) const;
        DGraph reverse() const;
        DGraph& operator= (const DGraph& other);
        DGraph& operator= (DGraph&& other);
    protected:
        int _v;
        int _edge;
        adj_list _adj;
    };
}
#endif // UDG_DGraph_H_