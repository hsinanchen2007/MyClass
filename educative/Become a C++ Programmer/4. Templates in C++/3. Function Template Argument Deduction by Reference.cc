/*

https://www.educative.io/module/lesson/templates-in-cpp/g74ZxEkJ8j3

In the above example, we have created two functions func and constFunc in lines 4 and 7. Both of these functions accept 
parameters by reference (19 ¡V 21).

For better understanding, click here to analyze the process using C++ Insight.

*/

// functionTemplateArgumentDeductionReference.cpp

template <typename T>
void func(T& param){}

template <typename T>
void constFunc(const T& param){}

int main(){
  
  int x = 2011;
  const int cx = x;
  const int& rx = x;
  
  func(x);
  func(cx);
  func(rx);
   
  constFunc(x);
  constFunc(cx);
  constFunc(rx); 
}
