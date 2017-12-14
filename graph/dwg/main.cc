#include<fstream>
#include <vector>
#include <iostream>
#include "dwgraph.h"
#include "DijkstraSP.h"
#include "AcylicSP.h"

int main(int argc, char* argv[])
{
	std::ifstream fin(argv[1]);
	DirectedWeightedGraph::DWGraph g(fin);
	DirectedWeightedGraph::DijkstralSP sp(g, 5);
	int v = 6;
	bool haspath = sp.hasPathTo(v);
	std::stack<DirectedWeightedGraph::Edge> edges = sp.pathTo(v);
	while (!edges.empty())
	{
		auto& e = edges.top();
		std::cout << e << std::endl;
		edges.pop();
	}
	std::cout << sp.distTo(v) << std::endl;
	getchar();
	return 0;
}