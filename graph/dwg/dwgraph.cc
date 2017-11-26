#include "dwgraph.h"

namespace DirectedWeightedGraph {
    Edge::Edge() 
        : _v(std::numeric_limits<int>::quiet_NaN()),
          _w(std::numeric_limits<int>::quiet_NaN()),
          _weight(std::numeric_limits<double>::quiet_NaN())
    {
    }
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

    int Edge::from() const
    {
        return _v;
    }

    int Edge::to() const
    {
		return _w;
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
    bool Edge::invalid()
    {
        return _weight != _weight;
    }
    std::ostream & operator<<(std::ostream& out, const Edge & e)
    {
        out << e._v << '-' << e._w << ' ' << e._weight;
        return out;
    }
    DWGraph::DWGraph(int v): _v(v), _edge(0), _adj(v)
    {

    }
    DWGraph::DWGraph(std::ifstream & fin)
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
    int DWGraph::vertex() const
    {
        return _v;;
    }
    int DWGraph::edge() const
    {
        return _edge;
    }
    void DWGraph::addedge(const Edge & other)
    {
        _adj[other.from()].insert(other);
        ++_edge;
    }
    const DWGraph::edge_set & DWGraph::adj(int v) const
    {
        return _adj[v];
    }
}

