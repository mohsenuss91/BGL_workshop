#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <iostream>
using namespace std;
using namespace boost;
typedef property<edge_weight_t, int>
EdgeWeightProperty;
typedef boost::adjacency_list
< listS, vecS, undirectedS, no_property, EdgeWeightProperty>
mygraph;
class custom_dfs_visitor : public boost::default_dfs_visitor
{ public: template < typename Vertex, typename Graph >
void discover_vertex(Vertex u, const Graph & g)
const { std::cout << "At " << u << std::endl; }
template < typename Edge, typename Graph >
void examine_edge(Edge e, const Graph& g)
const { std::cout << "Examining edges " << e << std::endl;
}
};
int main()
{
mygraph g;
add_edge (0, 1, 8, g);
add_edge (0, 3, 18, g);
add_edge (1, 2, 20, g);
add_edge (2, 3, 2, g);
add_edge (3, 1, 1, g);
add_edge (1, 3, 7, g);
custom_dfs_visitor vis;
depth_first_search(g, visitor(vis));
}
