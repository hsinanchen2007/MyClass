/*

https://www.educative.io/courses/grokking-the-coding-interview/qVZmZJVxPY0

Solution
In this problem, following a greedy approach to connect the smallest ropes first will ensure 
the lowest cost. We can use a Min Heap to find the smallest ropes following a similar approach 
as discussed in Kth Smallest Number. Once we connect two ropes, we need to insert the resultant 
rope back in the Min Heap so that we can connect it with the remaining ropes.

Time complexity
Given ‘N’ ropes, we need O(N*logN) to insert all the ropes in the heap. In each step, while 
processing the heap, we take out two elements from the heap and insert one. This means we will 
have a total of ‘N’ steps, having a total time complexity of O(N*logN).

Space complexity
The space complexity will be O(N) because we need to store all the ropes in the heap.

*/

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class ConnectRopes {
 public:
  static int minimumCostToConnectRopes(const vector<int> &ropeLengths) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // add all ropes to the min heap
    for (int i = 0; i < ropeLengths.size(); i++) {
      minHeap.push(ropeLengths[i]);
    }

    // go through the values of the heap, in each step take top (lowest) rope lengths from the min
    // heap connect them and push the result back to the min heap. keep doing this until the heap is
    // left with only one rope
    int result = 0, temp = 0;
    while (minHeap.size() > 1) {
      temp = minHeap.top();
      minHeap.pop();
      temp += minHeap.top();
      minHeap.pop();
      result += temp;
      minHeap.push(temp);
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  int result = ConnectRopes::minimumCostToConnectRopes(vector<int>{1, 3, 11, 5});
  cout << "Minimum cost to connect ropes: " << result << endl;
  result = ConnectRopes::minimumCostToConnectRopes(vector<int>{3, 4, 5, 6});
  cout << "Minimum cost to connect ropes: " << result << endl;
  result = ConnectRopes::minimumCostToConnectRopes(vector<int>{1, 3, 11, 5, 2});
  cout << "Minimum cost to connect ropes: " << result << endl;
}
