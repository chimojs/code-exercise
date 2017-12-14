#ifndef DG_Topological_H_
#define DG_Topological_H_
#include <stack>
#include <vector>
namespace DirectedWeightedGraph {
    template<typename _DG>
    class Topological
    {
    public:
        Topological(const _DG& g) : _marked(), _order()
        {
            _marked.resize(g.vertex(), false);
            //assume there is no cycle in graph
            //CycleDetected cyclefinder(g);
            //if (!cyclefinder.hascycle())
            for (int v = 0, c = g.vertex(); v < c; ++v)
            {
                if (!_marked[v])
                    dfs(g, v);
            }
        }
        bool isDAG()
        {
            return !_order.empty();
        }
        std::stack<int> order()
        {
            return _order;
        }
    private:
        void dfs(const _DG& g, int s)
        {
            _marked[s] = true;
            for (auto& e : g.adj(s))
            {
                int v = e.to();
                if (!_marked[v])
                    dfs(g, v);
            }
            _order.push(s);
        }
    private:
        std::vector<bool> _marked;
        std::stack<int> _order;
    };
}
#endif // DG_Topological_H_