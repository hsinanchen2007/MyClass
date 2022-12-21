/*

https://www.educative.io/courses/grokking-the-coding-interview/gkZNLjV2kBk

Basic Solution
A basic brute-force solution could be to try all combinations of the given items (as we did above), 
allowing us to choose the one with maximum profit and a weight that doesn’t exceed ‘C’. Take the 
example of four items (A, B, C, and D), as shown in the diagram below. To try all the combinations, 
our algorithm will look like:

12345
for each item 'i' 
  create a new set which INCLUDES item 'i' if the total weight does not exceed the capacity, and 
     recursively process the remaining capacity and items
  create a new set WITHOUT item 'i', and recursively process the remaining items 
return the set from the above two sets with higher profit 
Here is a visual representation of our algorithm:

widget
All green boxes have a total weight that is less than or equal to the capacity (7), and all the red 
ones have a weight that is more than 7. The best solution we have is with items [B, D] having a total 
profit of 22 and a total weight of 7.

Time and Space complexity
The above algorithm’s time complexity is exponential O(2^n), where ‘n’ represents the total number of 
items. This can also be confirmed from the above recursion tree. As we can see, we will have a total 
of ‘31’ recursive calls – calculated through (2^n) + (2^n) - 1, which is asymptotically equivalent to 
O(2^n).

The space complexity is O(n). This space will be used to store the recursion stack. Since the recursive 
algorithm works in a depth-first fashion, which means that we can’t have more than ‘n’ recursive calls 
on the call stack at any time.

Overlapping Sub-problems: Let’s visually draw the recursive calls to see if there are any overlapping 
sub-problems. As we can see, in each recursive call, profits and weights arrays remain constant, and only 
capacity and currentIndex change. For simplicity, let’s denote capacity with ‘c’ and currentIndex with ‘i’:

*/

using namespace std;

#include <iostream>
#include <vector>

class Knapsack {
 public:
  int solveKnapsack(const vector<int> &profits, vector<int> &weights, int capacity) {
    return this->knapsackRecursive(profits, weights, capacity, 0);
  }

 private:
  int knapsackRecursive(const vector<int> &profits, vector<int> &weights, int capacity,
                        int currentIndex) {
    // base checks
    if (capacity <= 0 || currentIndex >= profits.size()) {
      return 0;
    }

    // recursive call after choosing the element at the currentIndex
    // if the weight of the element at currentIndex exceeds the capacity, we shouldn't process this
    int profit1 = 0;
    if (weights[currentIndex] <= capacity) {
      profit1 =
          profits[currentIndex] +
          knapsackRecursive(profits, weights, capacity - weights[currentIndex], currentIndex + 1);
    }

    // recursive call after excluding the element at the currentIndex
    int profit2 = knapsackRecursive(profits, weights, capacity, currentIndex + 1);

    return max(profit1, profit2);
  }
};

int main(int argc, char *argv[]) {
  Knapsack ks;
  vector<int> profits = {1, 6, 10, 16};
  vector<int> weights = {1, 2, 3, 5};
  int maxProfit = ks.solveKnapsack(profits, weights, 7);
  cout << "Total knapsack profit ---> " << maxProfit << endl;
  maxProfit = ks.solveKnapsack(profits, weights, 6);
  cout << "Total knapsack profit ---> " << maxProfit << endl;
}

