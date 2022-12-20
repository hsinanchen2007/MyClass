/*

https://www.educative.io/courses/grokking-the-coding-interview/B89rvR6XZ3J

Solution
This problem follows Top ‘K’ Numbers. The only difference is that in this problem, we need to 
find the most frequently occurring number compared to finding the largest numbers.

We can follow the same approach as discussed in the Top K Elements problem. However, in this 
problem, we first need to know the frequency of each number, for which we can use a HashMap. 
Once we have the frequency map, we can use a Min Heap to find the ‘K’ most frequently occurring 
number. In the Min Heap, instead of comparing numbers we will compare their frequencies in order 
to get frequently occurring numbers

Time complexity
The time complexity of the above algorithm is O(N+N*logK).

Space complexity
The space complexity will be O(N). Even though we are storing only ‘K’ numbers in the heap. 
For the frequency map, however, we need to store all the ‘N’ numbers.

*/

using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TopKFrequentNumbers {
  struct valueCompare {
    char operator()(const pair<int, int> &x, const pair<int, int> &y) {
      return x.second > y.second;
    }
  };

 public:
  static vector<int> findTopKFrequentNumbers(const vector<int> &nums, int k) {
    // find the frequency of each number
    unordered_map<int, int> numFrequencyMap;
    for (int n : nums) {
      numFrequencyMap[n]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, valueCompare> minHeap;

    // go through all numbers of the numFrequencyMap and push them in the minHeap, which will have
    // top k frequent numbers. If the heap size is more than k, we remove the smallest (top) number
    for (auto entry : numFrequencyMap) {
      minHeap.push(entry);
      if (minHeap.size() > k) {
        minHeap.pop();
      }
    }

    // create a list of top k numbers
    vector<int> topNumbers;
    while (!minHeap.empty()) {
      topNumbers.push_back(minHeap.top().first);
      minHeap.pop();
    }

    return topNumbers;
  }
};

int main(int argc, char *argv[]) {
  vector<int> result =
      TopKFrequentNumbers::findTopKFrequentNumbers(vector<int>{1, 3, 5, 12, 11, 12, 11}, 2);
  cout << "Here are the K frequent numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = TopKFrequentNumbers::findTopKFrequentNumbers(vector<int>{5, 12, 11, 3, 11}, 2);
  cout << "Here are the K frequent numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}

