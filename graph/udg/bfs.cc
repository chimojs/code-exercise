#include<queue>
#include "bfs.h"

namespace UndirectedGraph {
    BFS::BFS(const Graph & g, int s) : _marked(), _count(0)
    {
        _marked.resize(g.vertex(), false);
        bfs(g, s);
    }
    bool BFS::marked(int v) const
    {
        return _marked[v];
    }
    int BFS::count() const
    {
        return _count;
    }
    void BFS::bfs(const Graph & g, int s)
    {
        std::queue<int> que;
        que.push(s);
        while (!que.empty())
        {
            int v = que.front();
            que.pop();
            for (int w : g.adj(v))
            {
                if (_marked[w]) continue;
                _marked[w] = true;
                ++_count;
                que.push(w);
            }
        }
    }
}