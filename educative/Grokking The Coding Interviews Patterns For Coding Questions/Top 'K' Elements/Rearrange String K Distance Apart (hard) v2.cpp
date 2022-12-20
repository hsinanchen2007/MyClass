/*

https://www.educative.io/courses/grokking-the-coding-interview/qA7n6820GjG

Solution 
This problem follows the Top ‘K’ Numbers pattern and is quite similar to Rearrange String. 
The only difference is that in the ‘Rearrange String’ the same characters need not be adjacent 
i.e., they should be at least ‘2’ distance apart (in other words, there should be at least
one character between two same characters), while in the current problem, the same characters 
should be ‘K’ distance apart.

Following a similar approach, since we were inserting a character back in the heap in the next 
iteration, in this problem, we will re-insert the character after ‘K’ iterations. We can keep 
track of previous characters in a queue to insert them back in the heap after ‘K’ iterations.

Time complexity
The time complexity of the above algorithm is O(N*logN) where ‘N’ is the number of characters 
in the input string.

Space complexity
The space complexity will be O(N), as in the worst case, we need to store all the ‘N’ characters 
in the HashMap.

*/

using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class RearrangeStringKDistanceApart {
 public:
  struct valueCompare {
    char operator()(const pair<int, int> &x, const pair<int, int> &y) {
      return y.second > x.second;
    }
  };

  static string reorganizeString(const string &str, int k) {
    if (k <= 1) return str;
    
    unordered_map<char, int> charFrequencyMap;
    for (char chr : str) {
      charFrequencyMap[chr]++;
    }

    priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare> maxHeap;

    // add all characters to the max heap
    for (auto entry : charFrequencyMap) {
      maxHeap.push(entry);
    }

    queue<pair<char, int>> queue;
    string resultString;
    while (!maxHeap.empty()) {
      auto currentEntry = maxHeap.top();
      maxHeap.pop();
      // append the current character to the result string and decrement its count
      resultString += currentEntry.first;
      currentEntry.second--;
      queue.push(currentEntry);
      if (queue.size() == k) {
        auto entry = queue.front();
        queue.pop();
        if (entry.second > 0) {
          maxHeap.push(entry);
        }
      }
    }

    // if we were successful in appending all the characters to the result string, return it
    return resultString.length() == str.length() ? resultString : "";
  }
};

int main(int argc, char *argv[]) {
  cout << "Reorganized string: "
       << RearrangeStringKDistanceApart::reorganizeString("Programming", 3) << endl;
  cout << "Reorganized string: "
       << RearrangeStringKDistanceApart::reorganizeString("mmpp", 2) << endl;
  cout << "Reorganized string: "
       << RearrangeStringKDistanceApart::reorganizeString("aab", 2) << endl;
  cout << "Reorganized string: " << RearrangeStringKDistanceApart::reorganizeString("aappa", 3)
       << endl;
}
