/*

https://www.educative.io/courses/grokking-the-coding-interview/BnnArPGKolJ

Solution
This problem is similar to Tasks Scheduling, the only difference being that we need to find 
the best ordering of tasks so that it is possible to schedule them all.

Time complexity
In step ‘d’, each task can become a source only once and each edge (prerequisite) will be 
accessed and removed once. Therefore, the time complexity of the above algorithm will be O(V+E)
, where ‘V’ is the total number of tasks and ‘E’ is the total number of prerequisites.

Space complexity
The space complexity will be O(V+E), since we are storing all of the prerequisites for each 
task in an adjacency list.

Similar Problems
Course Schedule: There are ‘N’ courses, labeled from ‘0’ to ‘N-1’. Each course has some 
prerequisite courses which need to be completed before it can be taken. Given the number of 
courses and a list of prerequisite pairs, write a method to find the best ordering of the 
courses that a student can take in order to finish all courses.

Solution: This problem is exactly similar to our parent problem. In this problem, we have 
courses instead of tasks.

*/

using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TaskSchedulingOrder {
 public:
  static vector<int> findOrder(int tasks, const vector<vector<int>>& prerequisites) {
    vector<int> sortedOrder;
    if (tasks <= 0) {
      return sortedOrder;
    }

    // a. Initialize the graph
    unordered_map<int, int> inDegree;       // count of incoming edges for every vertex
    unordered_map<int, vector<int>> graph;  // adjacency list graph
    for (int i = 0; i < tasks; i++) {
      inDegree[i] = 0;
      graph[i] = vector<int>();
    }

    // b. Build the graph
    for (int i = 0; i < prerequisites.size(); i++) {
      int parent = prerequisites[i][0], child = prerequisites[i][1];
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

    // if sortedOrder doesn't contain all tasks, there is a cyclic dependency between tasks,
    // therefore, we will not be able to schedule all tasks
    if (sortedOrder.size() != tasks) {
      return vector<int>();
    }

    return sortedOrder;
  }
};

int main(int argc, char* argv[]) {
  vector<int> result =
      TaskSchedulingOrder::findOrder(3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = TaskSchedulingOrder::findOrder(
      3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}, vector<int>{2, 0}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = TaskSchedulingOrder::findOrder(
      6, vector<vector<int>>{vector<int>{2, 5}, vector<int>{0, 5}, vector<int>{0, 4},
                             vector<int>{1, 4}, vector<int>{3, 2}, vector<int>{1, 3}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
