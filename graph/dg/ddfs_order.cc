#include "ddfs_order.h"

namespace DirectedDGraph {
    DepthFirstOrders::DepthFirstOrders(const DGraph & g)
        : _marked(), _preor(), _postor(), _reverse_postor()
    {
        _marked.resize(g.vertex(), false);
        for (int v = 0, c = g.vertex(); v < c; ++v)
        {
            if (!_marked[v])
                dfs(g, v);
        }
    }
    std::vector<int> DepthFirstOrders::preorder()
    {
        return _preor;
    }
    std::vector<int> DepthFirstOrders::postorder()
    {
        return _postor;
    }
    std::stack<int> DepthFirstOrders::reverse_postorder()
    {
        return _reverse_postor;
    }

    void DepthFirstOrders::dfs(const DGraph & g, int s)
    {
        _marked[s] = true;
        _preor.push_back(s);
        for (int v : g.adj(s))
        {
            if (!_marked[v])
                dfs(g, v);
        }
        _postor.push_back(s);
        _reverse_postor.push(s);
    }
}