#include <stdio.h>

#define ADD(a, b) a + b

#define SWAP(a, b)  {int t = a; a = b; b = t;}

#define MIN(a, b) (a < b ? a : b)

void swap(int a, int b)
{
    int t = 0;

    // printf("a = %d, b = %d\n", a, b);

    t = a;
    a = b;
    b = t;

    // printf("a = %d, b = %d\n", a, b);

}

int main()
{
    int x = 1;
    int y = 2;

    printf("x = %d, y = %d\n", x, y);

    SWAP(x, y);   // {int t = x; x = y; y = t;}

    printf("x = %d, y = %d\n", x, y);

    printf("x + y = %d\n", ADD(x, y));

    printf("MIN(%d, %d) = %d\n", x, y, MIN(x, y));  // printf("MIN(%d, %d) = %d\n", x, y, (x < y ? x : y));

    return 0;
}
