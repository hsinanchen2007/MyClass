#include <stdio.h>

int main()
{
    int a = 1;
    int b = 2;
    int c = 0;

    c = a && b;

    printf("c = %d\n", c);

    c = !(a - b) || (c < b);

    printf("c = %d\n", c);

    c = 10000;

    // all non-zero are true (including values like -100, 100), zero is false
    // so !c becomes zero (false), but !!c is 1 (true)
    printf("c = %d\n", !c);
    printf("c = %d\n", !!c);

    c = !!c;

    printf("c = %d\n", c);

    return 0;
}
