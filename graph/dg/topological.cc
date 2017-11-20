#include "topological.h"
#include "dcycle.h"

namespace DirectedDGraph {
	Topological::Topological(const DGraph & g) : _marked(), _order()
	{
		_marked.resize(g.vertex(), false);
		CycleDetected cyclefinder(g);
		if (!cyclefinder.hascycle())
		{
			for (int v = 0, c = g.vertex(); v < c; ++v)
			{
				if (!_marked[v])
					dfs(g, v);
			}
		}
	}
	bool Topological::isDAG()
	{
		return !_order.empty();
	}
	std::stack<int> Topological::order()
	{
		return _order;
	}
	void Topological::dfs(const DGraph & g, int s)
	{
		_marked[s] = true;
		for (int v : g.adj(s))
		{
			if (!_marked[v])
				dfs(g, v);
		}
		_order.push(s);
	}
}