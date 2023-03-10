/*

https://www.educative.io/courses/grokking-the-coding-interview/RLwKZWgMJ1q

Solution 
This problem follows the Merge Intervals pattern. Let’s take the above-mentioned example (2) and 
visually draw it:

Input: Employee Working Hours=[[[1,3], [9,12]], [[2,4]], [[6,8]]]
Output: [4,6], [8,9]
svg viewer

One simple solution can be to put all employees’ working hours in a list and sort them on the start 
time. Then we can iterate through the list to find the gaps. Let’s dig deeper. Sorting the intervals 
of the above example will give us:

[1,3], [2,4], [6,8], [9,12]
We can now iterate through these intervals, and whenever we find non-overlapping intervals (e.g., 
[2,4] and [6,8]), we can calculate a free interval (e.g., [4,6]). This algorithm will take O(N * logN) 
time, where ‘N’ is the total number of intervals. This time is needed because we need to sort all 
the intervals. The space complexity will be O(N), which is needed for sorting. Can we find a better 
solution?

Using a Heap to Sort the Intervals
One fact that we are not utilizing is that each employee list is individually sorted!

How about we take the first interval of each employee and insert it in a Min Heap. This Min Heap can 
always give us the interval with the smallest start time. Once we have the smallest start-time interval, 
we can then compare it with the next smallest start-time interval (again from the Heap) to find the gap. 
This interval comparison is similar to what we suggested in the previous approach.

Whenever we take an interval out of the Min Heap, we can insert the same employee’s next interval. This 
also means that we need to know which interval belongs to which employee.

Time complexity
The above algorithm’s time complexity is O(N*logK), where ‘N’ is the total number of intervals, and ‘K’ 
is the total number of employees. This is because we are iterating through the intervals only once 
(which will take O(N)), and every time we process an interval, we remove (and can insert) one interval 
in the Min Heap, (which will take O(logK)). At any time, the heap will not have more than ‘K’ elements.

Space complexity
The space complexity of the above algorithm will be O(K) as at any time, the heap will not have more than 
‘K’ elements.

*/

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class Interval {
 public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class EmployeeFreeTime {
 public:
  struct startCompare {
    bool operator()(const pair<Interval, pair<int, int>> &x,
                    const pair<Interval, pair<int, int>> &y) {
      return x.first.start > y.first.start;
    }
  };

  static vector<Interval> findEmployeeFreeTime(const vector<vector<Interval>> &schedule) {
    vector<Interval> result;
    if (schedule.empty()) {
      return result;
    }

    // PriorityQueue to store one interval from each employee
    priority_queue<pair<Interval, pair<int, int>>, vector<pair<Interval, pair<int, int>>>,
                   startCompare>
        minHeap;

    // insert the first interval of each employee to the queue
    for (int i = 0; i < schedule.size(); i++) {
      minHeap.push(make_pair(schedule[i][0], make_pair(i, 0)));
    }

    Interval previousInterval = minHeap.top().first;
    while (!minHeap.empty()) {
      auto queueTop = minHeap.top();
      minHeap.pop();
      // if previousInterval is not overlapping with the next interval, insert a free interval
      if (previousInterval.end < queueTop.first.start) {
        result.push_back({previousInterval.end, queueTop.first.start});
        previousInterval = queueTop.first;
      } else {  // overlapping intervals, update the previousInterval if needed
        if (previousInterval.end < queueTop.first.end) {
          previousInterval = queueTop.first;
        }
      }

      // if there are more intervals available for the same employee, add their next interval
      vector<Interval> employeeSchedule = schedule[queueTop.second.first];
      if (employeeSchedule.size() > queueTop.second.second + 1) {
        minHeap.push(make_pair(employeeSchedule[queueTop.second.second + 1],
                               make_pair(queueTop.second.first, queueTop.second.second + 1)));
      }
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<Interval>> input = {{{1, 3}, {5, 6}}, {{2, 3}, {6, 8}}};
  vector<Interval> result = EmployeeFreeTime::findEmployeeFreeTime(input);
  cout << "Free intervals: ";
  for (auto interval : result) {
    cout << "[" << interval.start << ", " << interval.end << "] ";
  }
  cout << endl;

  input = {{{1, 3}, {9, 12}}, {{2, 4}}, {{6, 8}}};
  result = EmployeeFreeTime::findEmployeeFreeTime(input);
  cout << "Free intervals: ";
  for (auto interval : result) {
    cout << "[" << interval.start << ", " << interval.end << "] ";
  }
  cout << endl;

  input = {{{1, 3}}, {{2, 4}}, {{3, 5}, {7, 9}}};
  result = EmployeeFreeTime::findEmployeeFreeTime(input);
  cout << "Free intervals: ";
  for (auto interval : result) {
    cout << "[" << interval.start << ", " << interval.end << "] ";
  }
}

