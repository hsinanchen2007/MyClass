/*

https://leetcode.com/problems/sort-colors/

75. Sort Colors

Medium
13.6K
495
company
Amazon
company
Microsoft
company
Apple

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color 
are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.


Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
 

Follow up: Could you come up with a one-pass algorithm using only constant extra space?

*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p1=0,p2=nums.size()-1;
        for(int i=p1;i<=p2;i++)
        {
            if(nums[i]==0)
            {
                swap(nums[i],nums[p1]);
                p1++;
            }
            if(nums[i]==2)
            {
                swap(nums[i],nums[p2]);
                p2--;
                i--;
            }
        }
    }
};
