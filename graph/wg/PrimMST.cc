#include <map>
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

    EagerPrimMST::EagerPrimMST(const WGraph & wg)
        : _marked(), _mst(), _dist(), _weight(0.f), _edgeto(), _mp(wg.vertex())
    {
        _marked.resize(wg.vertex(), false);
        _edgeto.resize(wg.vertex(), Edge());
        _dist.resize(wg.vertex(), std::numeric_limits<double>::max());

        _mp.insert(0, 0.0);
        while (!_mp.empty())
        {
            int v = _mp.delmin();
            Edge e = _edgeto[v];
            if (!e.invalid())
            {
                _mst.push(e);
                _weight += e.weight();
            }
            visit(wg, v);
        }
    }
    std::queue<Edge> EagerPrimMST::edges() const
    {
        return _mst;
    }
    double EagerPrimMST::weight()
    {
        return _weight;
    }
    void EagerPrimMST::visit(const WGraph & wg, int v)
    {
        _marked[v] = true;
        for (auto& e : wg.adj(v))
        {
            int w = e.other(v);
            if (_marked[w]) continue;
            if (e.weight() < _dist[w])
            {
                _edgeto[w] = e;
                _dist[w] = e.weight();
                if (_mp.contains(w))
                    _mp.change(w, _dist[w]);
                else
                    _mp.insert(w, _dist[w]);
            }
        }

    }
}

