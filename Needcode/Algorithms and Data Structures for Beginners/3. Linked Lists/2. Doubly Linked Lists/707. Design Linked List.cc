/*

https://leetcode.com/problems/design-linked-list/

707. Design Linked List

Medium
2K
1.4K
company
Microsoft
company
Google
Virtu Financial
Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
 

Example 1:

Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3
 

Constraints:

0 <= index, val <= 1000
Please do not use the built-in LinkedList library.
At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and deleteAtIndex.

*/

// From https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/design-linked-list.cpp

// Time:  O(n)
// Space: O(n)

struct Node {
    Node(int value) :
         val(value),
         next(nullptr),
         prev(nullptr) {}
    int val;
    Node *next;
    Node *prev;
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() : size_(0) {
        head_ = tail_ = new Node(-1);
        head_->next = tail_;
        tail_->prev = head_;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (0 <= index && index <= size_ / 2) {
            return forward(0, index, head_->next)->val;
        } else if (size_ / 2 < index && index < size_) {
            return backward(size_, index, tail_)->val;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list.
        After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        add(head_, val);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        add(tail_->prev, val);
    }
    
    /** Add a node of value val before the index-th node in the linked list.
        If index equals to the length of linked list,
        the node will be appended to the end of linked list.
        If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (0 <= index && index <= size_ / 2) {
            add(forward(0, index, head_->next)->prev, val);
        } else if (size_ / 2 < index && index <= size_) {
            add(backward(size_, index, tail_)->prev, val);
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (0 <= index && index <= size_ / 2) {
            remove(forward(0, index, head_->next));
        } else if (size_ / 2 < index && index < size_) {
            remove(backward(size_, index, tail_));
        }
    }
    
private:
    void add(Node *preNode, int val) {
        auto node = new Node(val);
        node->prev = preNode;
        node->next = preNode->next;
        node->prev->next = node->next->prev = node;
        ++size_;
    }
        
    void remove(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        --size_;
    }
        
    Node *forward(int start, int end, Node *curr) {
        while (start != end) {
            ++start;
            curr = curr->next;
        }
        return curr;
    }
    
    Node *backward(int start, int end, Node *curr) {
        while (start != end) {
            --start;
            curr = curr->prev;
        }
        return curr;
    }

    Node *head_;
    Node *tail_;
    int size_;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
 