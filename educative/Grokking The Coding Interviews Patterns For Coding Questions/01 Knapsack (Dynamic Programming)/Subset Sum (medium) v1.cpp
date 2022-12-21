/*

https://www.educative.io/courses/grokking-the-coding-interview/gxrnL0GQGqk

Given a set of positive numbers, determine if a subset exists whose sum is equal to a given number ‘S’.

Example 1:
Input: {1, 2, 3, 7}, S=6
Output: True
The given set has a subset whose sum is '6': {1, 2, 3}

Example 2:
Input: {1, 2, 7, 1, 5}, S=10
Output: True
The given set has a subset whose sum is '10': {1, 2, 7}

Example 3:
Input: {1, 3, 4, 8}, S=6
Output: False
The given set does not have any subset whose sum is equal to '6'.

Basic Solution
This problem follows the 0/1 Knapsack pattern and is quite similar to Equal Subset Sum Partition. 
A basic brute-force solution could be to try all subsets of the given numbers to see if any set has 
a sum equal to ‘S’.

So our brute-force algorithm will look like:

12345
for each number 'i' 
  create a new set which INCLUDES number 'i' if it does not exceed 'S', and recursively 
     process the remaining numbers
  create a new set WITHOUT number 'i', and recursively process the remaining numbers 
return true if any of the above two sets has a sum equal to 'S', otherwise return false
Since this problem is quite similar to Equal Subset Sum Partition, let’s jump directly to the 
bottom-up dynamic programming solution.

Bottom-up Dynamic Programming
We’ll try to find if we can make all possible sums with every subset to populate the array 
dp[TotalNumbers][S+1].

For every possible sum ‘s’ (where 0 <= s <= S), we have two options:

Exclude the number. In this case, we will see if we can get the sum ‘s’ from the subset 
excluding this number => dp[index-1][s]
Include the number if its value is not more than ‘s’. In this case, we will see if we can 
find a subset to get the remaining sum => dp[index-1][s-num[index]]
If either of the above two scenarios returns true, we can find a subset with a sum equal to ‘s’.

Let’s draw this visually, with the example input {1, 2, 3, 7}, and start with our base 
case of size zero:

Time and Space complexity
The above solution has the time and space complexity of O(N*S), where ‘N’ represents total numbers 
and ‘S’ is the required sum.

*/

using namespace std;

#include <iostream>
#include <vector>

class SubsetSum {
 public:
  virtual bool canPartition(const vector<int> &num, int sum) {
    int n = num.size();
    vector<vector<bool>> dp(n, vector<bool>(sum + 1));

    // populate the sum=0 columns, as we can always form '0' sum with an empty set
    for (int i = 0; i < n; i++) {
      dp[i][0] = true;
    }

    // with only one number, we can form a subset only when the required sum is equal to its value
    for (int s = 1; s <= sum; s++) {
      dp[0][s] = (num[0] == s ? true : false);
    }

    // process all subsets for all sums
    for (int i = 1; i < num.size(); i++) {
      for (int s = 1; s <= sum; s++) {
        // if we can get the sum 's' without the number at index 'i'
        if (dp[i - 1][s]) {
          dp[i][s] = dp[i - 1][s];
        } else if (s >= num[i]) {
          // else include the number and see if we can find a subset to get the remaining sum
          dp[i][s] = dp[i - 1][s - num[i]];
        }
      }
    }

    // the bottom-right corner will have our answer.
    return dp[num.size() - 1][sum];
  }
};

int main(int argc, char *argv[]) {
  SubsetSum ss;
  vector<int> num = {1, 2, 3, 7};
  cout << ss.canPartition(num, 6) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ss.canPartition(num, 10) << endl;
  num = vector<int>{1, 3, 4, 8};
  cout << ss.canPartition(num, 6) << endl;
}
