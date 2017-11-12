#include<fstream>
#include "graph.h"

int main(int argc, char* argv[])
{
	//Graph g(5);
	std::ifstream fin(argv[1]);
	Graph g(fin);
	int v = g.vertex();
	int e = g.edge();
	return 0;
}