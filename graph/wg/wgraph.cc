#include "wgraph.h"

namespace WeightedGraph {
    Edge::Edge(int v, int w, double weight)
    {
        _v = v;
        _w = w;
        _weight = weight;
    }

    double Edge::weight() const
    {
        return _weight;
    }

    int Edge::either() const
    {
        return _v;
    }

    int Edge::other(int v) const
    {
        if (v == _v) return _w;
        return _v;
    }

    int Edge::compareto(const Edge& other) const
    {
        if (_weight < other._weight) return -1;
        else if (_weight == other._weight) return 0;
        else return 1;
    }
    bool Edge::operator<(const Edge & right) const
    {
        return _weight < right._weight;
    }
    bool Edge::operator>(const Edge & right) const
    {
        return _weight > right._weight;
    }
    std::ostream & operator<<(std::ostream& out, const Edge & e)
    {
        out << e._v << '-' << e._w << ' ' << e._weight;
        return out;
    }
    WGraph::WGraph(int v): _v(v), _edge(0), _adj(v)
    {
    }
    WGraph::WGraph(std::ifstream & fin)
    {
        fin >> _v;
        _adj.resize(_v);
        while (!fin.eof())
        {
            int v = -1, w = -1;
            double weight = 0.f;
            fin >> v >> w >> weight;
            addedge(Edge(v, w, weight));
        }
    }
    int WGraph::vertex() const
    {
        return _v;;
    }
    int WGraph::edge() const
    {
        return _edge;
    }
    void WGraph::addedge(const Edge & other)
    {
        int v = other.either();
        int w = other.other(v);
        _adj[v].insert(other);
        _adj[w].insert(other);
        ++_edge;
    }
    const WGraph::edge_set & WGraph::adj(int v) const
    {
        return _adj[v];
    }
}

