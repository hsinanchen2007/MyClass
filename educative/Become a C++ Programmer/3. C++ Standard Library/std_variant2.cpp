/*

https://www.educative.io/module/lesson/cpp-standard-library/7DxED8WV7yy

Each variant in this example can hold a char, long, float, int, double, or long long. 
The first visitor [](auto&& arg){std::cout << arg << " ";} will output the various variants. 
The second visitor std::cout << typeid(arg).name() << " ";} will display its types.

Now I want to sum up the elements of the variants. First I need the right result type at 
compile time. std::common_type from the type traits library will provide it. std::common_type 
gives the type to which all types char, long, float, int, double, and long long can implicitly 
be converted to. The final {} in res{} causes it to be initialised to 0.0. res is of type double.

The visitor [&res](auto&& arg){arg *= 2;} doubles each element and the following line displays 
the result.

*/

// visit.cpp 
#include <iostream>
#include <variant>
#include <vector>

using namespace std;

int main(){
  std::vector<std::variant<char, long, float, int, double, long long>>      
           vecVariant = {5, '2', 5.4, 100ll, 2011l, 3.5f, 2017};

  for (auto& v: vecVariant){        
    std::visit([](auto&& arg){std::cout << arg << " ";}, v);    
                                   // 5 2 5.4 100 2011 3.5 2017                
  }
  cout<<std::endl;
  
  // display each type
  for (auto& v: vecVariant){
    std::visit([](auto&& arg){std::cout << typeid(arg).name() << " ";}, v);  
                                  // i c d x l f i (these letters refer to int char double __int64 long float int respectively
  }
  cout<<endl;
  
  // get the sum
  std::common_type<char, long, float, int, double, long long>::type res{};  
 
  std::cout << typeid(res).name() << std::endl;        // d (for double)
  
  for (auto& v: vecVariant){
    std::visit([&res](auto&& arg){res+= arg;}, v);     
  }
  std::cout << "res: " << res << std::endl;            // res: 4191.9
  
  // double each value
  for (auto& v: vecVariant){
    std::visit([](auto&& arg){arg *= 2;}, v);                           
    std::visit([](auto&& arg){std::cout << arg << " ";}, v);   
                                 // 10 d 10.8 200 4022 7 4034
  }
  return 0;
}

// 5 2 5.4 100 2011 3.5 2017 
// i c d x l f i 
// d
// res: 4191.9
// 10 d 10.8 200 4022 7 4034 
