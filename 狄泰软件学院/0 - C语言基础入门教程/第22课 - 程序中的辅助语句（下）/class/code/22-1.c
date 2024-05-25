#include <stdio.h>

int main()
{
    int a = 0;
    int c = 1;

    a = -c++;  // c -> 2

    printf("a = %d\n", a);

    a = +++c; // +(++c); c -> 3

    printf("a = %d\n", a);

    a = -c--;  // c -> 2

    printf("a = %d\n", a);

    printf("c = %d\n", c);

    return 0;
}
