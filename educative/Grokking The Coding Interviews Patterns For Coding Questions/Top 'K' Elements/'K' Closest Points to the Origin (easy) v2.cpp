/*

https://www.educative.io/courses/grokking-the-coding-interview/3YxNVYwNR5p

Solution
The Euclidean distance of a point P(x,y) from the origin can be calculated through the 
following formula:

sqrt{x^2 + y^2}

This problem follows the Top ‘K’ Numbers pattern. The only difference in this problem is 
that we need to find the closest point (to the origin) as compared to finding the largest 
numbers.

Following a similar approach, we can use a Max Heap to find ‘K’ points closest to the origin. 
While iterating through all points, if a point (say ‘P’) is closer to the origin than the 
top point of the max-heap, we will remove that top point from the heap and add ‘P’ to always 
keep the closest points in the heap.

Time complexity
The time complexity of this algorithm is (N*logK) as we iterating all points and pushing 
them into the heap.

Space complexity
The space complexity will be O(K) because we need to store ‘K’ point in the heap.

*/

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class Point {
 public:
  int x = 0;
  int y = 0;

  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }

  int distFromOrigin() const {
    // ignoring sqrt
    return (x * x) + (y * y);
  }

  const bool operator<(const Point& p) { return p.distFromOrigin() > this->distFromOrigin(); }
};

class KClosestPointsToOrigin {
 public:
  static vector<Point> findClosestPoints(const vector<Point>& points, int k) {
    // put first 'k' points in the vector
    vector<Point> maxHeap(points.begin(), points.begin() + k);
    make_heap(maxHeap.begin(), maxHeap.end());

    // go through the remaining points of the input array, if a point is closer to the origin than
    // the top point of the max-heap, remove the top point from heap and add the point from the
    // input array
    for (int i = k; i < points.size(); i++) {
      if (points[i].distFromOrigin() < maxHeap.front().distFromOrigin()) {
        pop_heap(maxHeap.begin(), maxHeap.end());
        maxHeap.pop_back();
        maxHeap.push_back(points[i]);
        push_heap(maxHeap.begin(), maxHeap.end());
      }
    }

    // the heap has 'k' points closest to the origin
    return maxHeap;
  }
};

int main(int argc, char* argv[]) {
  vector<Point> maxHeap = KClosestPointsToOrigin::findClosestPoints({{1, 3}, {3, 4}, {2, -1}}, 2);
  cout << "Here are the k points closest the origin: ";
  for (auto p : maxHeap) {
    cout << "[" << p.x << " , " << p.y << "] ";
  }
}
