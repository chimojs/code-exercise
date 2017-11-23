#include "../uf/union-find.h"
#include "KruskalMST.h"

namespace WeightedGraph {
    KrustralMST::KrustralMST(const WGraph & wg)
        : _mst(), _pq(), _weight(0.f)
    {
        addedges(wg);
        UnionFind uf(wg.vertex());

        while (!_pq.empty() && _mst.size() < static_cast<size_t>(wg.vertex() - 1))
        {
            Edge e = _pq.top();
            _pq.pop();
            int v = e.either(), w = e.other(v);
            if (uf.Connected(v, w)) continue;
            uf.Union(v, w);
            _mst.push(e);
            _weight += e.weight();
        }
    }
    std::queue<Edge> KrustralMST::edges() const
    {
        return _mst;
    }
    double KrustralMST::weight()
    {
        return _weight;
    }

    void KrustralMST::addedges(const WGraph & wg)
    {
        for (int v = 0; v < wg.vertex(); ++v)
        {
            for (auto& e : wg.adj(v))
            {
                int w = e.other(v);
                if (w > v)
                    _pq.push(e);
            }
        }
        
    }
}

