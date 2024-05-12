#include <stdio.h>

int main(int argc, char* argv[])
{
    int a = 4;

    // In C++, when reference is defined, it is required to specify initial value immediately
    int& b = a;

    b = 5;

    // variables a and b are same, even their addresses
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("&a = %p\n", &a);
    printf("&b = %p\n", &b);

    int c = 1;
    int d = 2;

    // Below in C++, it can return either value or variable itself, then we can assign a value
    // The returned variable is like a reference
    (c < d ? c : d) = 3;
    printf("c = %d, d = %d\n", c, d);

    // However, if any compared one is value, not both variables, it will have compilation error
    // (c < d ? c : 10) = 3;
    // printf("c = %d, d = %d\n", c, d);

    return 0;
}
