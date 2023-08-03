#include<iostream>
#include<typeinfo>
using namespace std ;
int main()
{   
    auto a = 5 ; 
    auto b = 10.5 ;
    cout << a << " " << b << "\n" ; 
    cout << typeid(a).name() << " " << typeid(b).name();
    return 0 ;
}

