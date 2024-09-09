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

    printf("x = %d, y = %d\n", x, y);               // x = 1, y = 2

    SWAP(x, y);                                     // {int t = x; x = y; y = t;}

    printf("x = %d, y = %d\n", x, y);               // x = 2, y = 1

    printf("x + y = %d\n", ADD(x, y));              // x + y = 3

    printf("MIN(%d, %d) = %d\n", x, y, MIN(x, y));  // printf("MIN(%d, %d) = %d\n", x, y, (x < y ? x : y)); 
                                                    // MIN(2, 1) = 1

    return 0;
}
