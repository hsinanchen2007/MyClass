/*

https://www.educative.io/courses/grokking-the-coding-interview/m25rBmwLV00

Solution
The basic idea behind the topological sort is to provide a partial ordering among the vertices 
of the graph such that if there is an edge from U to V then U≤V i.e., U comes before V in the 
ordering. Here are a few fundamental concepts related to topological sort:

Source: Any node that has no incoming edge and has only outgoing edges is called a source.

Sink: Any node that has only incoming edges and no outgoing edge is called a sink.

So, we can say that a topological ordering starts with one of the sources and ends at one of 
the sinks.

A topological ordering is possible only when the graph has no directed cycles, i.e. if the graph 
is a Directed Acyclic Graph (DAG). If the graph has a cycle, some vertices will have cyclic 
dependencies which makes it impossible to find a linear ordering among vertices.

To find the topological sort of a graph we can traverse the graph in a Breadth First Search (BFS) 
way. We will start with all the sources, and in a stepwise fashion, save all sources to a sorted 
list. We will then remove all sources and their edges from the graph. After the removal of the 
edges, we will have new sources, so we will repeat the above process until all vertices are visited.

Here is the visual representation of this algorithm for Example-3:

 Add all sources to the sorted list. Remove all sources and their edges to find new sources  
 Add all sources to the sorted list. Remove all sources and their edges to find new sources  
    6   
    4   
    2   
    1   
    5   
    3   
    0   
 Sources: [5, 6]Topological Sort: ""  
    3   
    0   
    1   
    2   
    4   
 Sources: [3, 4]Topological Sort: "5, 6"  
    0   
    1   
    2   
 Sources: [0, 1, 2]Topological Sort: "5, 6, 3, 4"  
 All remaining vertices are source, so we will add them in the sorted list  
 Sources: []Topological Sort: "5, 6, 3, 4, 0, 1, 2"  
This is how we can implement this algorithm:

a. Initialization
    We will store the graph in Adjacency Lists, which means each parent vertex will have a list containing 
    all of its children. We will do this using a HashMap where the ‘key’ will be the parent vertex number 
    and the value will be a List containing children vertices.
    To find the sources, we will keep a HashMap to count the in-degrees i.e., count of incoming edges of each 
    vertex. Any vertex with ‘0’ in-degree will be a source.

b. Build the graph and find in-degrees of all vertices
    We will build the graph from the input and populate the in-degrees HashMap.

c. Find all sources
    All vertices with ‘0’ in-degrees will be our sources and we will store them in a Queue.

d. Sort
    For each source, do the following things:
    Add it to the sorted list.
    Get all of its children from the graph.
    Decrement the in-degree of each child by 1.
    If a child’s in-degree becomes ‘0’, add it to the sources Queue.
    Repeat step 1, until the source Queue is empty.

Time Complexity
In step ‘d’, each vertex will become a source only once and each edge will be accessed and removed once. 
Therefore, the time complexity of the above algorithm will be O(V+E), where ‘V’ is the total number of 
vertices and ‘E’ is the total number of edges in the graph.

Space Complexity
The space complexity will be O(V+E), since we are storing all of the edges for each vertex in an adjacency 
list.

*/

using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TopologicalSort {
 public:
  static vector<int> sort(int vertices, const vector<vector<int>>& edges) {
    vector<int> sortedOrder;
    if (vertices <= 0) {
      return sortedOrder;
    }

    // a. Initialize the graph
    unordered_map<int, int> inDegree;       // count of incoming edges for every vertex
    unordered_map<int, vector<int>> graph;  // adjacency list graph
    for (int i = 0; i < vertices; i++) {
      inDegree[i] = 0;
      graph[i] = vector<int>();
    }

    // b. Build the graph
    for (int i = 0; i < edges.size(); i++) {
      int parent = edges[i][0], child = edges[i][1];
      graph[parent].push_back(child);  // put the child into it's parent's list
      inDegree[child]++;               // increment child's inDegree
    }

    // c. Find all sources i.e., all vertices with 0 in-degrees
    queue<int> sources;
    for (auto entry : inDegree) {
      if (entry.second == 0) {
        sources.push(entry.first);
      }
    }

    // d. For each source, add it to the sortedOrder and subtract one from all of its children's
    // in-degrees if a child's in-degree becomes zero, add it to the sources queue
    while (!sources.empty()) {
      int vertex = sources.front();
      sources.pop();
      sortedOrder.push_back(vertex);
      vector<int> children =
          graph[vertex];  // get the node's children to decrement their in-degrees
      for (auto child : children) {
        inDegree[child]--;
        if (inDegree[child] == 0) {
          sources.push(child);
        }
      }
    }

    if (sortedOrder.size() !=
        vertices) {  // topological sort is not possible as the graph has a cycle
      return vector<int>();
    }

    return sortedOrder;
  }
};

int main(int argc, char* argv[]) {
  vector<int> result =
      TopologicalSort::sort(4, vector<vector<int>>{vector<int>{3, 2}, vector<int>{3, 0},
                                                   vector<int>{2, 0}, vector<int>{2, 1}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = TopologicalSort::sort(
      5, vector<vector<int>>{vector<int>{4, 2}, vector<int>{4, 3}, vector<int>{2, 0},
                             vector<int>{2, 1}, vector<int>{3, 1}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = TopologicalSort::sort(
      7, vector<vector<int>>{vector<int>{6, 4}, vector<int>{6, 2}, vector<int>{5, 3},
                             vector<int>{5, 4}, vector<int>{3, 0}, vector<int>{3, 1},
                             vector<int>{3, 2}, vector<int>{4, 1}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
