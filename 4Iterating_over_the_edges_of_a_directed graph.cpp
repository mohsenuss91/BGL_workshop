#include <iostream>
#include <boost/graph/adjacency_list.hpp>
using namespace boost;
using namespace std;
typedef boost::adjacency_list<listS, vecS, bidirectionalS> mygraph;

int main()
{
	mygraph g;
	add_edge (0, 1, g);
	add_edge (0, 3, g);
	add_edge (1, 2, g);
	add_edge (2, 3, g);
	mygraph::vertex_iterator vertexIt, vertexEnd;
	mygraph::in_edge_iterator inedgeIt, inedgeEnd;
	mygraph::in_edge_iterator outedgeIt, outedgeEnd; 
	tie(vertexIt, vertexEnd) = vertices(g);
	for (; vertexIt != vertexEnd; ++vertexIt)
	{
		cout << "incoming edges for " << *vertexIt << ": ";
		tie(inedgeIt, inedgeEnd) = in_edges(*vertexIt, g);
		for(; inedgeIt != inedgeEnd; ++inedgeIt)
		{
			cout << *inedgeIt << " ";
		}
		cout << "\n";
	}
	for (; vertexIt != vertexEnd; ++vertexIt)
	{
		cout << "out-edges for " << *vertexIt << ":" ;
		tie(outedgeIt, outedgeEnd) = out_edges(*vertexIt, g); // Similar to incoming edges
	}
}
