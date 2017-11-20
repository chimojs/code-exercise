#ifndef DG_CycleDetected_H_
#define DG_CycleDetected_H_
#include "dgraph.h"
namespace DirectedDGraph {
    class CycleDetected
    {
    public:
        CycleDetected(const DGraph& g);
        bool hascycle() const;
        std::vector<int> cycle() const;
    private:
        void dfs(const DGraph& g, int s);
    private:
        std::vector<bool> _marked;
        std::vector<bool> _onstack;
        std::vector<int> _cycle;
        std::vector<int> _edgeto;
        bool _hascycle;
    };
}
#endif // DG_CycleDetected_H_