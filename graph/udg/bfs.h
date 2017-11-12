#ifndef UDG_BFS_H_
#define UDG_BFS_H_
#include "graph.h"
namespace UndirectedGraph {
    class BFS
    {
    public:
        BFS(const Graph& g, int s);
        bool marked(int v) const;
        int count() const;
    private:
        void bfs(const Graph& g, int s);
    private:
        std::vector<bool> _marked;
        int _count;
    };
}
#endif // UDG_BFS_H_