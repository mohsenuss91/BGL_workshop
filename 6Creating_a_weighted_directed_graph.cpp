#include <boost/graph/adjacency_list.hpp>
using namespace boost;
typedef property<edge_weight_t, int> EdgeWeightProperty;
typedef boost::adjacency_list<listS, vecS, directedS, no_property,EdgeWeightProperty > mygraph;
int main()
{
mygraph g;
add_edge (0, 1, 8, g);
add_edge (0, 3, 18, g);
add_edge (1, 2, 20, g);
add_edge (2, 3, 2, g);
add_edge (3, 1, 1, g);
add_edge (1, 3, 7, g);
}
