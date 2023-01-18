/*

https://leetcode.com/problems/fibonacci-number/

509. Fibonacci Number

Easy
6K
304
company
Amazon
company
Adobe
company
Microsoft
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).
 

Example 1:

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:

Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Example 3:

Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 
Constraints:

0 <= n <= 30

*/

// From https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/fibonacci-number.cpp

// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int fib(int N) {
        vector<vector<int>> T = {{1, 1},
                                 {1, 0}};
        return matrixMult({{1, 0}}, matrixExpo(T, N))[0][1]; // [a1, a0] * T^N
    }

private:
    vector<vector<int>> matrixExpo(const vector<vector<int>>& A, int pow) {
        vector<vector<int>> result(A.size(), vector<int>(A.size()));
        vector<vector<int>> A_exp(A);
        for (int i = 0; i < A.size(); ++i) {
            result[i][i] = 1;
        }
        while (pow) {
            if (pow % 2 == 1) {
                result = matrixMult(result, A_exp);
            }
            A_exp = matrixMult(A_exp, A_exp);
            pow /= 2;
        }
        return result;
    }

    vector<vector<int>> matrixMult(const vector<vector<int>>& A, const vector<vector<int>>& B) {
        vector<vector<int>> result(A.size(), vector<int>(B[0].size()));
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B[0].size(); ++j) {
                int64_t entry = 0;
                for (int k = 0; k < B.size(); ++k) {
                    entry = (static_cast<int64_t>(A[i][k]) * B[k][j] + entry);
                }
                result[i][j] = static_cast<int>(entry);
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    int fib(int N) {
        vector<int> dp(3, 0);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= N; ++i) {
            dp[i % 3] = dp[(i - 1) % 3] + dp[(i - 2) % 3];
        }
        return dp[N % 3];
    }
};
