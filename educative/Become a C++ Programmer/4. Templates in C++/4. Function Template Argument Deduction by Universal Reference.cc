/*

https://www.educative.io/module/lesson/templates-in-cpp/g74ZxEkJ8j3

In the above code, we have defined a function funcUniversal in line 4 which accepts its parameters with a universal reference.

For better understanding click here to analyze the process using C++ Insight.

*/

// functionTemplateArgumentDeductionUniversalReference.cpp

template <typename T>
void funcUniversal(T&& param){}


int main(){
  
  int x = 2011;
  const int cx = x;
  const int& rx = x;
  
  funcUniversal(x);
  funcUniversal(cx);
  funcUniversal(rx);
  funcUniversal(2014); 
}