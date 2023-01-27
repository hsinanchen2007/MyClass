/*

https://leetcode.com/problems/shortest-path-in-binary-matrix/

1091. Shortest Path in Binary Matrix

Medium
4.3K
180
company
Facebook
company
Amazon
company
Google

Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, 
return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) 
such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.
 

Example 1:

Input: grid = [[0,1],[1,0]]
Output: 2

Example 2:

Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1

*/

// From https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/shortest-path-in-binary-matrix.cpp

// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1},
                                                          { 0, -1}, { 0, 1},
                                                          { 1, -1}, { 1, 0}, { 1, 1}};
        int result = 0;
        queue<pair<int, int>> q({{0, 0}});
        while (!q.empty()) {
            ++result;
            queue<pair<int, int>> next_depth;
            while (!q.empty()) {
                int i, j;
                tie(i, j) = q.front(); q.pop();
                if (0 <= i && i < grid.size() &&
                    0 <= j && j < grid[0].size() &&
                    !grid[i][j]) {
                    grid[i][j] = 1;
                    if (i == grid.size() - 1 && j == grid.size() - 1) {
                        return result;
                    }
                    for (const auto& dir : directions) {
                        next_depth.emplace(i + dir.first, j + dir.second);
                    }
                }
            }
            q = move(next_depth);
        }
        return -1;
    }
};