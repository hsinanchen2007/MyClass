#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[] = {1, 2, 3, 4};
    int* pa = a;

    int b[2][2] = {{1, 2}, {3, 4}};
    // int** pb = b;  // b �����;��Բ��� int**

    int (*pnb) [2] = b;  // b �������� int(*)[2]

    printf("a = %p, pa = %p\n", a, pa);     // a = 00CFFCD0, pa = 00CFFCD0
    // printf("b = %p, pb = %p\n", b, pb);
    printf("b = %p, pnb = %p\n", b, pnb);   // b = 00CFFCC0, pnb = 00CFFCC0

    return 0;
}
