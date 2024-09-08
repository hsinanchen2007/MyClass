#include <stdio.h>

int main()
{
    int a = 0;
    int c = 1;

    a = -c++;  // c -> 2

    printf("a = %d\n", a);      // a = -1

    a = +(++c); // +(++c); c -> 3

    printf("a = %d\n", a);      // a = 3

    a = -c--;  // c -> 2

    printf("a = %d\n", a);      // a = -3

    printf("c = %d\n", c);      // c = 2

    return 0;
}
