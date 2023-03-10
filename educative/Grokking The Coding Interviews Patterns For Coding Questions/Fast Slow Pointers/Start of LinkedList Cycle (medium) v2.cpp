/*

https://www.educative.io/courses/grokking-the-coding-interview/N7pvEn86YrN

Solution
If we know the length of the LinkedList cycle, we can find the start of the cycle through the following steps:

Take two pointers. Let’s call them pointer1 and pointer2.
Initialize both pointers to point to the start of the LinkedList.
We can find the length of the LinkedList cycle using the approach discussed in LinkedList Cycle. Let’s assume 
that the length of the cycle is ‘K’ nodes.
Move pointer2 ahead by ‘K’ nodes.
Now, keep incrementing pointer1 and pointer2 until they both meet.
As pointer2 is ‘K’ nodes ahead of pointer1, which means, pointer2 must have completed one loop in the cycle when 
both pointers meet. Their meeting point will be the start of the cycle.

Let’s visually see this with the above-mentioned Example-1:

    1   
    2   
    3   
    4   
    5   
    6   
    1   
    2   
    3   
    4   
    5   
    6   
    1   
    2   
    3   
    4   
    5   
    6   
 pointer1  
 pointer2  
 pointer2  
 pointer1  
 pointer1, pointer2  
    1   
    2   
    3   
    4   
    5   
    6   
 pointer1, pointer2  
 -Keep incrementing both pointers until they meet  
 -Move pointer2 '4' nodes ahead  

We can use the algorithm discussed in LinkedList Cycle to find the length of the cycle and then follow the above-mentioned 
steps to find the start of the cycle.

Code
Here is what our algorithm will look like:

Time Complexity
As we know, finding the cycle in a LinkedList with ‘N’ nodes and also finding the length of the cycle requires O(N). 
Also, as we saw in the above algorithm, we will need O(N) to find the start of the cycle. Therefore, the overall time 
complexity of our algorithm will be O(N)

Space Complexity
The algorithm runs in constant space O(1)

*/

using namespace std;

#include <iostream>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class LinkedListCycleStart {
 public:
  static ListNode *findCycleStart(ListNode *head) {
    int cycleLength = 0;
    // find the LinkedList cycle
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
      if (slow == fast) {  // found the cycle
        cycleLength = calculateCycleLength(slow);
        break;
      }
    }

    return findStart(head, cycleLength);
  }

 private:
  static int calculateCycleLength(ListNode *slow) {
    ListNode *current = slow;
    int cycleLength = 0;
    do {
      current = current->next;
      cycleLength++;
    } while (current != slow);

    return cycleLength;
  }

  static ListNode *findStart(ListNode *head, int cycleLength) {
    ListNode *pointer1 = head, *pointer2 = head;
    // move pointer2 ahead 'cycleLength' nodes
    while (cycleLength > 0) {
      pointer2 = pointer2->next;
      cycleLength--;
    }

    // increment both pointers until they meet at the start of the cycle
    while (pointer1 != pointer2) {
      pointer1 = pointer1->next;
      pointer2 = pointer2->next;
    }

    return pointer1;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);

  head->next->next->next->next->next->next = head->next->next;
  cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;

  head->next->next->next->next->next->next = head->next->next->next;
  cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;

  head->next->next->next->next->next->next = head;
  cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;
}


