#ifndef WG_DIJKSTRALSP_H_
#define WG_DIJKSTRALSP_H_
#include <stack>
#include <vector>
#include "dwgraph.h"
#include "../wg/IndexMinPQ.hpp"
namespace DirectedWeightedGraph{
    class DijkstralSP
    {
    public:
        DijkstralSP(const DWGraph& g, int s);
        bool hasPathTo(int v);
        double distTo(int v);
        std::stack<Edge> pathTo(int v);
    private:
        void relax(const DWGraph& g, int v);
    private:
        std::vector<Edge> edgeto_;
        std::vector<double> distto_;
        WeightedGraph::IndexMinPQ<double> pq_;
    };
   }
#endif // WG_DIJKSTRALSP_H_