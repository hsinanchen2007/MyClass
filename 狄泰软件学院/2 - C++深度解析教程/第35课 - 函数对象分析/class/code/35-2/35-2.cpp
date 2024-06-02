#include <iostream>
#include <string>

using namespace std;

// Solution by function object way
// 1. Standalone by each object/call
// 2. Can specify its owned initial value
// 3. Perform same functionality like normal function
class Fib
{
    int a0;
    int a1;
public:
    Fib()
    {
        a0 = 0;
        a1 = 1;
    }

    Fib(int n)
    {
        a0 = 0;
        a1 = 1;

        for (int i = 2; i <= n; i++)
        {
            // "t" is return actually
            int t = a1;

            a1 = a0 + a1;
            a0 = t;
        }
    }

    // Here is the key. For function object,
    // in addition to its constructor, we need
    // a operator overload call "()" to make
    // it works like a normal function
    // So when it is being called like the
    // "className()", it is not a constructor
    // at the beginning of its first time
    // Its behavior will be like calling a 
    // normal function functionName(...)
    // Note that second "()" can also have some
    // parameters, not always empty
    // https://www.geeksforgeeks.org/functors-in-cpp/?ref=gcse
    int operator () ()
    {
        int ret = a1;

        a1 = a0 + a1;
        a0 = ret;

        return ret;
    }
};

int main()
{
    // define first function object "fib"
    // with default initial value
    Fib fib;

    for (int i = 0; i < 10; i++)
    {
        cout << fib() << endl;
    }

    cout << endl;

    // can keep calling the first function 
    // object and keep calculation result
    for (int i = 0; i < 5; i++)
    {
        cout << fib() << endl;
    }

    cout << endl;

    // define second function object with
    // given initial parameter, and it works 
    // like a standalone one, nothing related
    // to first function object
    Fib fib2(10);

    for (int i = 0; i < 5; i++)
    {
        cout << fib2() << endl;
    }

    return 0;
}
