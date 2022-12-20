/*

https://www.educative.io/courses/grokking-the-coding-interview/R8o6vV83DLY

Solution
This problem follows the Top ‘K’ Elements pattern, and shares similarities with Top ‘K’ 
Frequent Numbers.

We can use a Max Heap to store the numbers. Instead of comparing the numbers we will compare 
their frequencies so that the root of the heap is always the most frequently occurring 
number. There are two issues that need to be resolved though:

How can we keep track of the frequencies of numbers in the heap? When we are pushing a new 
number to the Max Heap, we don’t know how many times the number has already appeared in the 
Max Heap. To resolve this, we will maintain a HashMap to store the current frequency of each 
number. Thus whenever we push a new number in the heap, we will increment its frequency in 
the HashMap and when we pop, we will decrement its frequency.
If two numbers have the same frequency, we will need to return the number which was pushed 
later while popping. To resolve this, we need to attach a sequence number to every number 
to know which number came first.

In short, we will keep three things with every number that we push to the heap:

    1. number // value of the number
    2. frequency // current frequency of the number when it was pushed to the heap
    3. sequenceNumber // a sequence number, to know what number came first

Time complexity
The time complexity of push() and pop() is O(logN) where ‘N’ is the current number of elements 
in the heap.

Space complexity
We will need O(N) space for the heap and the map, so the overall space complexity of the algorithm 
is O(N)

*/

using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

class Element {
 public:
  int number = 0;
  int frequency = 0;
  int sequenceNumber = 0;

  Element(int number, int frequency, int sequenceNumber) {
    this->number = number;
    this->frequency = frequency;
    this->sequenceNumber = sequenceNumber;
  }
};

class FrequencyStack {
 public:
  struct frequencyCompare {
    bool operator()(const Element &e1, const Element &e2) {
      if (e1.frequency != e2.frequency) {
        return e2.frequency > e1.frequency;
      }
      // if both elements have same frequency, return the one that was pushed later
      return e2.sequenceNumber > e1.sequenceNumber;
    }
  };

  int sequenceNumber = 0;
  priority_queue<Element, vector<Element>, frequencyCompare> maxHeap;
  unordered_map<int, int> frequencyMap;

  virtual void push(int num) {
    frequencyMap[num] += 1;
    maxHeap.push({num, frequencyMap[num], sequenceNumber++});
  }

  virtual int pop() {
    int num = maxHeap.top().number;
    maxHeap.pop();

    // decrement the frequency or remove if this is the last number
    if (frequencyMap[num] > 1) {
      frequencyMap[num] -= 1;
    } else {
      frequencyMap.erase(num);
    }

    return num;
  }
};

int main(int argc, char *argv[]) {
  FrequencyStack frequencyStack;
  frequencyStack.push(1);
  frequencyStack.push(2);
  frequencyStack.push(3);
  frequencyStack.push(2);
  frequencyStack.push(1);
  frequencyStack.push(2);
  frequencyStack.push(5);
  cout << frequencyStack.pop() << endl;
  cout << frequencyStack.pop() << endl;
  cout << frequencyStack.pop() << endl;
}

