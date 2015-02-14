#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/filtered_graph.hpp>
#include <boost/graph/graph_utility.hpp>
using namespace boost;
using namespace std;
//In this example we will filter a graph's edges based on edge weight. We will keep all edges with positive edge weight. 
//First, we create a predicate function object.

//"typename" is used for specifying that a dependent name in a template definition or declaration is a type.
template <typename EdgeWeightMap>
struct positive_edge_weight 
{
  //constructor
  positive_edge_weight() { }
  positive_edge_weight(EdgeWeightMap weight) : m_weight(weight) { }
  
  template <typename Edge>

  bool operator()(const Edge& e) const 
  {
    //testing if weight is positive
    return 0 < get(m_weight, e);
  }
  
  EdgeWeightMap m_weight;
};

//Now we create a graph and print out the filtered graph.
int main()
{

  //defining the graph by an adjacency_list
  typedef adjacency_list<vecS, vecS, directedS, no_property, property<edge_weight_t, int> > Graph;

  //define a syntax for mapping key objects (edge_weight_t) to corresponding value objects (EdgeWeightMap). 
  typedef property_map<Graph, edge_weight_t>::type EdgeWeightMap;

  // a distinct type whose value is restricted to one of several explicitly named constants 
  enum { A, B, C, D, E, N };

  const char* name = "ABCDE";

  Graph g(N);
  add_edge(A, B, 2, g);
  add_edge(A, C, 4, g);
  add_edge(C, D, 1, g);
  add_edge(D, B, -3, g);
  add_edge(C, E, 0, g);
  add_edge(E, C, 0, g);

  //filter()bprocesses a data structure (typically a list) in some order to produce a new data structure containing exactly those elements of the original data structure.
  positive_edge_weight<EdgeWeightMap> filter(get(edge_weight, g));
  filtered_graph<Graph, positive_edge_weight<EdgeWeightMap> > fg(g, filter);

  cout << "filtered edge set: ";
  print_edges(fg, name);

  cout << "filtered out-edges:" << endl;
  print_graph(fg, name);

  return 0;
}
