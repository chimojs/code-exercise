#include "../../graph/dwg/dwgraph.h"
#include "../../graph/dwg/BellmanFordSP.h"
#include "../../graph/dwg/AcylicSP.h"
#include <sstream>
#include <iostream>
#include "CPM.h"

CPM::CPM() : distto_()
{
}

CPM::~CPM()
{
}

void CPM::Parse(std::ifstream & inf)
{
    const int LINELENGTH = 80;
    char line[LINELENGTH] = { 0 };
    inf.getline(line, LINELENGTH);
    int vertics = atoi(line);
    int s = 2 * vertics, t = 2 * vertics + 1;
    DirectedWeightedGraph::DWGraph g(2 * vertics + 2);
    

    for (int i = 0; i < vertics; ++i)
    {
        inf.getline(line, 80);
        bool ret  = inf.fail();
        std::stringstream strS;
        strS << line;

        double duration;
        strS >> duration;
        g.addedge(DirectedWeightedGraph::Edge(i, i + vertics, -duration));
        g.addedge(DirectedWeightedGraph::Edge(s, i, -0.0));
        g.addedge(DirectedWeightedGraph::Edge(i + vertics, t, -0.0));
        while (!strS.eof())
        {
            int successor;
            strS >> successor;
            g.addedge(DirectedWeightedGraph::Edge(i + vertics, successor, -0.0));
        }
    }

    DirectedWeightedGraph::BellmanFordSP sp(g, s);
    std::cout << "job   start  finish" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout.setf(std::ios::right);
    for (int i = 0; i < vertics; ++i)
    {
        std::cout.width(4);
        std::cout << i;
        std::cout.width(8);
        std::cout << fabs(sp.distTo(i));
        std::cout.width(8);
        std::cout << fabs(sp.distTo(i + vertics));
        std::cout << std::endl;
    }
    std::cout << "Finish Time: " << fabs(sp.distTo(t)) << std::endl;
}

double CPM::distTo(int v)
{
    return distto_[v];
}
