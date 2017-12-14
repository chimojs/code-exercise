#ifndef WG_BELLMANFORDSP_H_
#define WG_BELLMANFORDSP_H_
#include <stack>
#include <vector>
#include <queue>
#include "dwgraph.h"

namespace DirectedWeightedGraph{
    class BellmanFordSP
    {
    public:
        BellmanFordSP(const DWGraph& g, int s);
        bool hasPathTo(int v);
        double distTo(int v);
        std::stack<Edge> pathTo(int v);

        //TODO:
        bool hasNegativeCycle();
        void findNegativeCycle();
    private:
        void relax(const DWGraph& g, int v, std::queue<int>& qe,
            std::vector<bool>& oq);
    private:
        int cost_;
        std::vector<Edge> edgeto_;
        std::vector<double> distto_;
    };
   }
#endif // WG_BELLMANFORDSP_H_