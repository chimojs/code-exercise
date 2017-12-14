#include "topological.hpp"
#include "AcylicSP.h"

namespace DirectedWeightedGraph {

    AcylicSP::AcylicSP(const DWGraph & g, int s)
        : edgeto_(), distto_()
    {
        edgeto_.resize(g.vertex(), Edge());
        distto_.resize(g.vertex(), std::numeric_limits<double>::infinity());

        distto_[s] = 0.0;
        Topological<DWGraph> ts(g);
        std::stack<int> vertics = ts.order();
        while (!vertics.empty())
        {
            int v = vertics.top();
            vertics.pop();
            relax(g, v);
        }
    }
    bool AcylicSP::hasPathTo(int v)
    {
        return distto_[v] < std::numeric_limits<double>::infinity();
    }
    double AcylicSP::distTo(int v)
    {
        return distto_[v];
    }
    std::stack<Edge> AcylicSP::pathTo(int v)
    {
        std::stack<Edge> edges;
        if (!hasPathTo(v)) return edges;
        for (Edge e = edgeto_[v]; !e.invalid(); e = edgeto_[e.from()])
            edges.push(e);
        return edges;
    }
    void AcylicSP::relax(const DWGraph & g, int v)
    {
        for (auto& e : g.adj(v))
        {
            int w = e.to();
            if (distto_[w] > distto_[v] + e.weight())
            {
                distto_[w] = distto_[v] + e.weight();
                edgeto_[w] = e;
            }
        }
    }
}

