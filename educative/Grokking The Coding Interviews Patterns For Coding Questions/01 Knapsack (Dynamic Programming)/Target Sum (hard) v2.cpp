/*

https://www.educative.io/courses/grokking-the-coding-interview/JE0BWB8DgAJ

Solution
This problem follows the 0/1 Knapsack pattern and can be converted into Count of Subset Sum. 
Let’s dig into this.

We are asked to find two subsets of the given numbers whose difference is equal to the given 
target ‘S’. Take the first example above. As we saw, one solution is {+1-1-2+3}. So, the two 
subsets we are asked to find are {1, 3} & {1, 2} because,

    (1 + 3) - (1 + 2 ) = 1
Now, let’s say ‘Sum(s1)’ denotes the total sum of set ‘s1’, and ‘Sum(s2)’ denotes the total 
sum of set ‘s2’. So the required equation is:

    Sum(s1) - Sum(s2) = S
This equation can be reduced to the subset sum problem. Let’s assume that ‘Sum(num)’ denotes 
the total sum of all the numbers, therefore:

    Sum(s1) + Sum(s2) = Sum(num)
Let’s add the above two equations:

    => Sum(s1) - Sum(s2) + Sum(s1) + Sum(s2) = S + Sum(num)
    => 2 * Sum(s1) =  S + Sum(num)
    => Sum(s1) = (S + Sum(num)) / 2
Which means that one of the set ‘s1’ has a sum equal to (S + Sum(num)) / 2. This essentially 
converts our problem to: "Find the count of subsets of the given numbers whose sum is equal 
to (S + Sum(num)) / 2"

Time and Space complexity
The above solution has time and space complexity of O(N*S), where ‘N’ represents total numbers 
and ‘S’ is the desired sum.

We can further improve the solution to use only O(S) space.

*/

using namespace std;

#include <iostream>
#include <vector>

class TargetSum {
 public:
  int findTargetSubsets(const vector<int> &num, int s) {
    int totalSum = 0;
    for (auto n : num) {
      totalSum += n;
    }

    // if 's + totalSum' is odd, we can't find a subset with sum equal to '(s + totalSum) / 2'
    if (totalSum < s || (s + totalSum) % 2 == 1) {
      return 0;
    }

    return countSubsets(num, (s + totalSum) / 2);
  }

  // this function is exactly similar to what we have in 'Count of Subset Sum' problem.
 private:
  int countSubsets(const vector<int> &num, int sum) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

    // populate the sum=0 columns, as we will always have an empty set for zero sum
    for (int i = 0; i < n; i++) {
      dp[i][0] = 1;
    }

    // with only one number, we can form a subset only when the required sum is
    // equal to the number
    for (int s = 1; s <= sum; s++) {
      dp[0][s] = (num[0] == s ? 1 : 0);
    }

    // process all subsets for all sums
    for (int i = 1; i < num.size(); i++) {
      for (int s = 1; s <= sum; s++) {
        dp[i][s] = dp[i - 1][s];
        if (s >= num[i]) {
          dp[i][s] += dp[i - 1][s - num[i]];
        }
      }
    }

    // the bottom-right corner will have our answer.
    return dp[num.size() - 1][sum];
  }
};

int main(int argc, char *argv[]) {
  TargetSum ts;
  vector<int> num = {1, 1, 2, 3};
  cout << ts.findTargetSubsets(num, 1) << endl;
  num = vector<int>{1, 2, 7, 1};
  cout << ts.findTargetSubsets(num, 9) << endl;
}
