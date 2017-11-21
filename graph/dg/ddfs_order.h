#ifndef DG_DFSORDER_H_
#define DG_DFSORDER_H_
#include <stack>
#include "dgraph.h"

namespace DirectedDGraph {
    class DepthFirstOrders
    {
    public:
        DepthFirstOrders(const DGraph& g);
        std::vector<int> preorder();
        std::vector<int> postorder();
        std::stack<int> reverse_postorder();
    private:
        void dfs(const DGraph & g, int s);
    private:
        std::vector<bool> _marked;
        std::vector<int> _preor;
        std::vector<int> _postor;
        std::stack<int> _reverse_postor;

    };
}
#endif // DG_DFSORDER_H_