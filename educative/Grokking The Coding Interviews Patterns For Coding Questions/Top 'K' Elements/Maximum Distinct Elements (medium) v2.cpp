/*

https://www.educative.io/courses/grokking-the-coding-interview/gx6oKY8PGYY

Solution
This problem follows the Top ‘K’ Numbers pattern, and shares similarities with Top ‘K’ 
Frequent Numbers.

We can follow a similar approach as discussed in Top ‘K’ Frequent Numbers problem:

First, we will find the frequencies of all the numbers.
Then, push all numbers that are not distinct (i.e., have a frequency higher than one) 
in a Min Heap based on their frequencies. At the same time, we will keep a running count 
of all the distinct numbers. Following a greedy approach, in a stepwise fashion, we will 
remove the least frequent number from the heap (i.e., the top element of the min-heap), 
and try to make it distinct. We will see if we can remove all occurrences of a number 
except one. If we can, we will increment our running count of distinct numbers. We have 
to also keep a count of how many removals we have done. If after removing elements from 
the heap, we are still left with some deletions, we have to remove some distinct elements.

Time complexity
Since we will insert all numbers in a HashMap and a Min Heap, this will take O(N*logN)
where ‘N’ is the total input numbers. While extracting numbers from the heap, in the worst 
case, we will need to take out ‘K’ numbers. This will happen when we have at least ‘K’ 
numbers with a frequency of two. Since the heap can have a maximum of ‘N/2’ numbers, 
therefore, extracting an element from the heap will take O(logN) and extracting ‘K’ numbers 
will take O(KlogN). So overall, the time complexity of our algorithm will be O(N*logN + KlogN)

We can optimize the above algorithm and only push ‘K’ elements in the heap, as in the worst 
case we will be extracting ‘K’ elements from the heap. This optimization will reduce the 
overall time complexity to O(N*logK + KlogK).

Space complexity
The space complexity will be O(N) as, in the worst case, we need to store all the ‘N’ 
characters in the HashMap.

*/

using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class MaximumDistinctElements {
 public:
  struct valueCompare {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) {
      return x.second > y.second;
    }
  };

  static int findMaximumDistinctElements(const vector<int> &nums, int k) {
    int distinctElementsCount = 0;
    if (nums.size() <= k) {
      return distinctElementsCount;
    }

    // find the frequency of each number
    unordered_map<int, int> numFrequencyMap;
    for (auto i : nums) {
      numFrequencyMap[i]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, valueCompare> minHeap;

    // insert all numbers with frequency greater than '1' into the min-heap
    for (auto entry : numFrequencyMap) {
      if (entry.second == 1) {
        distinctElementsCount++;
      } else {
        minHeap.push(entry);
      }
    }

    // following a greedy approach, try removing the least frequent numbers first from the min-heap
    while (k > 0 && !minHeap.empty()) {
      auto entry = minHeap.top();
      minHeap.pop();
      // to make an element distinct, we need to remove all of its occurrences except one
      k -= entry.second - 1;
      if (k >= 0) {
        distinctElementsCount++;
      }
    }

    // if k > 0, this means we have to remove some distinct numbers
    if (k > 0) {
      distinctElementsCount -= k;
    }

    return distinctElementsCount;
  }
};

int main(int argc, char *argv[]) {
  int result =
      MaximumDistinctElements::findMaximumDistinctElements(vector<int>{7, 3, 5, 8, 5, 3, 3}, 2);
  cout << "Maximum distinct numbers after removing K numbers: " << result << endl;

  result = MaximumDistinctElements::findMaximumDistinctElements(vector<int>{3, 5, 12, 11, 12}, 3);
  cout << "Maximum distinct numbers after removing K numbers: " << result << endl;

  result = MaximumDistinctElements::findMaximumDistinctElements(
      vector<int>{1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5}, 2);
  cout << "Maximum distinct numbers after removing K numbers: " << result << endl;
}
