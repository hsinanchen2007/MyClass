#include<iostream>
using namespace std ;

class SP{
    int *ptr;
public:
    SP(int *p = NULL)
    {
        ptr = p;
    }
    ~SP()
    {
        delete ptr;
    }
    int& operator * ()
    {
        return *ptr;
    }
};

int main()
{
    SP sp(new int());
    *sp = 20;
    cout << *sp;
    return 0 ;
}



#include<iostream>
using namespace std ;

class Test 
{
public:
    int x, y;
    Test(int a = 9, int b = 0)
    {
        x = a;
        y = b;
        cout << "Constructor Called \n";
    }
    ~Test()
    {
        cout << "Destructor Called \n";
    }
};

class SP
{
    Test *ptr;
public:
    SP(Test *p = NULL)
    {
        ptr = p;
    }
    ~SP()
    {
        delete ptr;
    }
    Test& operator * ()
    {
        return *ptr;
    }
    Test* operator -> ()
    {
        return ptr;
    }
};

int main()
{
    cout << "Main Begins \n";
    {
        SP sp(new Test(10, 20));
    }
    cout << "Main Ends \n";
    return 0 ;
}



#include<iostream>
using namespace std ;

template<class T>
class SP{
    T *ptr;
public:
    SP(T *p = NULL)
    {
        ptr = p;
    }
    ~SP()
    {
        delete ptr;
    }
    T& operator * ()
    {
        return *ptr;
    }
    T* operator -> ()
    {
        return ptr;
    }
};

int main()
{
    SP<int> sp(new int());
    *sp = 20;
    cout << *sp;
    return 0 ;
}





