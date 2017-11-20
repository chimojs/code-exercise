#ifndef DG_Topological_H_
#define DG_Topological_H_
#include "dgraph.h"
#include <stack>

namespace DirectedDGraph {
    class Topological
    {
    public:
        Topological(const DGraph& g);
        bool isDAG();
        std::stack<int> order();
    private:
        void dfs(const DGraph& g, int s);
    private:
        std::vector<bool> _marked;
        std::stack<int> _order;
    };
}
#endif // DG_Topological_H_