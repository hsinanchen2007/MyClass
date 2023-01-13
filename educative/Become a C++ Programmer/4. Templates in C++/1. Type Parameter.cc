/*

https://www.educative.io/module/lesson/templates-in-cpp/mEZyOPn3BMG

In the above code, we are identifying the type of different data types that we have passed in the parameter list. 
We can identify the type of variable passed to the function by using the keyword typeid in line 25. If we pass 
string or class type object in the parameter list, it will display the type of parameter passed along with the size 
of the object.

*/

// templateTypeParameter.cpp

#include <iostream>
#include <typeinfo>

class Account{
public:
  explicit Account(double amt): balance(amt){}
private:
  double balance;

};

union WithString{
  std::string s;
  int i;
  WithString():s("hello"){}
  ~WithString(){}
};

template <typename T>
class ClassTemplate{
public:
  ClassTemplate(){
    std::cout << "typeid(T).name(): "  << typeid(T).name() << std::endl;
  }
};

int main(){

  std::cout << std::endl;

  ClassTemplate<int> clTempInt;
  ClassTemplate<double> clTempDouble;
  ClassTemplate<std::string> clTempString;

  ClassTemplate<Account> clTempAccount;
  ClassTemplate<WithString> clTempWithString;

  std::cout << std::endl;

}

// typeid(T).name(): i
// typeid(T).name(): d
// typeid(T).name(): NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
// typeid(T).name(): 7Account
// typeid(T).name(): 10WithString
