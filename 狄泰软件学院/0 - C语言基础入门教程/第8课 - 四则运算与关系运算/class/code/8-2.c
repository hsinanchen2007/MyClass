#include <stdio.h>

int main()
{
    int a = 1;
    int b = 2;
    int c = 3;

    c = a != b;
    c = a - b >= a + b;
    printf("c = %d\n", c);

    // c now is 0, not 3 anymore
    c = (a < b) + (c < b);
    printf("c = %d\n", c);

    return 0;
}
