#include <iostream>
#include <boost/graph/adjacency_list.hpp>
using namespace boost;
using namespace std;

typedef boost::adjacency_list<
                                listS, //std::list is a container that supports constant time insertion and removal of elements from anywhere
                                vecS, //std::vector is a sequence container that encapsulates dynamic size arrays.
                                undirectedS //undirected_selector 
                             > mygraph; 

int main()
{
    mygraph g;
    //Adds edge (u,v) to the graph and returns the edge descriptor for the new edge. 
    add_edge (0, 1, g);
    add_edge (0, 3, g);
    add_edge (1, 2, g);
    add_edge (2, 3, g);

    // vertex_iterator provides access to all of the vertices in a graph. 
    mygraph::vertex_iterator vertexIt, vertexEnd;
    // adjacency_iterator implements the member functions and operators required of the Random Access Iterator concep
    mygraph::adjacency_iterator neighbourIt, neighbourEnd; 
    //The adjacency iterator adaptor transforms an out_edge_iterator into an adjacency iterator.
    tie(vertexIt, vertexEnd) = vertices(g);

    for (; vertexIt != vertexEnd; ++vertexIt)
    {
        cout << *vertexIt << " is connected with ";
        tie(neighbourIt, neighbourEnd) = adjacent_vertices(*vertexIt, g);
        for (; neighbourIt != neighbourEnd; ++neighbourIt) cout << *neighbourIt << " ";
        cout << "\n";
    }
}
