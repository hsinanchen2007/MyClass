/*

https://leetcode.com/problems/merge-k-sorted-lists/

23. Merge k Sorted Lists

Hard
15.3K
577
company
Amazon
company
Microsoft
company
Uber
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:

Input: lists = []
Output: []

Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.

*/

/*
    Given array of k sorted linked-lists, merge all into 1 sorted list
    Ex. lists = [[1,4,5],[1,3,4],[2,6]] -> [1,1,2,3,4,4,5,6]

    Min heap -> optimize space w/ divide-and-conquer, merge 2 each time

    Time: O(n log k)
    Space: O(n) -> O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         priority_queue<int, vector<int>, greater<int>> pq;
//         for (int i = 0; i < lists.size(); i++) {
//             ListNode* node = lists[i];
//             while (node != NULL) {
//                 pq.push(node->val);
//                 node = node->next;
//             }
//         }
//         if (pq.empty()) {
//             return NULL;
//         }
//         ListNode* node = new ListNode(pq.top());
//         pq.pop();
//         ListNode* head = node;
//         while (!pq.empty()) {
//             node->next = new ListNode(pq.top());
//             pq.pop();
//             node = node->next;
//         }
//         return head;
//     }
// };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) {
            return NULL;
        }
        
        while (n > 1) {
            for (int i = 0; i < n / 2; i++) {
                lists[i] = mergeTwoLists(lists[i], lists[n - i - 1]);
            }
            n = (n + 1) / 2;
        }
        
        return lists.front();
    }
private:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL && list2 == NULL) {
            return NULL;
        }
        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }
        
        ListNode* head = NULL;
        if (list1->val <= list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }
        ListNode* curr = head;
        
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        
        if (list1 == NULL) {
            curr->next = list2;
        } else {
            curr->next = list1;
        }
        
        return head;
    }
};
