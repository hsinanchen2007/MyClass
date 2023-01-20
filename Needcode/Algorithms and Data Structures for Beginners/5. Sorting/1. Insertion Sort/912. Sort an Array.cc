/*

https://leetcode.com/problems/sort-an-array/

912. Sort an Array

Medium
3.2K
598
company
Microsoft
company
Amazon
company
Google
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest 
space complexity possible.
 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while 
the positions of other numbers are changed (for example, 1 and 5).

Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.
 

Constraints:

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104

*/

// From https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/sort-an-array.cpp

// Time:  O(nlogn)
// Space: O(n)

// merge sort solution
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0, nums.size(), &nums);
        return nums;
    }

private:
    void mergeSort(int start, int end, vector<int> *nums) {
        if (end - start <= 1) {
            return;
        }
        const auto& mid = start + (end - start) / 2;
        mergeSort(start, mid, nums);
        mergeSort(mid, end, nums);
        vector<int> tmp;
        for (int left = start, right = mid; left < mid; ++left) {
            while (right < end && (*nums)[right] < (*nums)[left]) {
                tmp.emplace_back((*nums)[right++]);
            }
            tmp.emplace_back((*nums)[left]);
        }
        copy(tmp.cbegin(), tmp.cend(), nums->begin() + start);
    }
};

// Time:  O(nlogn), on average
// Space: O(logn)
// quick sort solution
class Solution2 {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(0, nums.size(), &nums);
        return nums;
    }

private:
    void quickSort(int start, int end, vector<int> *nums) {
        if (end - start <= 1) {
            return;
        }
        const auto& mid = start + (end - start) / 2;
        nth_element(nums->begin() + start,
                    nums->begin() + mid,
                    nums->begin() + end);
        quickSort(start, mid, nums);
        quickSort(mid, end, nums);
    }
};