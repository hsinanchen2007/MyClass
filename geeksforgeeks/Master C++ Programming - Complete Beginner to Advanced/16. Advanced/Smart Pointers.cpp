#include<iostream>
#include<memory>
using namespace std ;

class Test 
{
    int x;
public:
    Test(int a = 0)
    {
        x = a;
        cout << "Constructor \n";
    }
    ~Test()
    {
        cout << "Destructor \n";
    }
    void fun()
    {
        cout << x << endl;
    }
};

int main()
{
    cout << "Main Begins \n";
    {
        unique_ptr<Test> ptr(new Test(9));
        ptr -> fun();
    }
    cout << "Main Ends \n";
    return 0 ;
}



#include<iostream>
#include<memory>
using namespace std ;

class Test 
{
    int x;
public:
    Test(int a = 0)
    {
        x = a;
        cout << "Constructor \n";
    }
    ~Test()
    {
        cout << "Destructor \n";
    }
    void fun()
    {
        cout << x << endl;
    }
};

int main()
{
    unique_ptr<Test> ptr1 = make_unique<Test>(10);
    auto ptr2 = move(ptr1);
    ptr2 -> fun();
    return 0 ;
}



#include<iostream>
#include<memory>
using namespace std ;

class Test 
{
    int x;
public:
    Test(int a = 0)
    {
        x = a;
        cout << "Constructor \n";
    }
    ~Test()
    {
        cout << "Destructor \n";
    }
    void fun()
    {
        cout << x << endl;
    }
};

int main()
{
    shared_ptr<Test> ptr1 = make_shared<Test>(10);
    auto ptr2 = (ptr1);
    cout << ptr1.use_count() << ' ' << ptr2.use_count() << '\n';
    return 0 ;
}



#include<iostream>
#include<memory>
using namespace std ;

class Test 
{
    int x;
public:
    Test(int a = 0)
    {
        x = a;
        cout << "Constructor \n";
    }
    ~Test()
    {
        cout << "Destructor \n";
    }
    void fun()
    {
        cout << x << endl;
    }
};

int main()
{
    shared_ptr<Test> p1;
    {
        auto p2 = make_shared<Test>(10);
        p1 = p2;
    }
    cout << "Main Ends \n";
    return 0 ;
}



#include<iostream>
#include<memory>
using namespace std ;

class Test 
{
    int x;
public:
    Test(int a = 0)
    {
        x = a;
        cout << "Constructor \n";
    }
    ~Test()
    {
        cout << "Destructor \n";
    }
    void fun()
    {
        cout << x << endl;
    }
};

int main()
{
    shared_ptr<Test> p1;
    {
        auto p2 = make_shared<Test>(10);
    }
    cout << "Main Ends \n";
    return 0 ;
}



#include<iostream>
#include<memory>
using namespace std ;

class Test 
{
    int x;
public:
    Test(int a = 0)
    {
        x = a;
        cout << "Constructor \n";
    }
    ~Test()
    {
        cout << "Destructor \n";
    }
    void fun()
    {
        cout << x << endl;
    }
};

int main()
{
    weak_ptr<Test> p1;
    {
        auto p2 = make_shared<Test>(10);
        p1 = p2;
    }
    cout << "Main Ends \n";
    return 0 ;
}



#include<iostream>
#include<memory>
using namespace std ;

class Test 
{
    int x;
public:
    Test(int a = 0)
    {
        x = a;
        cout << "Constructor \n";
    }
    ~Test()
    {
        cout << "Destructor \n";
    }
    void fun()
    {
        cout << x << endl;
    }
};

int main()
{
    weak_ptr<Test> p1;
    {
        auto p2 = make_shared<Test>(10);
        p1 = p2;
        cout << p2.use_count() << endl;
        shared_ptr<Test>p3  = p1.lock();
    }
    cout << p1.expired() << endl;
    
    return 0 ;
}
