/*

https://leetcode.com/problems/insert-into-a-binary-search-tree/

701. Insert into a Binary Search Tree

Medium
4.5K
156
company
LinkedIn
company
Amazon
company
Google
You are given the root node of a binary search tree (BST) and a value to insert into the tree. 
Return the root node of the BST after the insertion. It is guaranteed that the new value does 
not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains 
a BST after insertion. You can return any of them.
 

Example 1:

Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]
Explanation: Another accepted tree is:

Example 2:

Input: root = [40,20,60,10,30,50,70], val = 25
Output: [40,20,60,10,30,50,70,null,null,25]

Example 3:

Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
Output: [4,2,7,1,3,5]
 

Constraints:

The number of nodes in the tree will be in the range [0, 104].
-108 <= Node.val <= 108
All the values Node.val are unique.
-108 <= val <= 108
It's guaranteed that val does not exist in the original BST.

*/

// From https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/insert-into-a-binary-search-tree.cpp

// Time:  O(h)
// Space: O(1)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *curr = root, *parent = nullptr;
        while (curr) {
            parent = curr;
            if (val <= curr->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        if (!parent) {
            root = new TreeNode(val);
        } else if (val <= parent->val) {
            parent->left = new TreeNode(val);
        } else {
            parent->right = new TreeNode(val);
        }
        return root;
    }
};


// Time:  O(h)
// Space: O(h)
class Solution2 {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            root = new TreeNode(val);
        } else {
            if (val <= root->val) {
                root->left = insertIntoBST(root->left, val);
            } else {
                root->right = insertIntoBST(root->right, val);
            }
        }
        return root;
    }
};