#include <stdio.h>

int main(int argc, char* argv[])
{
    // In C++, as long as variable is defined as bool, internally, 
    // it will set it to 0 if value is false/0, and 1 if value is 
    // true or not 0
    bool b = false;

    int a = b;

    // bool is only using one byte
    printf("sizeof(b) = %zd\n", sizeof(b));

    printf("b = %d, a = %d\n", b, a);

    b = 3;
    a = b;

    printf("b = %d, a = %d\n", b, a);

    b = -5;
    a = b;

    printf("b = %d, a = %d\n", b, a);

    a = 10;
    b = a;

    printf("a = %d, b = %d\n", a, b);

    a = 0;
    b = a;

    printf("a = %d, b = %d\n", a, b);

    return 0;
}
