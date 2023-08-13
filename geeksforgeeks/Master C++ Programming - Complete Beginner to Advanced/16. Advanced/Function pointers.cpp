#include<iostream>
using namespace std ;

void fun()
{
    cout << "GFG \n";
}
int main()
{
    // void (*fun_ptr)() = &fun;
    // void (*fun_ptr)() = fun;
    auto fun_ptr = fun;
    fun_ptr();
    // (*fun_ptr)();
    return 0 ;
}



#include<iostream>
using namespace std ;

int fun(int x, int y)
{
    return (x+y);
}
int main()
{
    auto fun_ptr = fun;
    // here auto is int (*fun_ptr) (int, int)
    cout << fun_ptr(10, 20);
    return 0 ;
}

