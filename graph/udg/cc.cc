#include "cc.h"

namespace UndirectedGraph {
    CC::CC(const Graph & g) : _marked(), _id(), _count(0)
    {
        _marked.resize(g.vertex(), false);
        _id.resize(g.vertex(), -1);
        for (int v = 0, c = g.vertex(); v < c; ++v)
        {
            if (!_marked[v])
            {
                dfs(g, v);
                ++_count;
            }
        }
    }
    int CC::id(int v) const
    {
        return _id[v];
    }
    int CC::count() const
    {
        return _count;
    }
    void CC::dfs(const Graph & g, int s)
    {
        _marked[s] = true;
        _id[s] = _count;
        for (int v : g.adj(s))
        {
            if (!_marked[v])
                dfs(g, v);
        }
    }
}