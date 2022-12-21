/*

https://www.educative.io/courses/grokking-the-coding-interview/m20NY0Rwz7A

Solution 
Since each sequence in the given array defines the ordering of some numbers, we need to combine 
all these ordering rules to find two things:

Is it possible to construct the originalSeq from all these rules?
Are these ordering rules not sufficient enough to define the unique ordering of all the numbers 
in the originalSeq? In other words, can these rules result in more than one sequence?

Take Example-1:

originalSeq: [1, 2, 3, 4], seqs:[[1, 2], [2, 3], [3, 4]]
The first sequence tells us that ‘1’ comes before ‘2’; the second sequence tells us that ‘2’ comes 
before ‘3’; the third sequence tells us that ‘3’ comes before ‘4’. Combining all these sequences 
will result in a unique sequence: [1, 2, 3, 4].

The above explanation tells us that we are actually asked to find the topological ordering of all 
the numbers and also to verify that there is only one topological ordering of the numbers possible 
from the given array of the sequences.

This makes the current problem similar to Tasks Scheduling Order with two differences:

We need to build the graph of the numbers by comparing each pair of numbers in the given array of sequences.
We must perform the topological sort for the graph to determine two things:

Can the topological ordering construct the originalSeq?
That there is only one topological ordering of the numbers possible. This can be confirmed if we do 
not have more than one source at any time while finding the topological ordering of numbers.

Time complexity
In step ‘d’, each number can become a source only once and each edge (a rule) will be accessed and 
removed once. Therefore, the time complexity of the above algorithm will be O(V+E), where ‘V’ is the 
count of distinct numbers and ‘E’ is the total number of the rules. Since, at most, each pair of numbers 
can give us one rule, we can conclude that the upper bound for the rules is O(N) where ‘N’ is the count 
of numbers in all sequences. So, we can say that the time complexity of our algorithm is O(V+N).

Space complexity
The space complexity will be O(V+N), since we are storing all of the rules for each number in an adjacency 
list.

*/

using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class SequenceReconstruction {
 public:
  static bool canConstruct(const vector<int> &originalSeq, const vector<vector<int>> &sequences) {
    vector<int> sortedOrder;
    if (originalSeq.size() <= 0) {
      return false;
    }

    // a. Initialize the graph
    unordered_map<int, int> inDegree;       // count of incoming edges for every vertex
    unordered_map<int, vector<int>> graph;  // adjacency list graph
    for (auto seq : sequences) {
      for (int i = 0; i < seq.size(); i++) {
        inDegree[seq[i]] = 0;
        graph[seq[i]] = vector<int>();
      }
    }

    // b. Build the graph
    for (auto seq : sequences) {
      for (int i = 1; i < seq.size(); i++) {
        int parent = seq[i - 1], child = seq[i];
        graph[parent].push_back(child);
        inDegree[child]++;
      }
    }

    // if we don't have ordering rules for all the numbers we'll not able to uniquely construct the
    // sequence
    if (inDegree.size() != originalSeq.size()) {
      return false;
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
      if (sources.size() > 1) {
        return false;  // more than one sources mean, there is more than one way to reconstruct the
                       // sequence
      }
      if (originalSeq[sortedOrder.size()] != sources.front()) {
        return false;  // the next source (or number) is different from the original sequence
      }
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

    // if sortedOrder's size is not equal to original sequence's size, there is no unique way to
    // construct
    return sortedOrder.size() == originalSeq.size();
  }
};

int main(int argc, char *argv[]) {
  bool result = SequenceReconstruction::canConstruct(
      vector<int>{1, 2, 3, 4},
      vector<vector<int>>{vector<int>{1, 2}, vector<int>{2, 3}, vector<int>{3, 4}});
  cout << "Can we uniquely construct the sequence: " << result << endl;

  result = SequenceReconstruction::canConstruct(
      vector<int>{1, 2, 3, 4},
      vector<vector<int>>{vector<int>{1, 2}, vector<int>{2, 3}, vector<int>{2, 4}});
  cout << "Can we uniquely construct the sequence: " << result << endl;

  result = SequenceReconstruction::canConstruct(
      vector<int>{3, 1, 4, 2, 5},
      vector<vector<int>>{vector<int>{3, 1, 5}, vector<int>{1, 4, 2, 5}});
  cout << "Can we uniquely construct the sequence: " << result << endl;
}
