/*

https://www.educative.io/courses/grokking-the-coding-interview/B1gBkopEBzk

Solution
This problem follows the Top ‘K’ Elements pattern and is quite similar to Rearrange String 
K Distance Apart. We need to rearrange tasks such that same tasks are ‘K’ distance apart.

Following a similar approach, we will use a Max Heap to execute the highest frequency task 
first. After executing a task we decrease its frequency and put it in a waiting list. In each 
iteration, we will try to execute as many as k+1 tasks. For the next iteration, we will put 
all the waiting tasks back in the Max Heap. If, for any iteration, we are not able to execute 
k+1 tasks, the CPU has to remain idle for the remaining time in the next iteration.

Time complexity
The time complexity of the above algorithm is O(N*logN) where ‘N’ is the number of tasks. 
Our while loop will iterate once for each occurrence of the task in the input (i.e. ‘N’) 
and in each iteration we will remove a task from the heap which will take O(logN) time. 
Hence the overall time complexity of our algorithm is O(N*logN).

Space complexity
The space complexity will be O(N), as in the worst case, we need to store all the ‘N’ tasks 
in the HashMap.

*/

using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TaskScheduler {
 public:
  struct valueCompare {
    char operator()(const pair<int, int> &x, const pair<int, int> &y) {
      return y.second > x.second;
    }
  };

  static int scheduleTasks(vector<char> &tasks, int k) {
    int intervalCount = 0;
    unordered_map<char, int> taskFrequencyMap;
    for (char chr : tasks) {
      taskFrequencyMap[chr]++;
    }

    priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare> maxHeap;

    // add all tasks to the max heap
    for (auto entry : taskFrequencyMap) {
      maxHeap.push(entry);
    }

    while (!maxHeap.empty()) {
      vector<pair<char, int>> waitList;
      int n = k + 1;  // try to execute as many as 'k+1' tasks from the max-heap
      for (; n > 0 && !maxHeap.empty(); n--) {
        intervalCount++;
        auto currentEntry = maxHeap.top();
        maxHeap.pop();
        if (currentEntry.second > 1) {
          currentEntry.second--;
          waitList.push_back(currentEntry);
        }
      }
      // put all the waiting list back on the heap
      for (auto it = waitList.begin(); it != waitList.end(); it++) {
        maxHeap.push(*it);
      }
      if (!maxHeap.empty()) {
        intervalCount += n;  // we'll be having 'n' idle intervals for the next iteration
      }
    }

    return intervalCount;
  }
};

int main(int argc, char *argv[]) {
  vector<char> tasks = {'a', 'a', 'a', 'b', 'c', 'c'};
  cout << "Minimum intervals needed to execute all tasks: "
       << TaskScheduler::scheduleTasks(tasks, 2) << endl;

  tasks = vector<char>{'a', 'b', 'a'};
  cout << "Minimum intervals needed to execute all tasks: "
       << TaskScheduler::scheduleTasks(tasks, 3) << endl;
}
