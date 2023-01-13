/*

https://www.educative.io/module/lesson/templates-in-cpp/g74ZxEkJ8j3

In the above example, we have defined 3 function templates

isSmaller takes two arguments which have the same type and returns true if the first element is less than the second element (line 6). 
Invoking the function with arguments of different types would give a compile-time error (line 25).

isSmaller2 takes two arguments which can have a different type. The function returns true if the first element is less than the second 
element (line 11). add takes two arguments which can have different types (line 16). The return type must be specified because it cannot 
be deduced from the function arguments.

*/

// templateArgumentDeduction.cpp

#include <iostream>

template <typename T>
bool isSmaller(T fir, T sec){
  return fir < sec;
}

template <typename T, typename U>
bool isSmaller2(T fir, U sec){
  return fir < sec;
}

template <typename R, typename T, typename U>
R add(T fir, U sec){
  return fir + sec;
}

int main(){

  std::cout << std::boolalpha << std::endl;

  std::cout << "isSmaller(1,2): " << isSmaller(1,2) << std::endl;
  // std::cout << "isSmaller(1,5LL): "  << isSmaller(1,5LL) << std::endl; // ERROR

  std::cout << "isSmaller<int>(1,5LL): " << isSmaller<int>(1,5LL) << std::endl;
  std::cout << "isSmaller<double>(1,5LL): " << isSmaller<double>(1,5LL) << std::endl;

  std::cout << std::endl;

  std::cout << "isSmaller2(1,5LL): "  << isSmaller2(1,5LL) << std::endl;

  std::cout << std::endl;

  std::cout << "add<long long int>(1000000,1000000): " << add<long long int>(1000000, 1000000) << std::endl;
  std::cout << "add<double,double>(1000000,1000000): " << add<double,double>(1000000, 1000000) << std::endl;
  std::cout << "add<double,double,float>(1000000,1000000): " << add<double,double,float>(1000000, 1000000) << std::endl;

  std::cout << std::endl;
}

// isSmaller(1,2): true
// isSmaller<int>(1,5LL): true
// isSmaller<double>(1,5LL): true
//
// isSmaller2(1,5LL): true
//
// add<long long int>(1000000,1000000): 2000000
// add<double,double>(1000000,1000000): 2e+06
//add<double,double,float>(1000000,1000000): 2e+06
