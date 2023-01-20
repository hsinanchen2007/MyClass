/*

https://leetcode.com/problems/search-a-2d-matrix/

74. Search a 2D Matrix

Medium
11.1K
325
company
Amazon
company
Bloomberg
company
Apple
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
 

Example 1:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104

*/

/*
    Search for target value in matrix where every row & col is sorted

    Perform 2 binary searches: 1 to find row, then another to find col

    Time: O(log m + log n)
    Space: O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lowRow = 0;
        int highRow = matrix.size() - 1;
        
        while (lowRow < highRow) {
            int mid = lowRow + (highRow - lowRow) / 2;
            if (matrix[mid][0] == target) {
                return true;
            }
            if (matrix[mid][0] < target && target < matrix[mid + 1][0]) {
                lowRow = mid;
                break;
            }
            if (matrix[mid][0] < target) {
                lowRow = mid + 1;
            } else {
                highRow = mid - 1;
            }
        }
        
        int lowCol = 0;
        int highCol = matrix[0].size() - 1;
        
        while (lowCol <= highCol) {
            int mid = lowCol + (highCol - lowCol) / 2;
            if (matrix[lowRow][mid] == target) {
                return true;
            }
            if (matrix[lowRow][mid] < target) {
                lowCol = mid + 1;
            } else {
                highCol = mid - 1;
            }
        }
        
        return false;
    }
};
