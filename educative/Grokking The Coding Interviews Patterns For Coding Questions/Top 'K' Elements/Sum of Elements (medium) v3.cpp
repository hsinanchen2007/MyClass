/*

https://www.educative.io/courses/grokking-the-coding-interview/qVljv3Plr67

Alternate Solution
We can iterate the array and use a max-heap to keep track of the top K2 numbers. We can, 
then, add the top K2-K1-1 numbers in the max-heap to find the sum of all numbers coming 
between the K1’th and K2’th smallest numbers. Here is what the algorithm will look like:

Time complexity
Since we need to put only the top K2 numbers in the max-heap at any time, the time complexity 
of the above algorithm will be O(N*logK2).

Space complexity
The space complexity will be O(K2), as we need to store the smallest ‘K2’ numbers in the heap.

*/

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class SumOfElements {
 public:
  static int findSumOfElements(const vector<int> &nums, int k1, int k2) {
    priority_queue<int> maxHeap;
    // keep smallest k2 numbers in the max heap
    for (int i = 0; i < nums.size(); i++) {
      if (i < k2 - 1) {
        maxHeap.push(nums[i]);
      } else if (nums[i] < maxHeap.top()) {
        maxHeap.pop();  // as we are interested only in the smallest k2 numbers
        maxHeap.push(nums[i]);
      }
    }

    // get the sum of numbers between k1 and k2 indices
    // these numbers will be at the top of the max heap
    int elementSum = 0;
    for (int i = 0; i < k2 - k1 - 1; i++) {
      elementSum += maxHeap.top();
      maxHeap.pop();
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
