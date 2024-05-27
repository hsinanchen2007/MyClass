#include <stdio.h>

void f()
{
    // macro will be pre-processed before compiler, so even if the macro is defined in function f(),
    // function g() can still access its value
    #define a 3

    // The const value is defined within f(), so it will be be accessible from g()
    const int b = 4;
}

void g()
{
    // Can access macro "a" value
    printf("a = %d\n", a);

    // The const int b is defined within f(), not a global variable, so g() cannot access it
    // printf("b = %d\n", b);
}

int main()
{
    const int A = 1;
    const int B = 2;

    // For C++, as the A and B are defined as const, it will be saved into lookup table
    // For later usage, they will be replaced by the values directly from lookup table,
    // so it will be come array[3] without any problem
    int array[A + B] = { 0 };

    int i = 0;

    for (i = 0; i < (A + B); i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }

    f();
    g();

    return 0;
}
