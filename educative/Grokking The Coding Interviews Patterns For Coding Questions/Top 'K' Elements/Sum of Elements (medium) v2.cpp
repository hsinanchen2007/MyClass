/*

https://www.educative.io/courses/grokking-the-coding-interview/qVljv3Plr67

Solution
This problem follows the Top ‘K’ Numbers pattern, and shares similarities with Kth Smallest Number.

We can find the sum of all numbers coming between the K1’th and K2’th smallest numbers in the following steps:

First, insert all numbers in a min-heap.
Remove the first K1 smallest numbers from the min-heap.
Now take the next K2-K1-1 numbers out of the heap and add them. This sum will be our required output.

Time complexity
Since we need to put all the numbers in a min-heap, the time complexity of the above algorithm will be O(N*logN)
where ‘N’ is the total input numbers.

Space complexity
The space complexity will be O(N), as we need to store all the ‘N’ numbers in the heap.

*/

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class SumOfElements {
 public:
  struct numCompare {
    bool operator()(const int &x, const int &y) { return x > y; }
  };

  static int findSumOfElements(const vector<int> &nums, int k1, int k2) {
    priority_queue<int, vector<int>, numCompare> minHeap;

    // insert all numbers to the min heap
    for (int i = 0; i < nums.size(); i++) {
      minHeap.push(nums[i]);
    }

    // remove k1 small numbers from the min heap
    for (int i = 0; i < k1; i++) {
      minHeap.pop();
    }

    int elementSum = 0;
    // sum next k2-k1-1 numbers
    for (int i = 0; i < k2 - k1 - 1; i++) {
      elementSum += minHeap.top();
      minHeap.pop();
    }

    return elementSum;
  }
};

int main(int argc, char *argv[]) {
  int result = SumOfElements::findSumOfElements(vector<int>{1, 3, 12, 5, 15, 11}, 3, 6);
  cout << "Sum of all numbers between k1 and k2 smallest numbers: " << result << endl;

  result = SumOfElements::findSumOfElements(vector<int>{3, 5, 8, 7}, 1, 4);
  cout << "Sum of all numbers between k1 and k2 smallest numbers: " << result << endl;
}

