#include <stdio.h>
#include <stdlib.h>

int main()
{
    int b[2][2] = {{1, 2}, {3, 4}};
    int (*pnb) [2] = b;  // b 的类型是 int(*)[2]

    *pnb[1] = 30;

    printf("b[0][0] = %d\n", b[0][0]);
    printf("b[0][1] = %d\n", b[0][1]);
    printf("b[1][0] = %d\n", b[1][0]);
    printf("b[1][1] = %d\n", b[1][1]);

    return 0;
}
