#ifndef WG_KRUSKALMST_H_
#define WG_KRUSKALMST_H_
#include <queue>
#include <map>
#include <vector>
#include <functional>
#include "wgraph.h"

namespace WeightedGraph{
    class  KrustralMST
    {
    public:
        typedef WGraph::edge_set edge_set;
        KrustralMST(const WGraph& wg);
        std::queue<Edge> edges() const;
        double weight();
    private:
        void addedges(const WGraph& wg);
    private:
        std::queue<Edge> _mst;
        std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> _pq;
        double _weight;
    };
}
#endif // WG_KRUSKALMST_H_