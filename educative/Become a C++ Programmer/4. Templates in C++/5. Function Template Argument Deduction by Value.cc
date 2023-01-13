/*

https://www.educative.io/module/lesson/templates-in-cpp/g74ZxEkJ8j3

In the above example, we have implemented a function funcValue in line 4 which takes its parameter by value.

For better understanding click here to analyze the process using C++ Insight.

*/

// functionTemplateArgumentDeductionValue.cpp

template <typename T>
void funcValue(T param){}

int main(){
  
  int x = 2011;
  const int cx = x;
  const int& rx = x;
  
  funcValue(x);
  funcValue(cx);
  funcValue(rx); 
}
