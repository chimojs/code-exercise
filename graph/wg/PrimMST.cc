#include "PrimMST.h"

namespace WeightedGraph {
    LazyPrimMST::LazyPrimMST(const WGraph & wg) 
        : _marked(), _mst(), _pq(), _weight(0.f)
    {
        _marked.resize(wg.vertex(), false);
        visit(wg, 0);
        while (_pq.size())
        {
            Edge e = _pq.top();
            _pq.pop();
            int v = e.either(), w = e.other(v);
            if (_marked[v] && _marked[w]) continue;
            _mst.push(e);
            _weight += e.weight();
            if (!_marked[v]) visit(wg, v);
            if (!_marked[w]) visit(wg, w);
        }
    }
    std::queue<Edge> LazyPrimMST::edges() const
    {
        return _mst;
    }
    double LazyPrimMST::weight()
    {
        return _weight;
    }
    void LazyPrimMST::visit(const WGraph & wg, int v)
    {
        _marked[v] = true;
        for (auto& e : wg.adj(v))
            if (!_marked[e.other(v)]) _pq.push(e);
    }
}

