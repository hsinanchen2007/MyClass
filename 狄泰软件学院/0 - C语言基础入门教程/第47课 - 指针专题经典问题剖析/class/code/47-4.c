#include <stdio.h>
#include <stdlib.h>

int main()
{
    int b[2][2] = {{1, 2}, {3, 4}};
    int (*pnb) [2] = b;  // b �������� int(*)[2]

    *pnb[1] = 30;

    printf("b[0][0] = %d\n", b[0][0]);  // b[0][0] = 1
    printf("b[0][1] = %d\n", b[0][1]);  // b[0][1] = 2
    printf("b[1][0] = %d\n", b[1][0]);  // b[1][0] = 30
    printf("b[1][1] = %d\n", b[1][1]);  // b[1][1] = 4

    return 0;
}
