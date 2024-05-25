#include <stdio.h>

int main()
{
    int a = 0;
    int b = 10;
    int c = 0;

    a = (b < 10) ? 1 : 2;

    printf("a = %d\n", a);

    (a < 5) ? (a = 5) : (a = 0);

    printf("a = %d\n", a);

    /*
    ((a == 5) ? a : b) = 10; // ERROR
    */

    a = b = c = 0;

    c = (a = 2, b = 3, a + b);

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);

    c -= a;  // c = c - a;

    printf("c = %d\n", c);

    return 0;
}
