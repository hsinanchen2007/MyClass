/*

https://leetcode.com/problems/kth-largest-element-in-an-array/

215. Kth Largest Element in an Array

Medium
13K
647
company
Facebook
company
Amazon
company
Spotify
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

You must solve it in O(n) time complexity.
 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104

*/

/*
    Given array and int k, return kth largest element in array
    Ex. nums = [3,2,1,5,6,4], k = 2 -> 5

    Quickselect, partition until pivot = k, left side all > k

    Time: O(n) -> optimized from O(n log k) min heap solution
    Space: O(1)
*/

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int, vector<int>, greater<int>> pq;
//         for (int i = 0; i < nums.size(); i++) {
//             pq.push(nums[i]);
//             if (pq.size() > k) {
//                 pq.pop();
//             }
//         }
//         return pq.top();
//     }
// };

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int low = 0;
        int high = nums.size() - 1;
        int pivotIndex = nums.size();
        
        while (pivotIndex != k - 1) {
            pivotIndex = partition(nums, low, high);
            if (pivotIndex < k - 1) {
                low = pivotIndex + 1;
            } else {
                high = pivotIndex - 1;
            }
        }
        
        return nums[k - 1];
    }
private:
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];
        
        int i = low + 1;
        int j = high;
        
        while (i <= j) {
            if (nums[i] < pivot && pivot < nums[j]) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            if (nums[i] >= pivot) {
                i++;
            }
            if (pivot >= nums[j]) {
                j--;
            }
        }
        
        swap(nums[low], nums[j]);
        return j;
    }
};
