#ifndef WG_PRIMMST_H_
#define WG_PRIMMST_H_
#include <queue>
#include <vector>
#include <functional>
#include "wgraph.h"

namespace WeightedGraph{
    class  LazyPrimMST
    {
    public:
        typedef WGraph::edge_set edge_set;
         LazyPrimMST(const WGraph& wg);
         std::queue<Edge> edges() const;
         double weight();
    private:
        void visit(const WGraph& wg, int v);
    private:
        std::vector<bool> _marked;
        std::queue<Edge> _mst;
        std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> _pq;
        double _weight;
    };
}
#endif // WG_PRIMMST_H_