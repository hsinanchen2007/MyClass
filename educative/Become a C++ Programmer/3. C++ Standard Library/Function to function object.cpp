/*

https://www.educative.io/module/lesson/cpp-standard-library/R81A3EEX7vE

Functions
Functions are the simplest callables. They can have - apart from static variables - 
no state. Because the definition of a function is often widely separated from its use 
or even in a different translation unit, the compiler has fewer opportunities to optimize 
the resulting code.

Code by function:
    #include <iostream>
    #include <vector>
    #include <algorithm>

    void square(int& i) { i = i * i; }

    int main(){
    std::vector<int> myVec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::for_each(myVec.begin(), myVec.end(), square);
    for (auto v: myVec) std::cout << v << " ";      // 1 4 9 16 25 36 49 64 81 100

    return 0;
    }

    // 1 4 9 16 25 36 49 64 81 100 


Function Objects
At first, don’t call them functors. That’s a well-defined term from the category theory.

Function objects are objects that behave like functions. They achieve this due to their 
call operator being implemented. As functions objects are objects, they can have attributes 
and therefore state.

🔑 Instantiate function objects to use them
It’s a common error that only the name of the function object (Square) and not the instance 
of function object (Square()) is used in an algorithm: std::for_each(myVec.begin(), myVec.end(), 
Square). That’s of course an error. You have to use the instance: std::for_each(myVec.begin(), 
myVec.end(), Square())

Predefined Function Objects
C++ offers a bunch of predefined function objects. They need the header <functional>. These 
predefined function objects are very useful to change the default behaviour of the containers. 
For example, the keys of the ordered associative containers are by default sorted with the predefined 
function object std::less. But you may want to use std::greater instead:

    std::map<int, std::string> myDefaultMap;                     // std::less<int>
    std::map<int, std::string, std::greater<int>> mySpecialMap;  // std::greater<int>

There are function objects in the Standard Template Library for arithmetic, logic, and bitwise 
operations, and also for negation and comparison. Here are a few of these predefined function objects:

Function object for	Representative
    Negation	std::negate<T>()
    Arithmetic	std::plus<T>(), std::minus<T>()
    std::multiplies<T>(), std::divides<T>()
    std::modulus<T>()
    Comparison	std::equal_to<T>(), std::not_equal_to<T>()
    std::less<T>(), std::greater<T>()
    std::less_equal<T>(), std::greater_equal<T>()
    Logical	std::logical_not<T>()
    std::logical_and<T>(), std::logical_or<T>()
    Bitwise	std::bit_and<T>(), std::bit_or<T>()
    std::bit_xor<T>()
Predefined function objects

*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Square{
  void operator()(int& i){i= i*i;}
};

int main(){
  std::vector<int> myVec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::for_each(myVec.begin(), myVec.end(), Square());
  for (auto v: myVec) std::cout << v << " "; // 1 4 9 16 25 36 49 64 81 100

  return 0;
}

// 1 4 9 16 25 36 49 64 81 100 