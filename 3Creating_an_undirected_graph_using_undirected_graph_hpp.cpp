#include <boost/graph/undirected_graph.hpp>
#include <iostream>
using namespace boost;
using namespace std;
int main( )
{
    undirected_graph<>g;
    undirected_graph<>::vertex_descriptor u = g.add_vertex();
    undirected_graph<>::vertex_descriptor v = g.add_vertex();
    undirected_graph<>::vertex_descriptor w = g.add_vertex();
    undirected_graph<>::vertex_descriptor x = g.add_vertex();
    add_edge(u, v, g);
    add_edge(u, w, g);
    add_edge(v, x, g);
    cout << "Degree of u: " << degree(u, g)<<"\n";
    return 0;
}
