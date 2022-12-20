/*

https://www.educative.io/courses/grokking-the-coding-interview/xV7wx4o8ymB

Solution
This problem follows the Top ‘K’ Numbers pattern. We can follow a greedy approach to find 
an arrangement of the given string where no two same characters come next to each other.

We can work in a stepwise fashion to create a string with all characters from the input 
string. Following a greedy approach, we should first append the most frequent characters 
to the output strings, for which we can use a Max Heap. By appending the most frequent 
character first, we have the best chance to find a string where no two same characters 
come next to each other.

So in each step, we should append one occurrence of the highest frequency character to the 
output string. We will not put this character back in the heap to ensure that no two same 
characters are adjacent to each other. In the next step, we should process the next most 
frequent character from the heap in the same way and then, at the end of this step, insert 
the character from the previous step back to the heap after decrementing its frequency.

Following this algorithm, if we can append all the characters from the input string to the 
output string, we would have successfully found an arrangement of the given string where no 
two same characters appeared adjacent to each other.

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

class RearrangeString {
 public:
  struct valueCompare {
    char operator()(const pair<int, int> &x, const pair<int, int> &y) {
      return y.second > x.second;
    }
  };

  static string rearrangeString(const string &str) {
    unordered_map<char, int> charFrequencyMap;
    for (char chr : str) {
      charFrequencyMap[chr]++;
    }

    priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare> maxHeap;

    // add all characters to the max heap
    for (auto entry : charFrequencyMap) {
      maxHeap.push(entry);
    }

    pair<char, int> previousEntry(-1, -1);
    string resultString = "";
    while (!maxHeap.empty()) {
      pair<char, int> currentEntry = maxHeap.top();
      maxHeap.pop();
      // add the previous entry back in the heap if its frequency is greater than zero
      if (previousEntry.second > 0) {
        maxHeap.push(previousEntry);
      }
      // append the current character to the result string and decrement its count
      resultString += currentEntry.first;
      currentEntry.second--;
      previousEntry = currentEntry;
    }

    // if we were successful in appending all the characters to the result string, return it
    return resultString.length() == str.length() ? resultString : "";
  }
};

int main(int argc, char *argv[]) {
  cout << "Rearranged string: " << RearrangeString::rearrangeString("aappp") << endl;
  cout << "Rearranged string: " << RearrangeString::rearrangeString("Programming") << endl;
  cout << "Rearranged string: " << RearrangeString::rearrangeString("aapa") << endl;
}
