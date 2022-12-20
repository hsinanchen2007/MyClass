/*

https://www.educative.io/courses/grokking-the-coding-interview/gxZz615BPPG

Solution
This problem follows the Top ‘K’ Elements pattern, and shares similarities with Top ‘K’ 
Frequent Numbers.

We can follow the same approach as discussed in the Top ‘K’ Frequent Numbers problem. 
First, we will find the frequencies of all characters, then use a max-heap to find the 
most occurring characters.

Time complexity
The time complexity of the above algorithm is O(D*logD) where ‘D’ is the number of distinct 
characters in the input string. This means, in the worst case, when all characters are 
unique the time complexity of the algorithm will be O(N*logN) where ‘N’ is the total number 
of characters in the string.

Space complexity
The space complexity will be O(N), as in the worst case, we need to store all the ‘N’ 
characters in the HashMap.

*/

using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

class FrequencySort {
 public:
  struct valueCompare {
    bool operator()(const pair<char, int> &x, const pair<char, int> &y) {
      return y.second > x.second;
    }
  };

  static string sortCharacterByFrequency(const string &str) {
    // find the frequency of each character
    unordered_map<char, int> characterFrequencyMap;
    for (char chr : str) {
      characterFrequencyMap[chr]++;
    }

    priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare> maxHeap;

    // add all characters to the max heap
    for (auto entry : characterFrequencyMap) {
      maxHeap.push(entry);
    }

    // build a string, appending the most occurring characters first
    string sortedString = "";
    while (!maxHeap.empty()) {
      auto entry = maxHeap.top();
      maxHeap.pop();
      for (int i = 0; i < entry.second; i++) {
        sortedString += entry.first;
      }
    }

    return sortedString;
  }
};

int main(int argc, char *argv[]) {
  string result = FrequencySort::sortCharacterByFrequency("Programming");
  cout << "Here is the given string after sorting characters by frequency: " << result << endl;

  result = FrequencySort::sortCharacterByFrequency("abcbab");
  cout << "Here is the given string after sorting characters by frequency: " << result << endl;
}
