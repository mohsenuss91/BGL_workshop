#include <boost/graph/adjacency_list.hpp> 
using namespace boost; 
typedef boost::adjacency_list<listS, vecS, directedS> mygraph; 

int main() 
{ 
	mygraph g; 
	add_edge(0, 1, g); 
	add_edge (0, 3, g); 
	add_edge (1, 2, g); 
	add_edge (2, 3, g); 
}