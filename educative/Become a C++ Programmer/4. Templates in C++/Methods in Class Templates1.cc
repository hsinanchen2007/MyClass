/*

https://www.educative.io/module/lesson/templates-in-cpp/gx1WAMYXozk

Explanation
In the example above, we have initialized two instances of Array class namely doubleArray and intArray 
in lines 32 and 33. We・re using the generic = operator to copy the intArray elements to doubleArray in 
line 35. When you look carefully, you see that the generic = is only applicable, when both arrays have 
the same length.

In the next lesson, we have a small challenge for you to test your knowledge of class templates.

*/

// templateClassTemplateMethods.cpp

#include <algorithm>
#include <iostream>
#include <vector>

template <typename T, int N>
class Array{

public:
  Array()= default;

  template <typename T2>
  Array<T, N>& operator=(const Array<T2, N>& arr){
    elem.clear();
	  elem.insert(elem.begin(), arr.elem.begin(), arr.elem.end());
	  return *this;
  }

  int getSize() const;

  std::vector<T> elem;
};

template <typename T, int N>
int Array<T, N>::getSize() const {
  return N;
}

int main(){

  Array<double, 10> doubleArray{};
  Array<int, 10> intArray{};

  doubleArray= intArray;

  Array<std::string, 10> strArray{};
  Array<int, 100> bigIntArray{};

  // doubleArray= strArray;            // ERROR: cannot convert ．const std::basic_string<char>・ to ．double・
  // doubleArray= bigIntArray;         // ERROR: no match for ．operator=・ in ．doubleArray = bigIntArray
}
