#ifndef UDG_DFS_H_
#define UDG_DFS_H_
#include "graph.h"
namespace UndirectedGraph {
    class DFS
    {
    public:
        DFS(const Graph& g, int s);
        bool marked(int v) const;
        int count() const;
    private:
        void dfs(const Graph& g, int s);
    private:
        std::vector<bool> _marked;
        int _count;
    };
}
#endif // UDG_DFS_H_