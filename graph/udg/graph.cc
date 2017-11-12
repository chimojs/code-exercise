#include "graph.h"

Graph::Graph(int v) : _v(v), _edge(0), _adj(v)
{

}

Graph::Graph(std::ifstream& fin) : _v(0), _edge(0), _adj()
{
	fin >> _v;
	_adj.resize(_v);
	while (!fin.eof())
	{
		int v = -1, w = -1;
		fin >> v >> w;
		addedge(v, w);
	}
}

int Graph::vertex()
{
	return _v;
}

int Graph::edge()
{
	return _edge;
}

void Graph::addedge(int v, int w)
{
	_adj[v].insert(w);
	_adj[w].insert(v);
	++_edge;
}

const Graph::edge_set & Graph::adj(int v)
{
	return _adj[v];
}
