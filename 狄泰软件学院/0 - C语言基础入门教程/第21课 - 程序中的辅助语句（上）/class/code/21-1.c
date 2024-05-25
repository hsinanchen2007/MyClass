#include <stdio.h>

int main()
{
    int a = 0;
    int b = 10;

    a = b = b + 1; // a=>11  b=>11

    printf("a = %d, b = %d\n", a, b);

    a += 1;
    a -= 2;
    a *= 3;
    a /= 4;

    // a => 7

    printf("a = %d\n", a);

    /*
        复合赋值与连续赋值相结合
    */
    a += b -= 1;

    printf("a = %d, b = %d\n", a, b);

    return 0;
}
