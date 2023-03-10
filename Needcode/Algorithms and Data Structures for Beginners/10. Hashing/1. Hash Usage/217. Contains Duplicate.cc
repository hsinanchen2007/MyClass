/*

https://leetcode.com/problems/contains-duplicate/

217. Contains Duplicate

Easy
8.1K
1.1K
company
Amazon
company
Bloomberg
company
Apple

Given an integer array nums, return true if any value appears at least twice in the array, and return false 
if every element is distinct.
 

Example 1:

Input: nums = [1,2,3,1]
Output: true

Example 2:

Input: nums = [1,2,3,4]
Output: false

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109

*/

/*
    Given int array, return true if any value appears at least twice
    Ex. nums = [1,2,3,1] -> true, nums = [1,2,3,4] -> false

    If seen num previously then has dupe, else insert into hash set

    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            s.insert(nums[i]);
        }
        
        return false;
    }
};
