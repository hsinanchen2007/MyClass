/*

https://www.educative.io/module/lesson/cpp-standard-library/q2gK26vW8pp

Heaps
This is another popular data structure implemented in C++ using an range.

widget


?? What is a heap?
A heap is a binary search tree in which parent elements are always bigger than its child elements. 
Heap trees are optimized for the efficient sorting of elements.

You can create with std::make_heap a heap. You can push with std::push_heap new elements on the heap. 
On the contrary, you can pop the largest element with std::pop_heap from the heap. Both operations 
respect the heap characteristics. std::push_heap moves the last element of the range on the heap; 
std::pop_heap moves the biggest element of the heap to the last position in the range. You can check 
with std::is_heap if a range is a heap. You can determine with std::is_heap_until until which position 
the range is a heap. std::sort_heap sorts the heap.

The heap algorithms require that the ranges and the algorithm use the same sorting criterion. If not, 
the program is undefined. Per default, the predefined sorting criterion std::less is used. If you use 
your sorting criterion, it has to obey the strict weak ordering. If not, the program is undefined.

Creates a heap from the range:

12
void make_heap(RaIt first, RaIt last)
void make_heap(RaIt first, RaIt last, BiPre pre)
Checks if the range is a heap:

12345
bool is_heap(RaIt first, RaIt last)
bool is_heap(ExePol pol, RaIt first, RaIt last)

bool is_heap(RaIt first, RaIt last, BiPre pre)
bool is_heap(ExePol pol, RaIt first, RaIt last, BiPre pre)
Determines until which position the range is a heap:

12345
bool is_heap_until(RaIt first, RaIt last)
bool is_heap_until(ExePol pol, RaIt first, RaIt last)

bool is_heap_until(RaIt first, RaIt last, BiPre pre)
bool is_heap_until(ExePol pol, RaIt first, RaIt last, BiPre pre)
Sorts the heap:

12
void sort_heap(RaIt first, RaIt last)
void sort_heap(RaIt first, RaIt last, BiPre pre)
Pushes the last element of the range onto the heap. [first, last-1) has to be a heap.

12
void push_heap(RaIt first, RaIt last)
void push_heap(RaIt first, RaIt last, BiPre pre)
Removes the biggest element from the heap and puts it to the end of the range:

12
void pop_heap(RaIt first, RaIt last)
void pop_heap(RaIt first, RaIt last, BiPre pre)
Withstd::pop_heap you can remove the biggest element from the heap. Afterwards, the biggest element is 
the last element of the range. To remove it from the heap h, use h.pop_back.

*/

#include <algorithm>
#include <iostream>
#include <vector>
 
int main(){
 
  std::cout << std::boolalpha << std::endl;
 
  std::vector<int> vec{4, 3, 2, 1, 5, 6, 7, 9, 10};
  for (auto v: vec) std::cout << v << " ";
  std::cout << std::endl;
 
  std::make_heap(vec.begin(), vec.end());
  for (auto v: vec) std::cout << v << " ";
  std::cout << std::endl;
   
  std::cout << "std::is_heap(vec.begin(), vec.end()): " << std::is_heap(vec.begin(), vec.end()) << std::endl;
   
  std::cout << std::endl;
  
  vec.push_back(100);
  std::cout << "std::is_heap(vec.begin(), vec.end()): " << std::is_heap(vec.begin(), vec.end()) << std::endl;
  std::cout << "*std::is_heap_until(vec.begin(), vec.end()): " << *std::is_heap_until(vec.begin(), vec.end()) << std::endl;
  for (auto v: vec) std::cout << v << " ";
  std::push_heap(vec.begin(), vec.end());
  std::cout << "std::is_heap(vec.begin(), vec.end()): " << std::is_heap(vec.begin(), vec.end()) << std::endl;
  std::cout << std::endl;
  for (auto v: vec) std::cout << v << " ";
   
  std::cout << "\n\n";
   
  std::pop_heap(vec.begin(), vec.end());
  for (auto v: vec) std::cout << v << " ";
  std::cout << std::endl;
  std::cout << "*std::is_heap_until(vec.begin(), vec.end()): " << *std::is_heap_until(vec.begin(), vec.end()) << std::endl;
  vec.resize(vec.size() - 1);
  std::cout << "std::is_heap(vec.begin(), vec.end()): " << std::is_heap(vec.begin(), vec.end()) << std::endl;
   
  std::cout << std::endl;
   
  std::cout << "vec.front(): " << vec.front() << std::endl;
    
  std::cout << std::endl;
 
}

//
// 4 3 2 1 5 6 7 9 10 
// 10 9 7 4 5 6 2 3 1 
// std::is_heap(vec.begin(), vec.end()): true
//
// std::is_heap(vec.begin(), vec.end()): false
// *std::is_heap_until(vec.begin(), vec.end()): 100
// 10 9 7 4 5 6 2 3 1 100 std::is_heap(vec.begin(), vec.end()): true
// 
// 100 10 7 4 9 6 2 3 1 5 
//
// 10 9 7 4 5 6 2 3 1 100 
// *std::is_heap_until(vec.begin(), vec.end()): 100
// std::is_heap(vec.begin(), vec.end()): true
//
// vec.front(): 10
