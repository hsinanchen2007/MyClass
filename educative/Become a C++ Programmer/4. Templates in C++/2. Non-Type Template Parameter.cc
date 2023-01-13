/*

https://www.educative.io/module/lesson/templates-in-cpp/mEZyOPn3BMG

When you define an std::array in line 12, you have to specify its size. The size is a non-type template argument, 
which has to be specified at compile-time.

Therefore, you can output array1 in line 13 with a lambda-function [] and the range-based for-loop. By using the 
summation variable sum in line 19, you can sum up the elements of the std::array. The lambda-function in line 23 
takes its arguments by reference and can, therefore, map each element to its square. There is nothing really special, 
but we are dealing with an std::array.

With C++11 we have the free function templates std::begin and std::end returning iterators for a C array. A C array 
is quite comfortable and safe to use with these function templates because we don¡¦t have to remember its size.

*/

// array.cpp

#include <algorithm>
#include <array>
#include <iostream>

int main(){

  std::cout << std::endl;

  // output the array
  std::array <int,8> array1{1,2,3,4,5,6,7,8};
  std::for_each( array1.begin(),array1.end(),[](int v){std::cout << v << " ";});

  std::cout << std::endl;

  // calculate the sum of the array by using a global variable
  int sum = 0;
  std::for_each(array1.begin(), array1.end(),[&sum](int v) { sum += v; });
  std::cout << "sum of array{1,2,3,4,5,6,7,8}: " << sum << std::endl;

  // change each array element to the second power
  std::for_each(array1.begin(), array1.end(),[](int& v) { v=v*v; });
  std::for_each( array1.begin(),array1.end(),[](int v){std::cout << v << " ";});
  std::cout << std::endl;

  std::cout << std::endl;
}

// 1 2 3 4 5 6 7 8 
// sum of array{1,2,3,4,5,6,7,8}: 36
// 1 4 9 16 25 36 49 64 
