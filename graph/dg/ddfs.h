#ifndef UDG_DFS_H_
#define UDG_DFS_H_
#include "dgraph.h"
namespace DirectedDGraph {
    class DFS
    {
    public:
        DFS(const DGraph& g, int s);
        bool marked(int v) const;
    private:
        void dfs(const DGraph& g, int s);
    private:
        std::vector<bool> _marked;
    };
}
#endif // UDG_DFS_H_