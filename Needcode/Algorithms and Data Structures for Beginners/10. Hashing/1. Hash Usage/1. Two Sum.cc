/*

https://leetcode.com/problems/two-sum/

1. Two Sum

Easy
42.6K
1.4K
company
Amazon
company
Adobe
company
Apple

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1] 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 
Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

*/

/*
    Given int array & target, return indices of 2 nums that add to target
    Ex. nums = [2,7,11,15] & target = 9 -> [0,1], 2 + 7 = 9

    At each num, calculate complement, if exists in hash map then return

    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (m.find(complement) != m.end()) {
                result.push_back(m[complement]);
                result.push_back(i);
                break;
            } else {
                m.insert({nums[i], i});
            }
        }
        
        return result;
    }
};
