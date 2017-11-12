#ifndef UDG_BFS_H_
#define UDG_BFS_H_
#include "graph.h"
namespace UndirectedGraph {
    class CC
    {
    public:
        CC(const Graph& g);
        int id(int v) const;
        int count() const;
    private:
        void dfs(const Graph& g, int s);
    private:
        std::vector<bool> _marked;
        std::vector<int> _id;
        int _count;
    };
}
#endif // UDG_BFS_H_