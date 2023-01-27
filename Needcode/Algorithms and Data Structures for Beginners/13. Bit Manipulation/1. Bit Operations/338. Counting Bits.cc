/*

https://leetcode.com/problems/counting-bits/

338. Counting Bits

Easy
8.3K
397
company
Goldman Sachs
company
Amazon
company
Adobe

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the 
number of 1's in the binary representation of i.

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 
Constraints:

0 <= n <= 105
 
Follow up:

It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?

*/

/*
    Given int, return array: for each i, ans[i] is # of 1's
    Ex. n = 2 -> [0,1,1], 0 = 0 has 0, 1 = 1 has 1, 2 = 10 has 1

    x = 1001011101 = 605
    x'= 0100101110 = 302
    Differ by 1 bit, by removing LSB: f(x) = f(x / 2) + (x mod 2)

    Time: O(n)
    Space: O(1), the output array does not count towards space
*/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            //                 i / 2      i % 2
            result[i] = result[i >> 1] + (i & 1);
        }
        
        return result;
    }
};
