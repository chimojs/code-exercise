#include "dcycle.h"

namespace DirectedDGraph {
    CycleDetected::CycleDetected(const DGraph & g) : _marked(), _onstack()
                                                    ,_hascycle(false)
    {
        _marked.resize(g.vertex(), false);
        _onstack.resize(g.vertex(), false);
        _edgeto.resize(g.vertex(), -1);
        for (int v = 0, c = g.vertex(); v < c; ++v)
        {
            if (!_marked[v])
                dfs(g, v);
        }
    }

    bool CycleDetected::hascycle() const
    {
        return _hascycle;
    }

    std::vector<int> CycleDetected::cycle() const
    {
        return _cycle;
    }

    void CycleDetected::dfs(const DGraph & g, int s)
    {   
        _marked[s] = true;
        _onstack[s] = true;
        for (int v : g.adj(s))
        {
            if (_hascycle) return;
            if (!_marked[v])
            {
                _edgeto[v] = s;
                dfs(g, v);
            }
            if (_onstack[v])
            {
                _hascycle = true;
                for (int x = s; x != v; x = _edgeto[x])
                    _cycle.push_back(x);
                _cycle.push_back(v);
                _cycle.push_back(s);
            }
        }
        _onstack[s] = false;
    }
}