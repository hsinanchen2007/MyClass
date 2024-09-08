#include <stdio.h>

int main()
{
    int a = 0;
    int b = 10;
    int c = 0;

    a = (b < 10) ? 1 : 2;

    printf("a = %d\n", a);      // a = 2

    (a < 5) ? (a = 5) : (a = 0);

    printf("a = %d\n", a);      // a = 5

    /*
    ((a == 5) ? a : b) = 10; // ERROR
    */

    a = b = c = 0;

    c = (a = 2, b = 3, a + b);

    printf("a = %d\n", a);      // a = 2
    printf("b = %d\n", b);      // b = 3
    printf("c = %d\n", c);      // c = 5

    c -= a;  // c = c - a;

    printf("c = %d\n", c);      // c = 3

    return 0;
}
