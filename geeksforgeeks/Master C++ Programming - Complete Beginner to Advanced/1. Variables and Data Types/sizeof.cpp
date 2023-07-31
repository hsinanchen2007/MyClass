#include<iostream>
using namespace std ;
int main()
{   
    cout << sizeof(int)       << "\n"
         << sizeof(char)      << "\n"
         << sizeof(long long) << "\n"
         << sizeof(float)     << "\n"
         << sizeof(10ll)      << "\n"
         << sizeof(3.4)       << "\n"
         << sizeof(3.4f)      << "\n" ; 
    int var = 5 ;
    cout << sizeof(var ++) << "\n" ; 
    cout << var << "\n" ; 
    return 0 ;
}
