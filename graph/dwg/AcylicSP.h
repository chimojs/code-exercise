#ifndef WG_ACYLICSP_H_
#define WG_ACYLICSP_H_
#include <stack>
#include <vector>
#include "dwgraph.h"
#include "../wg/IndexMinPQ.hpp"
namespace DirectedWeightedGraph{
    class AcylicSP
    {
    public:
        AcylicSP(const DWGraph& g, int s);
        bool hasPathTo(int v);
        double distTo(int v);
        std::stack<Edge> pathTo(int v);
    private:
        void relax(const DWGraph& g, int v);
    private:
        std::vector<Edge> edgeto_;
        std::vector<double> distto_;
    };
   }
#endif // WG_ACYLICSP_H_