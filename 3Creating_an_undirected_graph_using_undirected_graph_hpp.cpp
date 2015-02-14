#include <boost/graph/undirected_graph.hpp>
#include <iostream>
using namespace boost;
using namespace std;
int main( )
{
    undirected_graph<>  g;
    //A vertex descriptor corresponds to a unique vertex in an abstract graph instance.
    undirected_graph<>::vertex_descriptor u = g.add_vertex();
    undirected_graph<>::vertex_descriptor v = g.add_vertex();
    undirected_graph<>::vertex_descriptor w = g.add_vertex();
    undirected_graph<>::vertex_descriptor x = g.add_vertex();

    //Adds edge (u,v) to the graph and returns the edge descriptor for the new edge. 
    add_edge(u, v, g);
    add_edge(u, w, g);
    add_edge(v, x, g);

    cout << "Degree of u: " << degree(u, g)<<"\n";
    
    return 0;
}
