#ifndef WG_WEIGHTEDGRAPH_H_
#define WG_WEIGHTEDGRAPH_H_
#include<fstream>
#include<set>
#include<vector>

namespace WeightedGraph{
    class Edge
    {
    public:
        Edge(int v, int w, double weight);
        double weight() const;
        int either() const;
        int other(int v) const;
        int compareto(const Edge& other) const;
        bool operator < (const Edge& right) const;
    private:
        int _v;
        int _w;
        double _weight;
    };

    class  WGraph
    {
    public:
        typedef std::set<Edge> edge_set;
        typedef std::vector<edge_set> adj_list;

        WGraph(int v);
        WGraph(std::ifstream& fin);
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
#endif // WG_WEIGHTEDGRAPH_H_