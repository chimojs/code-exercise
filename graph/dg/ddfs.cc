#include "ddfs.h"

namespace DirectedDGraph {
    DFS::DFS(const DGraph & g, int s) : _marked()
    {
        _marked.resize(g.vertex(), false);
        dfs(g, s);
    }
    bool DFS::marked(int v) const
    {
        return _marked[v];
    }
    void DFS::dfs(const DGraph & g, int s)
    {
        _marked[s] = true;
        for (int v : g.adj(s))
        {
            if (!_marked[v]) 
                dfs(g, v);
        }
    }
}