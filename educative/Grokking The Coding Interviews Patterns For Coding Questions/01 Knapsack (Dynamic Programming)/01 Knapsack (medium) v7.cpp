/*

https://www.educative.io/courses/grokking-the-coding-interview/gkZNLjV2kBk

The solution above is similar to the previous solution; the only difference is that we use 
i%2 instead of i and (i-1)%2 instead of i-1. This solution has a space complexity of O(2*C) 
= O(C), where ‘C’ is the knapsack’s maximum capacity.

This space optimization solution can also be implemented using a single array. It is a bit 
tricky, but the intuition is to use the same array for the previous and the next iteration!

If you see closely, we need two values from the previous iteration: dp[c] and dp[c-weight[i]]

Since our inner loop is iterating over c:0-->capacity, let’s see how this might affect our 
two required values:

When we access dp[c], it has not been overridden yet for the current iteration, so it should 
be fine.
dp[c-weight[i]] might be overridden if “weight[i] > 0”. Therefore we can’t use this value for 
the current iteration.
To solve the second case, we can change our inner loop to process in the reverse direction: 
c:capacity-->0. This will ensure that whenever we change a value in dp[], we will not need it 
again in the current iteration.

Can you try writing this algorithm?

*/

using namespace std;

#include <iostream>
#include <vector>

class Knapsack {
 public:
  int solveKnapsack(const vector<int> &profits, vector<int> &weights, int capacity) {
    // basic checks
    if (capacity <= 0 || profits.empty() || weights.size() != profits.size()) {
      return 0;
    }

    int n = profits.size();
    vector<int> dp(capacity + 1);

    // if we have only one weight, we will take it if it is not more than the
    // capacity
    for (int c = 0; c <= capacity; c++) {
      if (weights[0] <= c) {
        dp[c] = profits[0];
      }
    }

    // process all sub-arrays for all the capacities
    for (int i = 1; i < n; i++) {
      for (int c = capacity; c >= 0; c--) {
        int profit1 = 0, profit2 = 0;
        // include the item, if it is not more than the capacity
        if (weights[i] <= c) {
          profit1 = profits[i] + dp[c - weights[i]];
        }
        // exclude the item
        profit2 = dp[c];
        // take maximum
        dp[c] = max(profit1, profit2);
      }
    }

    return dp[capacity];
  }
};

int main(int argc, char *argv[]) {
  Knapsack ks;
  vector<int> profits = {1, 6, 10, 16};
  vector<int> weights = {1, 2, 3, 5};
  cout << ks.solveKnapsack(profits, weights, 7) << endl;
  cout << ks.solveKnapsack(profits, weights, 6) << endl;
}
