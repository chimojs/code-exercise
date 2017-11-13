#include "dgraph.h"
namespace DirectedDGraph {
    DGraph::DGraph(int v) : _v(v), _edge(0), _adj(v)
    {
    }
    DGraph::DGraph(std::ifstream& fin) : _v(0), _edge(0), _adj()
    {
        fin >> _v;
        _adj.resize(_v);
        while (!fin.eof())
        {
            int v = -1, w = -1;
            fin >> v >> w;
            addedge(v, w);
        }
    }
    DGraph::DGraph(const DGraph& other)
    {
        *this = other;
    }

    DGraph::DGraph(DGraph&& other)
    {
        *this = std::move(other);
    }
    int DGraph::vertex() const
    {
        return _v;
    }
    int DGraph::edge() const
    {
        return _edge;
    }
    void DGraph::addedge(int v, int w)
    {
        _adj[v].insert(w);
        ++_edge;
    }
    const DGraph::edge_set & DGraph::adj(int v) const
    {
        return _adj[v];
    }
    DGraph DGraph::reverse()
    {
        DGraph dr(_v);
        for (int v = 0; v < _v; ++v)
        {
            for (int w : adj(v))
            {
                dr.addedge(w, v);
            }
        }
        return dr;
    }
    DGraph & DGraph::operator=(const DGraph & other)
    {
        _v = other._v;
        _edge = other._edge;
        _adj = other._adj;
        return *this;
    }
    DGraph & DGraph::operator=(DGraph && other)
    {
        _v = other._v;
        _edge = other._edge;
        _adj = std::move(other._adj);
        return *this;
    }
}
