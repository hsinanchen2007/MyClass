#include <stdio.h>

class Test
{
    int i;
public:
    // constructor without parameter
    Test()
    {
        printf("Test::Test()\n");
        this->i = 0;
    }

    // constructor with one parameter
    Test(int i)
    {
        printf("Test::Test(int i)\n");
        this->i = i;
    }

    // copy constructor
    Test(const Test& obj)
    {
        printf("Test(const Test& obj)\n");
        this->i = obj.i;
    }

    // static member function of this class
    static void func()
    {
        printf("void Test::func()\n");
    }

    // class object member function
    void func(int i)
    {
        printf("void Test::func(int i), i = %d\n", i);
    }

    int getI()
    {
        return i;
    }
};

// global function
void func()
{
    printf("void func()\n");
}

// global function overloaded with one parameter
void func(int i)
{
    printf("void func(int i), i = %d\n", i);
}

int main()
{
    func();
    func(1);

    Test t;        // Test::Test()
    Test t1(1);    // Test::Test(int i)
    Test t2(t1);   // Test(const Test& obj)

    func();        // void func()
    Test::func();  // void Test::func()

    func(2);       // void func(int i), i = 2;
    t1.func(2);    // void Test::func(int i), i = 2
    t1.func();     // void Test::func()

    return 0;
}
