/*

https://www.educative.io/courses/grokking-the-coding-interview/R8AJWOMxw2q

Solution 
Since the given words are sorted lexicographically by the rules of the alien language, 
we can always compare two adjacent words to determine the ordering of the characters. 
Take Example-1 above: [“ba”, “bc”, “ac”, “cab”]

Take the first two words “ba” and “bc”. Starting from the beginning of the words, find 
the first character that is different in both words: it would be ‘a’ from “ba” and ‘c’ 
from “bc”. Because of the sorted order of words (i.e. the dictionary!), we can conclude 
that ‘a’ comes before ‘c’ in the alien language.

Similarly, from “bc” and “ac”, we can conclude that ‘b’ comes before ‘a’.
These two points tell us that we are actually asked to find the topological ordering of 
the characters, and that the ordering rules should be inferred from adjacent words from 
the alien dictionary.

This makes the current problem similar to Tasks Scheduling Order, the only difference 
being that we need to build the graph of the characters by comparing adjacent words first, 
and then perform the topological sort for the graph to determine the order of the characters.

Time complexity
In step ‘d’, each task can become a source only once and each edge (a rule) will be accessed 
and removed once. Therefore, the time complexity of the above algorithm will be O(V+E), 
where ‘V’ is the total number of different characters and ‘E’ is the total number of the rules 
in the alien language. Since, at most, each pair of words can give us one rule, therefore, 
we can conclude that the upper bound for the rules is O(N) where ‘N’ is the number of words 
in the input. So, we can say that the time complexity of our algorithm is O(V+N).

Space complexity
The space complexity will be O(V+N), since we are storing all of the rules for each character 
in an adjacency list.

*/

using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class AlienDictionary {
 public:
  static string findOrder(const vector<string> &words) {
    if (words.empty() || words.empty()) {
      return "";
    }

    // a. Initialize the graph
    unordered_map<char, int> inDegree;        // count of incoming edges for every vertex
    unordered_map<char, vector<char>> graph;  // adjacency list graph
    for (auto word : words) {
      for (char character : word) {
        inDegree[character] = 0;
        graph[character] = vector<char>();
      }
    }

    // b. Build the graph
    for (int i = 0; i < words.size() - 1; i++) {
      string w1 = words[i], w2 = words[i + 1];  // find ordering of characters from adjacent words
      for (int j = 0; j < min(w1.length(), w2.length()); j++) {
        char parent = w1[j], child = w2[j];
        if (parent != child) {             // if the two characters are different
          graph[parent].push_back(child);  // put the child into it's parent's list
          inDegree[child]++;               // increment child's inDegree
          break;  // only the first different character between the two words will help us find the
                  // order
        }
      }
    }

    // c. Find all sources i.e., all vertices with 0 in-degrees
    queue<char> sources;
    for (auto entry : inDegree) {
      if (entry.second == 0) {
        sources.push(entry.first);
      }
    }

    // d. For each source, add it to the sortedOrder and subtract one from all of its children's
    // in-degrees if a child's in-degree becomes zero, add it to the sources queue
    string sortedOrder;
    while (!sources.empty()) {
      char vertex = sources.front();
      sources.pop();
      sortedOrder += vertex;
      vector<char> children =
          graph[vertex];  // get the node's children to decrement their in-degrees
      for (char child : children) {
        inDegree[child]--;
        if (inDegree[child] == 0) {
          sources.push(child);
        }
      }
    }

    // if sortedOrder doesn't contain all characters, there is a cyclic dependency between
    // characters, therefore, we will not be able to find the correct ordering of the characters
    if (sortedOrder.length() != inDegree.size()) {
      return "";
    }

    return sortedOrder;
  }
};

int main(int argc, char *argv[]) {
  string result = AlienDictionary::findOrder(vector<string>{"ba", "bc", "ac", "cab"});
  cout << "Character order: " << result << endl;

  result = AlienDictionary::findOrder(vector<string>{"cab", "aaa", "aab"});
  cout << "Character order: " << result << endl;

  result = AlienDictionary::findOrder(vector<string>{"ywx", "wz", "xww", "xz", "zyy", "zwz"});
  cout << "Character order: " << result << endl;
}
