/*

https://leetcode.com/problems/k-closest-points-to-origin/

973. K Closest Points to Origin

Medium
7K
259
company
Amazon
company
Facebook
company
Google

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, 
return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it 
is in).
 

Example 1:

Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
 

Constraints:

1 <= k <= points.length <= 104
-104 < xi, yi < 104

*/

/*
    Given array of points & an int k, return k closest points to (0, 0)
    Ex. points = [[1,3],[-2,2]], k = 1 -> [[-2,2]]

    Quickselect, partition until pivot = k, left side all < k

    Time: O(n) -> optimized from O(n log k) max heap solution
    Space: O(1)
*/

// class Solution {
// public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//         priority_queue<pair<double, vector<int>>> pq;
//         for (int i = 0; i < points.size(); i++) {
//             double distance = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
//             pq.push({distance, points[i]});
//             if (pq.size() > k) {
//                 pq.pop();
//             }
//         }
        
//         vector<vector<int>> result;
//         while(!pq.empty()) {
//             result.push_back(pq.top().second);
//             pq.pop();
//         }
        
//         return result;
//     }
// };

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int low = 0;
        int high = points.size() - 1;
        int pivotIndex = points.size();
        
        while (pivotIndex != k) {
            pivotIndex = partition(points, low, high);
            if (pivotIndex < k) {
                low = pivotIndex;
            } else {
                high = pivotIndex - 1;
            }
        }
        
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
private:
    int partition(vector<vector<int>>& points, int low, int high) {
        vector<int> pivot = points[low + (high - low) / 2];
        int pivotDistance = getDistance(pivot);
        
        while (low < high) {
            if (getDistance(points[low]) >= pivotDistance) {
                swap(points[low], points[high]);
                high--;
            } else {
                low++;
            }
        }
        
        if (getDistance(points[low]) < pivotDistance) {
            low++;
        }
        return low;
    }
    
    int getDistance(vector<int>& point) {
        return pow(point[0], 2) + pow(point[1], 2);
    }
};
