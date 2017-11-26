#include "DijkstraSP.h"

namespace DirectedWeightedGraph {
    /**
    Algorithm 4 : "Dijkstra's algorithm solves the single source shortest-paths 
    problem in edge-weighted diagraphs with non nonnegative weights".
    **/
    DijkstralSP::DijkstralSP(const DWGraph & g, int s)
        : edgeto_(), distto_(), pq_(g.vertex())
    {
        edgeto_.resize(g.vertex(), Edge());
        distto_.resize(g.vertex(), std::numeric_limits<double>::infinity());

        distto_[s] = 0.0;
        pq_.insert(s, 0);
        while (!pq_.empty())
            relax(g, pq_.delmin());
    }
    bool DijkstralSP::hasPathTo(int v)
    {
        return distto_[v] < std::numeric_limits<double>::infinity();
    }
    double DijkstralSP::distTo(int v)
    {
        return distto_[v];
    }
    std::stack<Edge> DijkstralSP::pathTo(int v)
    {
        std::stack<Edge> edges;
        if (!hasPathTo(v)) return edges;
        for (Edge e = edgeto_[v]; !e.invalid(); e = edgeto_[e.from()])
            edges.push(e);
        return edges;
    }
    void DijkstralSP::relax(const DWGraph & g, int v)
    {
        for (auto& e : g.adj(v))
        {
            int w = e.to();
            if (distto_[w] > distto_[v] + e.weight())
            {
                distto_[w] = distto_[v] + e.weight();
                edgeto_[w] = e;
                if (pq_.contains(w))
                    pq_.change(w, distto_[w]);
                else
                    pq_.insert(w, distto_[w]);
            }
        }
    }
}

