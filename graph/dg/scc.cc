#include "scc.h"
#include "ddfs_order.h"

namespace DirectedDGraph {
    SCC::SCC(const DGraph & g) : _marked(), _id(), _count()
    {
        _marked.resize(g.vertex(), false);
        _id.resize(g.vertex(), -1);
        DepthFirstOrders dfsor(g.reverse());
        std::stack<int> reverse_order = dfsor.reverse_postorder();

        while (!reverse_order.empty())
        {
            int v = reverse_order.top();
            if (!_marked[v])
            {
                dfs(g, v);
                ++_count;
            }
            reverse_order.pop();
        }
    }
    bool SCC::strongconnected(int v, int w) const
    {
        return _id[v] == _id[w];
    }
    int SCC::count() const
    {
        return _count;
    }
    int SCC::id(int v) const
    {
        return _id[v];
    }
    void SCC::dfs(const DGraph & g, int s)
    {
        _marked[s] = true;
        _id[s] = _count;
        for (int v : g.adj(s))
        {
            if (!_marked[v])
            {
                dfs(g, v);
            }
        }
    }
}