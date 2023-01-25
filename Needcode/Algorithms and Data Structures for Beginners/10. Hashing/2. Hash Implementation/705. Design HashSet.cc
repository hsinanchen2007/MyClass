/*

https://leetcode.com/problems/design-hashset/

705. Design HashSet

Easy
2.5K
235
company
Amazon
company
Microsoft
company
Apple
Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

void add(key) Inserts the value key into the HashSet.
bool contains(key) Returns whether the value key exists in the HashSet or not.
void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
 

Example 1:

Input
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
Output
[null, null, null, true, false, null, true, null, false]

Explanation
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // return True
myHashSet.contains(3); // return False, (not found)
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // return True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // return False, (already removed)
 

Constraints:

0 <= key <= 106
At most 104 calls will be made to add, remove, and contains.

*/

// From https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/design-hashset.cpp

// Time:  O(1)
// Space: O(n)

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() : data_(10000) {
        
    }
    
    void add(int key) {
        auto& list = data_[key % data_.size()];
        auto it = find(list.begin(), list.end(), key);
        if (it == list.end()) {
            list.emplace_back(key);
        }
    }
    
    void remove(int key) {
        auto& list = data_[key % data_.size()];
        auto it = find(list.begin(), list.end(), key);
        if (it != list.end()) {
            list.erase(it);
        }
    }
    
    /** Returns true if this set did not already contain the specified element */
    bool contains(int key) {
        auto& list = data_[key % data_.size()];
        auto it = find(list.begin(), list.end(), key);
        return it != list.end();
    }

private:
    vector<list<int>> data_;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
 