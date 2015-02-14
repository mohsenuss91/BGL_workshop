#include <boost/graph/adjacency_list.hpp> 
using namespace boost; 
typedef boost::adjacency_list<
								listS, //std::list is a container that supports constant time insertion and removal of elements from anywhere
 								vecS, //std::vector is a sequence container that encapsulates dynamic size arrays.
							 	directedS //directed_selector 
							 > mygraph; 

int main() 
{ 
	mygraph g; 
	//Adds edge (u,v) to the graph and returns the edge descriptor for the new edge. 
	add_edge(0, 1, g); 
	add_edge (0, 3, g); 
	add_edge (1, 2, g); 
	add_edge (2, 3, g); 
}