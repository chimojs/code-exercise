#ifndef DG_SCC_H_
#define DG_SCC_H_
#include "dgraph.h"
namespace DirectedDGraph {
    class SCC
    {
    public:
        SCC(const DGraph& g);
        bool strongconnected(int v, int w) const;
        int count() const;
        int id(int v) const;
    private:
        void dfs(const DGraph& g, int s);
    private:
        std::vector<bool> _marked;
        std::vector<int> _id;
        int _count;
    };
}
#endif // DG_SCC_H_