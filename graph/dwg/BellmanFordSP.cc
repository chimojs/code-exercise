#include "BellmanFordSP.h"
#include <queue>

namespace DirectedWeightedGraph {
    
    BellmanFordSP::BellmanFordSP(const DWGraph & g, int s)
        : edgeto_(), distto_(), cost_(0)
    {
        edgeto_.resize(g.vertex(), Edge());
        distto_.resize(g.vertex(), std::numeric_limits<double>::infinity());

        distto_[s] = 0.0;
        std::vector<bool> oq(g.vertex(), false);
        std::queue<int> vertics;
        vertics.push(s);
        oq[s] = true;
        while (!vertics.empty() && !hasNegativeCycle())
        {
            int v = vertics.front();
            vertics.pop();
            oq[v] = false;
            relax(g, v, vertics, oq);
        }
    }
    bool BellmanFordSP::hasPathTo(int v)
    {
        return distto_[v] < std::numeric_limits<double>::infinity();
    }
    double BellmanFordSP::distTo(int v)
    {
        return distto_[v];
    }
    std::stack<Edge> BellmanFordSP::pathTo(int v)
    {
        std::stack<Edge> edges;
        if (!hasPathTo(v)) return edges;
        for (Edge e = edgeto_[v]; !e.invalid(); e = edgeto_[e.from()])
            edges.push(e);
        return edges;
    }
    bool BellmanFordSP::hasNegativeCycle()
    {
        return false;
    }
    void BellmanFordSP::findNegativeCycle()
    {
    }
    void BellmanFordSP::relax(const DWGraph & g, int v, std::queue<int>& qe,
        std::vector<bool>& oq)
    {
        for (auto& e : g.adj(v))
        {
            int w = e.to();
            if (distto_[w] > distto_[v] + e.weight())
            {
                distto_[w] = distto_[v] + e.weight();
                edgeto_[w] = e;
                if (!oq[w])
                {
                    qe.push(w);
                    oq[w] = true;
                }
            }

            if (cost_++ % g.vertex() == 0)
                findNegativeCycle();
        }
    }
}

