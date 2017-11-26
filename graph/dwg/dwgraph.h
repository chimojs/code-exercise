#ifndef WG_DIRECTEDWEIGHTEDGRAPH_H_
#define WG_DIRECTEDWEIGHTEDGRAPH_H_
#include<fstream>
#include<set>
#include<vector>
#include <iostream>

namespace DirectedWeightedGraph{
    class Edge
    {
    public:
        Edge();
        Edge(int v, int w, double weight);
        double weight() const;
        int from() const;
        int to() const;
        int compareto(const Edge& other) const;
        bool operator < (const Edge& right) const;
        bool operator > (const Edge& right) const;
        bool invalid();
    public:
        int _v;
        int _w;
        double _weight;
        friend std::ostream& operator << (std::ostream& out, const Edge & e);
    };

    class  DWGraph
    {
    public:
        typedef std::set<Edge> edge_set;
        typedef std::vector<edge_set> adj_list;

        DWGraph(int v);
        DWGraph(std::ifstream& fin);
        int vertex() const;
        int edge() const;
        void addedge(const Edge& other);
        const edge_set& adj(int v) const;
    protected:
        int _v;
        int _edge;
        adj_list _adj;
    };
}
#endif // WG_DIRECTEDWEIGHTEDGRAPH_H_