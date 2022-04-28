 /*---------------------------------------------------
 Name: Zamam Moeez
 ID: 1665264
 CMPUT 275 , Winter 2022
 CCID: zamam

 Exercise 6 Part 2: Graph Concepts
 ---------------------------------------------------*/
#include <iostream>
#include <unordered_map>
#include <stack>
#include <string>
#include <sstream>
#include "digraph.h"

using namespace std;

/* void function that does DFS search on graph object 

Arguements:
Digraph& graph
int u: vertex
int prev: previous visited vertex
unordered_map<int, int>& reached: stores visited vertices 

Returns:
None

*/
void dfs(const Digraph & graph,
  const int u,
    const int prev, unordered_map < int, int > & reached) {
  if (reached.find(u) != reached.end())
    return;  // it was visited before
  reached[u] = prev;  // Iterate over all neighbours of u
  for (auto itr = graph.neighbours(u); itr != graph.endIterator(u); ++itr) {
    dfs(graph, * itr, u, reached);
  }
}

/* computes number of connected components in undirected graph

Arguements:
Digraph& graph

Returns:
unsigned int count

*/
unsigned int count_components(const Digraph & graph) {
  int count = 0;  // init count is 0
  vector < int > ver = graph.vertices();  // get vector of vertices
  unordered_map < int, int > new_search_tree;  // create searchtree
  int numvert = ver.size();  // obtain num of vertices
  for (int i = 0; i < numvert; i++) {  // if vertex not in tree
    if (new_search_tree.find(ver[i]) == new_search_tree.end()) {
      count += 1;  // increase count and obtain tree for new vertex
      dfs(graph, ver[i], ver[i], new_search_tree);
    }
  }
  return count;
}

/* reads input from stdin and creates Digraph object 

Arguements:
None

Returns:
Digraph graph

*/
Digraph read_city_graph_undirected() {
  Digraph graph;  // initialise graph object
  string line;  // initialise string
  while (getline(cin, line)) {  // while these is a line of text
    stringstream ss(line);  // create a string stream
    string Label, ID, v1, v2;  // init 3 substrings
    getline(ss, ID, ',');  // parse string and store substr in ID
    if (ID == "V") {  // if V store first vertex and add to graph
      getline(ss, v1, ',');
      graph.addVertex(stoi(v1));
    } else if (ID == "E") {  // if E get 2 vertices
      getline(ss, v1, ',');
      getline(ss, v2, ',');
      graph.addEdge(stoi(v1), stoi(v2));  // add edges
      graph.addEdge(stoi(v2), stoi(v1));  // in both directions
    }
  }
  return graph;  // return graph object
}

int main() {
  Digraph graph = read_city_graph_undirected();  // create graph
  cout << count_components(graph) << endl;  // print the count
}
