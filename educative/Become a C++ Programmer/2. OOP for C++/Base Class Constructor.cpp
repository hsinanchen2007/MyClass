/*

https://www.educative.io/module/lesson/oop-in-cpp/qADVgyXJWB2

Base Class Constructor
When we make an instance of the Derived class without parameters it will first call 
the default constructor of the Base class and then the Derived class. In the same way, 
when we call the parameterized constructor of the derived class, it will first call 
the parameterized constructor of the Base class and then Derived class.

*/

#include <iostream> 
using namespace std; 
  
// Base class 
class Base {    
    
    public: 
    Base(){
      cout << "Base class default constructor!" << endl;
    }
    // Base class's parameterised constructor     
    Base(float i) {
        cout << "Base class parameterized constructor" << endl; 
    } 
}; 
  
  
// Derived class 
class Derived : public Base { 
    public:  
    Derived(){
      cout << "Derived class default constructor!" << endl;
    }
  
    // Derived class's parameterised constructor 
    Derived(float num): Base(num){ 
        cout << "Derived class parameterized constructor" << endl; 
    } 
}; 
  
// main function 
int main() {    
    // creating object of Derived Class 
    Derived obj;
    cout << endl;
    Derived obj1(10.2);
} 

// Base class default constructor!
// Derived class default constructor!
//
// Base class parameterized constructor
// Derived class parameterized constructor
