#include <stdio.h>

void Example()
{
    printf("Example:\n");

    int a = 4;
    const int& b = a;
    int* p = (int*)&b;

    //b = 5;

    *p = 5;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
}

void Demo()
{
    printf("Demo:\n");

    // When a const reference variable is defined, C++ will allocate a space 
    // to save this variable with valid address, but if its value is changed
    // from its pointer, not reference, the value will be changed as well
    const int& c = 1;
    int* p = (int*)&c;

    // Cannot assign value directly to c as it is defined as const reference
    //c = 5;

    *p = 5;

    printf("c = %d, c address = %p, p address = %p\n", c, &c,p);

    // Note, if not reference, const value won't be changed accordingly.
    // Value "d" will be retrieved from lookup table directly 
    const int d = 10;
    int* q = (int*)&d;

    *q = 100;

    printf("d = %d, q = %d, d address = %p, q address = %p\n", d, *q, &d, q);
}

int main(int argc, char* argv[])
{
    Example();

    printf("\n");

    Demo();

    return 0;
}
