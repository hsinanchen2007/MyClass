/*

https://www.educative.io/courses/grokking-the-coding-interview/gxxPGn8vE8G

Solution
This problem follows the Top ‘K’ Numbers pattern but has two differences:

Here we need to find the Kth smallest number, whereas in Top ‘K’ Numbers we were dealing 
with ‘K’ largest numbers. In this problem, we need to find only one number (Kth smallest) 
compared to finding all ‘K’ largest numbers. We can follow the same approach as discussed 
in the ‘Top K Elements’ problem. To handle the first difference mentioned above, we can 
use a max-heap instead of a min-heap. As we know, the root is the biggest element in the 
max heap. So, since we want to keep track of the ‘K’ smallest numbers, we can compare every 
number with the root while iterating through all numbers, and if it is smaller than the 
root, we’ll take the root out and insert the smaller number.

Time complexity
The time complexity of this algorithm is O(K*logK+(N-K)*logK), which is asymptotically 
equal to O(N*logK)

Space complexity
The space complexity will be O(K) because we need to store ‘K’ smallest numbers in the heap.

An Alternate Approach
Alternatively, we can use a Min Heap to find the Kth smallest number. We can insert all the 
numbers in the min-heap and then extract the top ‘K’ numbers from the heap to find the Kth 
smallest number. Initializing the min-heap with all numbers will take O(N) and extracting ‘K’ 
numbers will take O(KlogN). Overall, the time complexity of this algorithm will be O(N+KlogN)
and the space complexity will be O(N).

*/

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthSmallestNumber {
 public:
  static int findKthSmallestNumber(const vector<int> &nums, int k) {
    priority_queue<int> maxHeap;

    // put first k numbers in the max heap
    for (int i = 0; i < k; i++) {
      maxHeap.push(nums[i]);
    }

    // go through the remaining numbers of the array, if the number from the array is smaller than
    // the top (biggest) number of the heap, remove the top number from heap and add the number from
    // array
    for (int i = k; i < nums.size(); i++) {
      if (nums[i] < maxHeap.top()) {
        maxHeap.pop();
        maxHeap.push(nums[i]);
      }
    }

    // the root of the heap has the Kth smallest number
    return maxHeap.top();
  }
};

int main(int argc, char *argv[]) {
  int result = KthSmallestNumber::findKthSmallestNumber(vector<int>{1, 5, 12, 2, 11, 5}, 3);
  cout << "Kth smallest number is: " << result << endl;

  // since there are two 5s in the input array, our 3rd and 4th smallest numbers should be a '5'
  result = KthSmallestNumber::findKthSmallestNumber(vector<int>{1, 5, 12, 2, 11, 5}, 4);
  cout << "Kth smallest number is: " << result << endl;

  result = KthSmallestNumber::findKthSmallestNumber(vector<int>{5, 12, 11, -1, 12}, 3);
  cout << "Kth smallest number is: " << result << endl;
}
