#include <stdio.h>

int func(int a, int b, int c = 0)
{
    return a * b * c;
}

int func(int a, int b)
{
    return a + b;
}

int main(int argc, char* argv[])
{
    // cannot compile this file if below is uncommented
    // because the one with three parameters has a default
    // value, so when we call two parameters, compiler
    // doesn't know which one to call
    // int c = func(1, 2);

    // When we specify three parameters, even it has another
    // overload function, compiler clearly knows which one
    // is called as it matches three parameters one
    int c = func(1, 2, 3);

    return 0;
}

