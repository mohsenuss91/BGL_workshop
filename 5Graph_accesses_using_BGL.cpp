#include <iostream>
#include <boost/graph/adjacency_list.hpp>
using namespace boost;
using namespace std;
typedef property<edge_weight_t, int> EdgeWeightProperty;
typedef property<edge_weight_t, int> EdgeWeightProperty;
typedef boost::adjacency_list < listS, vecS, undirectedS, no_property, EdgeWeightProperty> mygraph;
int main()
{
    mygraph g;
    add_edge (0, 1, 8, g);
    add_edge (0, 3, 18, g);
    add_edge (1, 2, 20, g);
    add_edge (2, 3, 2, g);
    add_edge (3, 1, 1, g);
    add_edge (1, 3, 7, g);
    cout << "Number of edges: " << num_edges(g) << "\n";
    cout << "Number of vertices: " << num_vertices(g) << "\n";
    mygraph::vertex_iterator vertexIt, vertexEnd;
    tie(vertexIt, vertexEnd) = vertices(g);
    for (; vertexIt != vertexEnd; ++vertexIt)
    {
        std::cout << "in-degree for " << *vertexIt << ": "<< in_degree(*vertexIt, g) << "\n";
        std::cout << "out-degree for " << *vertexIt << ": "<< out_degree(*vertexIt, g) << "\n";
    }
    mygraph::edge_iterator edgeIt, edgeEnd;
    tie(edgeIt, edgeEnd) = edges(g);
    for (; edgeIt!= edgeEnd; ++edgeIt)
    {
        std::cout << "edge " << source(*edgeIt, g) << "-->"<< target(*edgeIt, g) << "\n";
    }
}
