#include "dfs.h"

namespace UndirectedGraph {
    DFS::DFS(const Graph & g, int s) : _marked(), _count(0)
    {
        _marked.resize(g.vertex(), false);
        dfs(g, s);
    }
    bool DFS::marked(int v) const
    {
        return _marked[v];
    }
    int DFS::count() const
    {
        return _count;
    }
    void DFS::dfs(const Graph & g, int s)
    {
        _marked[s] = true;
		++_count;
        for (int v : g.adj(s))
        {
            if (!_marked[v]) 
                dfs(g, v);
        }
    }
}